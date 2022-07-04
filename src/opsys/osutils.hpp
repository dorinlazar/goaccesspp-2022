#pragma once

#include <string>

namespace goapp::opsys {

void SwitchToUser(const std::string& username);
void UpdateLocale();
void BlockThreadSignals();
void SetupThreadSignals(void (*handle_signal_action)(int));

} // namespace goapp::opsys
