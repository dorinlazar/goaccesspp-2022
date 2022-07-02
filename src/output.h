#pragma once
#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#define MAX_PLOTS 5 /* number of metrics we can plot */

#include "commons.h"
#include "parser.h"

/* Enumerated chart types */
typedef enum GChartType_ {
  CHART_NONE,
  CHART_VBAR,
  CHART_AREASPLINE,
} GChartType;

/* Chart axis structure */
typedef struct GChartDef_ {
  const char* key;
  const char* value;
} GChartDef;

/* Chart axis structure */
typedef struct GChart_ {
  const char* key;
  GChartDef* def;
} GChart;

/* Chart behavior */
typedef struct GHTMLPlot_ {
  GChartType chart_type;
  void (*plot)(FILE* fp, struct GHTMLPlot_ plot, int sp);
  int8_t chart_reverse;
  int8_t redraw_expand;
  char* chart_key;
  char* chart_lbl;
} GHTMLPlot;

/* Controls HTML panel output. */
typedef struct GHTML_ {
  GModule module;
  int8_t table;
  void (*metrics)(FILE* fp, const struct GHTML_* def, int sp);
  GHTMLPlot chart[MAX_PLOTS];
} GHTML;

/* Metric definition . */
typedef struct GDefMetric_ {
  const char* cname = nullptr;    /* metric class name */
  const char* cwidth = nullptr;   /* metric column width */
  const char* datakey = nullptr;  /* metric JSON data key */
  const char* datatype = nullptr; /* metric data value type */
  const char* lbl = nullptr;      /* metric label (column name) */
  const char* metakey = nullptr;  /* metric JSON meta key */
  const char* metatype = nullptr; /* metric meta value type */
  const char* metalbl = nullptr;  /* metric meta value label */
} GDefMetric;

void output_html(GHolder* holder, const char* filename);

#endif
