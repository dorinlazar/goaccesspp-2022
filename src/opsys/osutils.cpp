#include "osutils.hpp"

#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <cstring>
#include <libintl.h>
#include <signal.h>

#include "error.hpp"

namespace goapp::opsys {

void SwitchToUser(const std::string& username) {
  struct passwd* pw;

  errno = 0;
  if ((pw = getpwnam(username.c_str())) == NULL) {
    if (errno == 0) {
      FATAL("No such user {}", username);
    }
    FATAL("Unable to retrieve user {}: {}", username, ::strerror(errno));
  }

  if (setgroups(1, &pw->pw_gid) == -1) {
    FATAL("setgroups: {}", ::strerror(errno));
  }
  if (setgid(pw->pw_gid) == -1) {
    FATAL("setgid: {}", ::strerror(errno));
  }
  if (setuid(pw->pw_uid) == -1) {
    FATAL("setuid: {}", ::strerror(errno));
  }
}

/* Set locale */
void UpdateLocale(void) {
  char* loc_ctype;

  setlocale(LC_ALL, "");
  bindtextdomain("goaccesspp", "/usr/share/locale");
  textdomain("goaccesspp");

  loc_ctype = getenv("LC_CTYPE");
  if (loc_ctype != NULL)
    setlocale(LC_CTYPE, loc_ctype);
  else if ((loc_ctype = getenv("LC_ALL")))
    setlocale(LC_CTYPE, loc_ctype);
  else
    setlocale(LC_CTYPE, "");
}

static sigset_t oldset;

void BlockThreadSignals() {
  /* Avoid threads catching SIGINT/SIGPIPE/SIGTERM and handle them in
   * main thread */
  sigset_t sigset;
  sigemptyset(&sigset);
  sigaddset(&sigset, SIGINT);
  sigaddset(&sigset, SIGPIPE);
  sigaddset(&sigset, SIGTERM);
  pthread_sigmask(SIG_BLOCK, &sigset, &oldset);
}

void SetupThreadSignals(void (*handle_signal_action)(int)) {
  struct sigaction act;

  act.sa_handler = handle_signal_action;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;

  sigaction(SIGINT, &act, NULL);
  sigaction(SIGTERM, &act, NULL);
  signal(SIGPIPE, SIG_IGN);

  /* Restore old signal mask for the main thread */
  pthread_sigmask(SIG_SETMASK, &oldset, NULL);
}

} // namespace goapp::opsys
