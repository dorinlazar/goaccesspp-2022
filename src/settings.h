#pragma once
#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include <stdint.h>
#include <vector>
#include <string>
#include <unordered_set>
#include "commons.h"

#define MAX_LINE_CONF 4096
#define MAX_EXTENSIONS 128
#define MAX_IGNORE_IPS 1024 + 128
#define MAX_IGNORE_REF 64
#define MAX_CUSTOM_COLORS 64
#define MAX_IGNORE_STATUS 64
#define MAX_OUTFORMATS 3
#define MAX_FILENAMES 3072
#define MIN_DATENUM_FMT_LEN 7
#define NO_CONFIG_FILE "No config file used"

typedef enum LOGTYPE {
  COMBINED,
  VCOMBINED,
  COMMON,
  VCOMMON,
  W3C,
  CLOUDFRONT,
  CLOUDSTORAGE,
  AWSELB,
  SQUID,
  AWSS3,
  CADDY,
  AWSALB,
} GLogType;

/* predefined log times */
typedef struct GPreConfTime_ {
  const char* fmt24;
  const char* usec;
  const char* sec;
} GPreConfTime;

/* predefined log dates */
typedef struct GPreConfDate_ {
  const char* apache;
  const char* w3c;
  const char* usec;
  const char* sec;
} GPreConfDate;

/* predefined log formats */
typedef struct GPreConfLog_ {
  const char* combined;
  const char* vcombined;
  const char* common;
  const char* vcommon;
  const char* w3c;
  const char* cloudfront;
  const char* cloudstorage;
  const char* awselb;
  const char* squid;
  const char* awss3;
  const char* caddy;
  const char* awsalb;
} GPreConfLog;

/* All configuration properties */
struct GConf {
  /* Array options */
  std::vector<std::string> colors;
  std::vector<std::string> enable_panels;        /* array of panels to enable */
  std::vector<std::string> filenames;            /* log files */
  std::vector<std::string> hide_referers;        /* hide referrers from report */
  std::vector<std::string> ignore_ips;           /* array of ips to ignore */
  std::unordered_set<std::string> ignore_panels; /* array of panels to ignore */
  std::vector<std::string> ignore_referers;      /* referrers to ignore */
  std::unordered_set<std::string> ignore_status; /* status to ignore */
  std::vector<std::string> output_formats;       /* output format, e.g. , HTML */
  std::vector<std::string> sort_panels;          /* sorting options for each panel */
  std::vector<std::string> static_files;         /* static extensions */

  void PushUniqueToArray(const std::string& value, std::vector<std::string>&);
  void PushUniqueToArray(const std::string& value, std::unordered_set<std::string>&);

  /* Log/date/time formats */
  const char* tz_name;             /* Canonical TZ name, e.g., America/Chicago */
  char* date_time_format;          /* date & time format */
  char* date_format;               /* date format */
  char* date_num_format;           /* numeric date format %Y%m%d */
  char* time_format;               /* time format as given by the user */
  char* spec_date_time_format;     /* date format w/ specificity */
  char* spec_date_time_num_format; /* numeric date format w/ specificity */
  char* log_format;                /* log format */
  char* iconfigfile;               /* config file path */
  char*** user_browsers_hash;      /* custom list of browsers */

  const char* debug_log;            /* debug log path */
  const char* geoip_database;       /* geoip db path */
  const char* html_custom_css;      /* custom CSS */
  const char* html_custom_js;       /* custom JS */
  const char* html_prefs;           /* default HTML JSON preferences */
  const char* html_report_title;    /* report title */
  const char* invalid_requests_log; /* invalid lines log path */
  const char* unknowns_log;         /* unknown browsers/OSs log path */
  const char* pidfile;              /* daemonize pid file path */
  const char* browsers_file;        /* browser's file path */
  const char* db_path;              /* db path to files */

  /* HTML real-time */
  const char* addr;          /* IP address to bind to */
  const char* fifo_in;       /* path FIFO in (reader) */
  const char* fifo_out;      /* path FIFO out (writer) */
  const char* origin;        /* WebSocket origin */
  const char* port;          /* port to use */
  const char* sslcert;       /* TLS/SSL path to certificate */
  const char* sslkey;        /* TLS/SSL path to private key */
  const char* ws_url;        /* WebSocket URL */
  const char* ping_interval; /* WebSocket ping interval in seconds */
  const char* unix_socket;   /* unix socket to bind to */

  /* User flags */
  int all_static_files;           /* parse all static files */
  int anonymize_ip;               /* anonymize ip addresses */
  int anonymize_level;            /* anonymization level */
  int append_method = 1;          /* append method to the req key */
  int append_protocol = 1;        /* append protocol to the req key */
  int client_err_to_unique_count; /* count 400s as visitors */
  int code444_as_404;             /* 444 as 404s? */
  int color_scheme;               /* color scheme */
  int crawlers_only;              /* crawlers only */
  int daemonize;                  /* run program as a Unix daemon */
  const char* username;           /* user to run program as */
  int double_decode;              /* need to double decode */
  int enable_html_resolver;       /* html/json/csv resolver */
  int geo_db;                     /* legacy geoip db */
  int hl_header = 1;              /* highlight header on term */
  int ignore_crawlers;            /* ignore crawlers */
  int ignore_qstr;                /* ignore query string */
  int ignore_statics;             /* ignore static files */
  int json_pretty_print;          /* pretty print JSON data */
  int list_agents;                /* show list of agents per host */
  int load_conf_dlg;              /* load curses config dialog */
  bool load_global_config = true; /* use global config file */
  int max_items;                  /* max number of items to output */
  bool mouse_support;             /* add curses mouse support */
  int no_color;                   /* no terminal colors */
  int no_strict_status;           /* don't enforce 100-599 status codes */
  int no_column_names;            /* don't show col names on termnal */
  int no_csv_summary;             /* don't show overall metrics */
  int no_html_last_updated;       /* don't show HTML last updated field */
  int no_ip_validation;           /* don't validate client IP addresses */
  int no_parsing_spinner;         /* disable parsing spinner */
  int no_progress;                /* disable progress metrics */
  int no_tab_scroll;              /* don't scroll dashboard on tab */
  int output_stdout;              /* outputting to stdout */
  int persist;                    /* ensure to persist data on exit */
  int process_and_exit;           /* parse and exit without outputting */
  int real_os;                    /* show real OSs */
  int real_time_html;             /* enable real-time HTML output */
  int restore;                    /* reload data from db-path */
  int skip_term_resolver;         /* no terminal resolver */
  int is_json_log_format;         /* is a json log format */
  uint32_t keep_last;             /* number of days to keep in storage */
  uint32_t num_tests = 10;        /* number of lines to test */
  uint64_t html_refresh;          /* refresh html report every X of seconds */
  uint64_t log_size;              /* log size override */

  /* Internal flags */
  int bandwidth;    /* is there bandwidth within the req line */
  int date_spec_hr; /* date specificity - hour */
  int has_geocity;
  int has_geocountry;
  int hour_spec_min;   /* hour specificity - min */
  int read_stdin;      /* read from stdin */
  int serve_usecs;     /* is there time served within req line */
  int stop_processing; /* stop all processing */
  int tailing_mode;    /* in tailing-mode? */

  /* Array indices */
  int browsers_hash_idx; /* browsers hash index */

  size_t static_file_max_len = 0;
};

char* get_selected_date_str(size_t idx);
char* get_selected_format_str(size_t idx);
char* get_selected_time_str(size_t idx);
const char* verify_formats(void);
int is_json_log_format(const char* fmt);
int parse_json_string(void* userdata, const char* str, int (*cb)(void*, char*, char*));
size_t get_selected_format_idx(void);
void set_date_format_str(const char* optarg);
void set_log_format_str(const char* optarg);
void set_spec_date_format(void);
void set_time_format_str(const char* optarg);

extern GConf conf;

char* get_config_file_path(void);
int parse_conf_file(int* argc, char*** argv);
void free_cmd_args(void);
void free_formats(void);
void set_default_static_files(void);

#endif
