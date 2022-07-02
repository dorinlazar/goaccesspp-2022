#pragma once
#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED

#define CYN "\x1B[36m"
#define RESET "\x1B[0m"
#define HTML_REFRESH 1 /* in seconds */

void add_dash_filename(void);
void cmd_help(void) __attribute__((noreturn));
void read_option_args(int argc, char** argv);
void verify_global_config(int argc, char** argv);

#endif
