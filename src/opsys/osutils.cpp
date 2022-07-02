#include "osutils.hpp"

#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <cstring>

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

} // namespace goapp::opsys
