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
#include <fmt/format.h>
#include <memory>

class Log {
  struct LogWriter {
    const int DEBUG_TEST = 0;
    std::unique_ptr<std::ostream> m_access;
    std::unique_ptr<std::ostream> m_debug;
    std::unique_ptr<std::ostream> m_invalids;
    std::unique_ptr<std::ostream> m_unknowns;

    template <typename... Args>
    inline void Access(const char* fmtarg, Args&&... args) {
      if (m_access) {
        Perform(*m_access, fmtarg, args...);
      }
    }
    template <typename... Args>
    inline void Debug(const char* fmtarg, Args&&... args) {
      if (m_debug) {
        Perform(*m_debug, fmtarg, args...);
      }
    }
    template <typename... Args>
    inline void Invalids(const char* fmtarg, Args&&... args) {
      if (m_invalids) {
        Perform(*m_invalids, fmtarg, args...);
      }
    }
    template <typename... Args>
    inline void Unknowns(const char* fmtarg, Args&&... args) {
      if (m_unknowns) {
        Perform(*m_unknowns, fmtarg, args...);
      }
    }
    template <typename... Args>
    inline void Trace(const char* fmtarg, Args&&... args) {
      if (DEBUG_TEST) {
        Perform(std::cerr, fmtarg, args...);
      }
    }

  private:
    template <typename... Args>
    static inline void Perform(std::ostream& os, const char* fmtarg, Args&&... args) {
      os << fmt::vformat(fmtarg, fmt::make_format_args(args...)) << "\n";
    }
  };
  static LogWriter m_log_writer;

public:
  template <typename... Args>
  static inline void Access(const char* fmtarg, Args&&... args) {
    m_log_writer.Access(fmtarg, args...);
  }
  template <typename... Args>
  static inline void Debug(const char* fmtarg, Args&&... args) {
    m_log_writer.Debug(fmtarg, args...);
  }
  template <typename... Args>
  static inline void Invalids(const char* fmtarg, Args&&... args) {
    m_log_writer.Invalids(fmtarg, args...);
  }
  template <typename... Args>
  static inline void Unknowns(const char* fmtarg, Args&&... args) {
    m_log_writer.Unknowns(fmtarg, args...);
  }
  template <typename... Args>
  static inline void Trace(const char* fmtarg, Args&&... args) {
    m_log_writer.Trace(fmtarg, args...);
  }

  static void OpenLogAccessFile(const std::string& filename);
  static void OpenLogDebugFile(const std::string& filename);
  static void OpenLogInvalidsFile(const std::string& filename);
  static void OpenLogUnknownsFile(const std::string& filename);
  static void CloseLogFiles();
};

template <typename... Args>
struct FATAL {
  [[noreturn]] FATAL(const char* fmtarg, Args&&... args,
                     const std::source_location& loc = std::source_location::current()) {
    (void)endwin();
    std::cerr << fmt::format("\nGoAccess - version {} - {}T{}\n", GO_VERSION, __DATE__, __TIME__);
    std::cerr << fmt::format("Config file: {}\n", conf.iconfigfile ? conf.iconfigfile : NO_CONFIG_FILE);
    std::cerr << "Fatal error has occurred\n";
    std::cerr << fmt::format("Error occurred at : {} : {} = > {}\n\n", loc.file_name(), loc.line(),
                             loc.function_name());
    std::cerr << fmt::vformat(fmtarg, fmt::make_format_args(args...));
    std::cout.flush();
    std::cerr.flush();
    std::abort();
  }
};

// https://en.cppreference.com/w/cpp/language/class_template_argument_deduction#User-defined_deduction_guides
template <typename... Args>
FATAL(const char*, Args&&...) -> FATAL<Args...>;

void set_signal_data(void* p);
void setup_sigsegv_handler(void);
void sigsegv_handler(int sig);

#endif
