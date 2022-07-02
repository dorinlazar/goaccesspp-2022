#include "textutils.hpp"
#include <algorithm>

namespace goapp::text {

std::string_view Trim(std::string_view txt) { return TrimRight(TrimLeft(txt)); }

std::string_view TrimRight(std::string_view txt) {
  auto pos = txt.find_last_not_of(" \t\r\n");
  if (pos != std::string_view::npos) {
    txt.remove_suffix(txt.size() - pos);
    return txt;
  }
  return {};
}

std::string_view TrimLeft(std::string_view txt) {
  auto pos = txt.find_first_not_of(" \t\r\n");
  if (pos != std::string_view::npos) {
    txt.remove_prefix(pos);
    return txt;
  }
  return {};
}

} // namespace goapp::text
