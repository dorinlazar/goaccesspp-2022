#pragma once

#include <string_view>
#include <string>

namespace goapp::text {

std::string_view Trim(std::string_view txt);
std::string_view TrimRight(std::string_view txt);
std::string_view TrimLeft(std::string_view txt);

} // namespace goapp::text