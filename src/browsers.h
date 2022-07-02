#pragma once

#include <string>
#include <optional>

namespace goapp {
class Browsers {
public:
  static bool IsCrawler(const std::string& agent);
  static std::optional<std::string> GetBrowserType(const std::string& str);
  static std::optional<std::string> ParseUserAgent(const std::string& user_agent);
  static void LoadBrowsersFile(const std::string& browsers_file);
};
} // namespace goapp
