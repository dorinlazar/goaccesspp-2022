#pragma once
#ifndef GDASHBOARD_H_INCLUDED
#define GDASHBOARD_H_INCLUDED

#include <stdint.h>

#include "ui/ui.h"

#define DASH_HEAD_POS 0   /* position of header line */
#define DASH_EMPTY_POS 1  /* empty line position */
#define DASH_COLS_POS 2   /* position of column names */
#define DASH_DASHES_POS 3 /* position of dashes under column names */
#define DASH_DATA_POS 4   /* data line position */

#define DASH_NON_DATA 5 /* number of rows without data stats */
#define DASH_COL_ROWS 2 /* number of rows for column values + dashed lines */

#define DASH_COLLAPSED 12 /* number of rows per panel (collapsed) */
#define DASH_EXPANDED 32  /* number of rows per panel (expanded) */

#define DASH_INIT_X 1 /* start position (x-axis) */

#define DASH_BW_LEN 11    /* max bandwidth string length, e.g., 151.69 MiB */
#define DASH_SRV_TM_LEN 9 /* max time served length, e.g., 483.00 us */
#define DASH_SPACE 1      /* space between columns (metrics) */

/* Common render data line fields */
typedef struct GDashRender_ {
  WINDOW* win;
  int y;
  int w;
  int idx;
  int sel;
} GDashRender;

/* Dashboard panel item */
typedef struct GDashData_ {
  GMetrics* metrics;
  short is_subitem;
} GDashData;

/* Dashboard panel meta data */
typedef struct GDashMeta_ {
  uint64_t max_hits;     /* maximum value on the hits column */
  uint64_t max_visitors; /* maximum value on the visitors column */

  /* determine the maximum metric's length of these metrics */
  /* for instance, 1022 is the max value for the hits column and its length = 4 */
  int hits_len;
  int hits_perc_len;
  int visitors_len;
  int visitors_perc_len;
  int bw_len;
  int avgts_len;
  int cumts_len;
  int maxts_len;
  int method_len;
  int protocol_len;
  int data_len;
} GDashMeta;

/* Dashboard panel */
typedef struct GDashModule_ {
  GDashData* data; /* data metrics */
  GModule module;  /* module */
  GDashMeta meta;  /* meta data */

  const char* head; /* panel header */
  const char* desc; /* panel description */

  int alloc_data; /* number of data items allocated. */
  /* e.g., MAX_CHOICES or holder size */
  int dash_size;   /* dashboard size */
  int holder_size; /* hash table size  */
  int ht_size;     /* hash table size  */
  int idx_data;    /* idx data */

  unsigned short pos_y; /* dashboard current Y position */
} GDashModule;

/* Dashboard */
typedef struct GDash_ {
  int total_alloc; /* number of allocated dashboard lines */
  GDashModule module[TOTAL_MODULES];
} GDash;

/* Function Prototypes */
GDashData* new_gdata(uint32_t size);
GDash* new_gdash(void);
int get_num_collapsed_data_rows(void);
int get_num_expanded_data_rows(void);
int perform_next_find(GHolder* h, GScroll* scroll);
int render_find_dialog(WINDOW* main_win, GScroll* scroll);
int set_module_from_mouse_event(GScroll* scroll, GDash* dash, int y);
uint32_t get_ht_size_by_module(GModule module);
void display_content(WINDOW* win, GDash* dash, GScroll* scroll);
void free_dashboard(GDash* dash);
void load_data_to_dash(GHolder* h, GDash* dash, GModule module, GScroll* scroll);
void reset_find(void);
void reset_scroll_offsets(GScroll* scroll);

#endif
