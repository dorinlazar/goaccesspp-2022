#pragma once
#ifndef GDNS_H_INCLUDED
#define GDNS_H_INCLUDED

#define H_SIZE 1025

typedef struct GDnsThread_ {
  pthread_cond_t not_empty; /* not empty queue condition */
  pthread_cond_t not_full;  /* not full queue condition */
  pthread_mutex_t mutex;
  pthread_t thread;
} GDnsThread;

extern GDnsThread gdns_thread;

#include <mutex>
#include <string>
#include <thread>
#include <deque>
#include <condition_variable>

class DNSResolver final {
public:
  DNSResolver();
  ~DNSResolver();

  std::string ReverseIp(const std::string& ip);
  void ResolveDns(const std::string& address);

private:
  void DnsResolveWorker();

private:
  std::condition_variable m_cond;
  std::mutex m_mutex;
  std::jthread m_thread;
  std::deque<std::string> m_queue;
};

char* reverse_ip(const char* str);
void dns_resolver(char* addr);
void gdns_free_queue(void);
void gdns_init(void);
void gdns_queue_free(void);
void gdns_thread_create(void);

#endif
