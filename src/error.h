/**
 *    ______      ___
 *   / ____/___  /   | _____________  __________
 *  / / __/ __ \/ /| |/ ___/ ___/ _ \/ ___/ ___/
 * / /_/ / /_/ / ___ / /__/ /__/  __(__  |__  )
 * \____/\____/_/  |_\___/\___/\___/____/____/
 *
 * The MIT License (MIT)
 * Copyright (c) 2009-2022 Gerardo Orellana <hello @ goaccess.io>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

#ifndef COMMONS
#include "commons.h"
#endif

#include <ncurses.h>

#include "settings.h"

#define TRACE_SIZE 128

#include <iostream>
#include <source_location>

namespace kl {
inline void _perform_log(std::ostream& os) { os << "\n"; }

template <typename T, typename... Other>
inline void _perform_log(std::ostream& os, const T& val, const Other&... args) {
  os << val;
  _perform_log(os, args...);
}

template <typename... Args>
inline void log(const Args&... args) {
  _perform_log(std::cout, args...);
}

template <typename... Args>
inline void err(const Args&... args) {
  _perform_log(std::cerr, args...);
}

} // namespace kl

template <typename... Args>
struct FATAL {
  [[noreturn]] FATAL(const Args&... args, const std::source_location& loc = std::source_location::current()) {
    (void)endwin();
    kl::err("\nGoAccess - version ", GO_VERSION, " - " __DATE__, " ", __TIME__);
    kl::err("Config file: ", conf.iconfigfile ?: NO_CONFIG_FILE);
    kl::err("Fatal error has occurred");
    kl::err("Error occurred at: ", loc.function_name(), "@", loc.file_name(), ":", loc.line());
    kl::err("--------------------------------------------------------------------------");
    kl::err(args...);
    std::cout.flush();
    std::cerr.flush();
    std::abort();
  }
};

// https://en.cppreference.com/w/cpp/language/class_template_argument_deduction#User-defined_deduction_guides
template <typename... Args>
FATAL(Args&&...) -> FATAL<Args...>;

// template <typename... Args>
// inline void LOG(const Args&... args) {
//   kl::log(args...);
// }

/* access requests log */
#define ACCESS_LOG(x, ...)                                                                                             \
  do {                                                                                                                 \
    access_fprintf x;                                                                                                  \
  } while (0)
/* debug log */
#define LOG_DEBUG(x, ...)                                                                                              \
  do {                                                                                                                 \
    dbg_fprintf x;                                                                                                     \
  } while (0)
/* invalid requests log */
#define LOG_INVALID(x, ...)                                                                                            \
  do {                                                                                                                 \
    invalid_fprintf x;                                                                                                 \
  } while (0)
/* unknown browser log */
#define LOG_UNKNOWNS(x, ...)                                                                                           \
  do {                                                                                                                 \
    unknowns_fprintf x;                                                                                                \
  } while (0)

#define DEBUG_TEST 0
/* log debug wrapper */
#define LOG(x)                                                                                                         \
  do {                                                                                                                 \
    if (DEBUG_TEST)                                                                                                    \
      dbg_printf x;                                                                                                    \
  } while (0)

int access_log_open(const char* path);
void access_fprintf(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
void access_log_close(void);
void dbg_fprintf(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
void dbg_log_close(void);
void dbg_log_open(const char* file);
void dbg_printf(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
void invalid_fprintf(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
void unknowns_fprintf(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
void invalid_log_close(void);
void invalid_log_open(const char* path);
void set_signal_data(void* p);
void setup_sigsegv_handler(void);
void sigsegv_handler(int sig);
void unknowns_log_close(void);
void unknowns_log_open(const char* path);

#endif
