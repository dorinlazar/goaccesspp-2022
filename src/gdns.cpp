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

DNSResolver::DNSResolver() : m_thread(&DNSResolver::DnsResolveWorker, this) {}
DNSResolver::~DNSResolver() {}

std::optional<std::string> DNSResolver::GetCachedHost(const std::string& ip) {
  std::unique_lock<std::mutex> lock(m_mutex);
  auto cache_it = m_cache.find(ip);
  if (cache_it != m_cache.end()) {
    return cache_it->second;
  }
  auto it = std::find(m_queue.begin(), m_queue.end(), ip);
  if (it == m_queue.end()) {
    m_queue.push_back(ip);
    m_cond.notify_one();
  }

  return std::nullopt;
}

std::optional<std::string> DNSResolver::ReverseIp(const std::string& ip) {
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

void DNSResolver::ResolveDns(const std::string& address) {
  std::unique_lock<std::mutex> lock(m_mutex);
  auto it = std::find(m_queue.begin(), m_queue.end(), address);
  if (it == m_queue.end()) {
    m_queue.push_back(address);
    m_cond.notify_one();
  }
}

void DNSResolver::DnsResolveWorker(std::stop_token stoken) {
  while (!stoken.stop_requested()) {
    std::string ip;
    {
      std::unique_lock<std::mutex> lock(m_mutex);
      if (!m_cond.wait(lock, stoken, [this]() { return !m_queue.empty(); })) {
        break;
      }
      ip = m_queue.front();
      m_queue.pop_front();
    }
    auto host = ReverseIp(ip);
    std::unique_lock<std::mutex> lock(m_mutex);
    m_cache.insert_or_assign(ip, host.value_or("[NONAME]"));
  }
}

std::unique_ptr<DNSResolver> g_dns_resolver;