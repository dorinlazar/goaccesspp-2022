/**
 * error.c -- error handling
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

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <execinfo.h>
#include <inttypes.h>
#include <sys/types.h>
#include <unistd.h>

#include "error.h"
#include "labels.h"
#include "parser.h"
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

static Logs* log_data;
static struct sigaction old_sigsegv_handler;

/* Set current overall parsed log data. */
void set_signal_data(void* p) { log_data = (Logs*)p; }

/* Set up sigsegv handler. */
void setup_sigsegv_handler(void) {
  struct sigaction act;

  sigemptyset(&act.sa_mask);
  act.sa_flags = (int)SA_RESETHAND;
  act.sa_handler = sigsegv_handler;

  sigaction(SIGSEGV, &act, &old_sigsegv_handler);
}

static void dump_struct_data(FILE* fp, GLog* glog, int pid) {
  fprintf(fp, "==%d== FILE: %s\n", pid, glog->filename);
  fprintf(fp, "==%d== Line number: %" PRIu64 "\n", pid, glog->processed);
  fprintf(fp, "==%d== Invalid data: %" PRIu64 "\n", pid, glog->invalid);
  fprintf(fp, "==%d== Piping: %d\n", pid, glog->piping);
  fprintf(fp, "==%d==\n", pid);
}

/* Dump to the standard output the values of the overall parsed log
 * data. */
static void dump_struct(FILE* fp) {
  int pid = getpid(), i;

  if (!log_data)
    return;

  fprintf(fp, "==%d== VALUES AT CRASH POINT\n", pid);
  fprintf(fp, "==%d==\n", pid);

  for (i = 0; i < log_data->size; ++i)
    dump_struct_data(fp, &log_data->glog[i], pid);
}

/* Custom SIGSEGV handler. */
void sigsegv_handler(int sig) {
  FILE* fp = stderr;
  int pid = getpid();

  char** messages;
  size_t size, i;
  void* trace_stack[TRACE_SIZE];

  (void)endwin();
  fprintf(fp, "\n");
  fprintf(fp, "==%d== GoAccess %s crashed by Sig %d\n", pid, GO_VERSION, sig);
  fprintf(fp, "==%d==\n", pid);

  dump_struct(fp);

  size = backtrace(trace_stack, TRACE_SIZE);
  messages = backtrace_symbols(trace_stack, size);

  fprintf(fp, "==%d== STACK TRACE:\n", pid);
  fprintf(fp, "==%d==\n", pid);

  for (i = 0; i < size; i++)
    fprintf(fp, "==%d== %zu %s\n", pid, i, messages[i]);

  fprintf(fp, "==%d==\n", pid);
  fprintf(fp, "==%d== %s:\n", pid, ERR_PLEASE_REPORT);
  fprintf(fp, "==%d== https://github.com/allinurl/goaccess/issues\n\n", pid);
  fflush(fp);

  /* Call old sigsegv handler; may be default exit or third party one (e.g. ASAN) */
  sigaction(SIGSEGV, &old_sigsegv_handler, NULL);
}
