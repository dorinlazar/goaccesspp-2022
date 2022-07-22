#pragma once

#include <mutex>
#include <string>
#include <thread>
#include <deque>
#include <optional>
#include <condition_variable>
#include <unordered_map>

class DNSResolver final {
public:
  DNSResolver();
  ~DNSResolver();

  std::optional<std::string> ReverseIp(const std::string& ip);
  void ResolveDns(const std::string& address);
  std::optional<std::string> GetCachedHost(const std::string& ip);

private:
  void DnsResolveWorker(std::stop_token stoken);

private:
  std::condition_variable_any m_cond;
  std::mutex m_mutex;
  std::jthread m_thread;
  std::deque<std::string> m_queue;
  std::unordered_map<std::string, std::string> m_cache;
};

extern std::unique_ptr<DNSResolver> g_dns_resolver;
