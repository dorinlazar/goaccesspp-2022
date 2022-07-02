#pragma once
#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#define COLOR_STR_LEN 9

/* Color Items/Fields */
typedef enum CSTM_COLORS {
  COLOR_NORMAL,
  COLOR_MTRC_HITS,
  COLOR_MTRC_VISITORS,
  COLOR_MTRC_DATA,
  COLOR_MTRC_BW,
  COLOR_MTRC_AVGTS,
  COLOR_MTRC_CUMTS,
  COLOR_MTRC_MAXTS,
  COLOR_MTRC_PROT,
  COLOR_MTRC_MTHD,
  COLOR_MTRC_HITS_PERC,
  COLOR_MTRC_HITS_PERC_MAX,
  COLOR_MTRC_VISITORS_PERC,
  COLOR_MTRC_VISITORS_PERC_MAX,
  COLOR_PANEL_COLS,
  COLOR_BARS,
  COLOR_ERROR,
  COLOR_SELECTED,
  COLOR_PANEL_ACTIVE,
  COLOR_PANEL_HEADER,
  COLOR_PANEL_DESC,
  COLOR_OVERALL_LBLS,
  COLOR_OVERALL_VALS,
  COLOR_OVERALL_PATH,
  COLOR_ACTIVE_LABEL,
  COLOR_BG,
  COLOR_DEFAULT,
  COLOR_PROGRESS,
} GColorItem;

/* Default Color Schemes */
typedef enum SCHEMES {
  NO_COLOR,
  MONOCHROME,
  STD_GREEN,
  MONOKAI,
} GShemes;

#include "commons.h"

/* Each color properties */
typedef struct GColorPair_ {
  short idx; /* color pair index identifier */
  short fg;  /* foreground color */
  short bg;  /* background color */
} GColorPair;

/* Color */
typedef struct GColors_ {
  GColorItem item;  /* screen item */
  GColorPair* pair; /* color pair */
  int attr;         /* color attributes, e.g., bold */
  short module;     /* panel */
} GColors;

GColors* color_default(void);
GColors* color_error(void);
GColors* color_overall_lbls(void);
GColors* color_overall_path(void);
GColors* color_overall_vals(void);
GColors* color_panel_active(void);
GColors* color_panel_desc(void);
GColors* color_panel_header(void);
GColors* color_progress(void);
GColors* color_selected(void);
GColors* get_color_by_item_module(GColorItem item, GModule module);
GColors* get_color(GColorItem item);
GColors* get_color_normal(void);
void free_color_lists(void);
void set_colors(int force);
void set_normal_color(void);

#endif // for #ifndef COLOR_H
