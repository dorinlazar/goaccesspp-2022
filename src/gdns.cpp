#define _MULTI_THREADED

#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

#include "gdns.h"

#include "util/error.hpp"
#include "gkhash.h"
#include "goaccess.h"
#include "util/util.h"
#include "util/xmalloc.h"

#include <deque>
#include <string>
#include <algorithm>

GDnsThread gdns_thread;
// replace with a rotating buffer.
static std::unique_ptr<std::deque<std::string>> gdns_queue;

/* Get the corresponding hostname given an IP address.
 *
 * On error, a string error message is returned.
 * On success, a malloc'd hostname is returned. */
static char* reverse_host(const struct sockaddr* a, socklen_t length) {
  char h[H_SIZE] = {0};
  int flags, st;

  flags = NI_NAMEREQD;
  st = getnameinfo(a, length, h, H_SIZE, NULL, 0, flags);
  if (!st) {
    /* BSD returns \0 while Linux . on solve lookups */
    if (*h == '\0')
      return alloc_string(".");
    return alloc_string(h);
  }
  return alloc_string(gai_strerror(st));
}

/* Determine if IPv4 or IPv6 and resolve.
 *
 * On error, NULL is returned.
 * On success, a malloc'd hostname is returned. */
char* reverse_ip(const char* str) {
  union {
    struct sockaddr addr;
    struct sockaddr_in6 addr6;
    struct sockaddr_in addr4;
  } a;

  if (str == NULL || *str == '\0')
    return NULL;
  memset(&a, 0, sizeof(a));
  if (1 == inet_pton(AF_INET, str, &a.addr4.sin_addr)) {
    a.addr4.sin_family = AF_INET;
    return reverse_host(&a.addr, sizeof(a.addr4));
  } else if (1 == inet_pton(AF_INET6, str, &a.addr6.sin6_addr)) {
    a.addr6.sin6_family = AF_INET6;
    return reverse_host(&a.addr, sizeof(a.addr6));
  }
  return NULL;
}

/* Producer - Resolve an IP address and add it to the queue. */
void dns_resolver(char* addr) {
  pthread_mutex_lock(&gdns_thread.mutex);
  auto it = std::find(gdns_queue->begin(), gdns_queue->end(), addr);
  if (it == gdns_queue->end()) {
    gdns_queue->push_back(addr);
    pthread_cond_broadcast(&gdns_thread.not_empty);
  }
  pthread_mutex_unlock(&gdns_thread.mutex);
}

/* Consumer - Once an IP has been resolved, add it to dwithe hostnames
 * hash structure. */
static void* dns_worker(void GO_UNUSED(*ptr_data)) {
  char* host = NULL;

  while (1) {
    pthread_mutex_lock(&gdns_thread.mutex);
    /* wait until an item has been added to the queue */
    while (gdns_queue->empty()) {
      pthread_cond_wait(&gdns_thread.not_empty, &gdns_thread.mutex);
    }

    auto ip = gdns_queue->front();
    gdns_queue->pop_front();

    pthread_mutex_unlock(&gdns_thread.mutex);
    host = reverse_ip(ip.c_str());
    pthread_mutex_lock(&gdns_thread.mutex);

    if (!active_gdns) {
      pthread_mutex_unlock(&gdns_thread.mutex);
      free(host);
      return nullptr;
    }

    /* insert the corresponding IP -> hostname map */
    if (host != NULL && active_gdns) {
      ht_insert_hostname(ip.c_str(), host);
      free(host);
    }

    pthread_cond_signal(&gdns_thread.not_full);
    pthread_mutex_unlock(&gdns_thread.mutex);
  }
  return nullptr;
}

/* Initialize queue and dns thread */
void gdns_init(void) {
  gdns_queue = std::make_unique<std::deque<std::string>>();

  if (pthread_cond_init(&(gdns_thread.not_empty), NULL))
    FATAL("Failed init thread condition");

  if (pthread_cond_init(&(gdns_thread.not_full), NULL))
    FATAL("Failed init thread condition");

  if (pthread_mutex_init(&(gdns_thread.mutex), NULL))
    FATAL("Failed init thread mutex");
}

/* Destroy (free) queue */
void gdns_free_queue(void) { gdns_queue.reset(); }

/* Create a DNS thread and make it active */
void gdns_thread_create(void) {
  int th;
  Log::Debug("Created gdns thread");
  active_gdns = 1;
  th = pthread_create(&(gdns_thread.thread), NULL, dns_worker, NULL);
  if (th)
    FATAL("Return code from pthread_create(): {}", th);
  pthread_detach(gdns_thread.thread);
}

DNSResolver::DNSResolver() {}
DNSResolver::~DNSResolver() {}

std::optional<std::string> DNSResolver::ReverseIp([[maybe_unused]] const std::string& ip) {
  if (ip.size() == 0)
    return std::nullopt;

  union {
    struct sockaddr sin;
    struct sockaddr_in sin4;
    struct sockaddr_in6 sin6;
  } sa;

  ::memset(&sa, 0, sizeof(sa));

  socklen_t length = 0;

  if (inet_pton(AF_INET, ip.c_str(), &sa.sin4.sin_addr) == 1) {
    sa.sin4.sin_family = AF_INET;
    length = sizeof(sa.sin4);
  } else if (inet_pton(AF_INET6, ip.c_str(), &sa.sin6.sin6_addr) == 1) {
    sa.sin6.sin6_family = AF_INET6;
    length = sizeof(sa.sin6);
  }

  if (length > 0) {
    std::array<char, 256> buffer; // As per RFC1035
    buffer[0] = '\0';
    buffer[buffer.size() - 1] = '\0';

    auto res = getnameinfo(&sa.sin, length, buffer.begin(), buffer.size() - 1, nullptr, 0, NI_NAMEREQD);
    if (res == 0) {
      return std::string(buffer.begin());
    }
  }

  return std::nullopt;
}

void DNSResolver::ResolveDns([[maybe_unused]] const std::string& address) {}

void DNSResolver::DnsResolveWorker() {}
