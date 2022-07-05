#pragma once
#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

#ifndef COMMONS
#include "commons.h"
#endif

#include "ui/textui.hpp"
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
    goapp::TextUiSystem::Close();
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

#endif
