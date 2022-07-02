#include "error.hpp"
#include <fstream>

Log::LogWriter Log::m_log_writer;

void Log::OpenLogAccessFile(const std::string& filename) {
  auto ptr = std::make_unique<std::ofstream>(filename, std::ios::out | std::ios::binary | std::ios::app);
  if (ptr->is_open()) {
    m_log_writer.m_access = std::move(ptr);
  } else {
    Trace("Unable to open access file [{}]: {} ", filename, ::strerror(errno));
  }
}

void Log::OpenLogDebugFile(const std::string& filename) {
  auto ptr = std::make_unique<std::ofstream>(filename, std::ios::out | std::ios::binary | std::ios::trunc);
  if (ptr->is_open()) {
    m_log_writer.m_debug = std::move(ptr);
  } else {
    Trace("Unable to open debug file [{}]: {} ", filename, ::strerror(errno));
  }
}

void Log::OpenLogInvalidsFile(const std::string& filename) {
  auto ptr = std::make_unique<std::ofstream>(filename, std::ios::out | std::ios::binary | std::ios::trunc);
  if (ptr->is_open()) {
    m_log_writer.m_invalids = std::move(ptr);
  } else {
    Trace("Unable to open invalids file [{}]: {} ", filename, ::strerror(errno));
  }
}

void Log::OpenLogUnknownsFile(const std::string& filename) {
  auto ptr = std::make_unique<std::ofstream>(filename, std::ios::out | std::ios::binary | std::ios::trunc);
  if (ptr->is_open()) {
    m_log_writer.m_unknowns = std::move(ptr);
  } else {
    Trace("Unable to open unknowns file [{}]: {} ", filename, ::strerror(errno));
  }
}

void Log::CloseLogFiles() {
  m_log_writer.m_access.reset();
  m_log_writer.m_debug.reset();
  m_log_writer.m_invalids.reset();
  m_log_writer.m_unknowns.reset();
}
