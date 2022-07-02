#pragma once
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include "commons.h"
#include "parser.h"

#define SORT_MAX_OPTS 11

/* See GEnum for mapping */
#define SORT_FIELD_LEN 11 + 1  /* longest metric name */
#define SORT_MODULE_LEN 15 + 1 /* longest module name */
#define SORT_ORDER_LEN 4 + 1   /* length of ASC or DESC */

/* Enumerated sorting metrics */
typedef enum GSortField_ {
  SORT_BY_HITS,
  SORT_BY_VISITORS,
  SORT_BY_DATA,
  SORT_BY_BW,
  SORT_BY_AVGTS,
  SORT_BY_CUMTS,
  SORT_BY_MAXTS,
  SORT_BY_PROT,
  SORT_BY_MTHD,
} GSortField;

/* Enumerated sorting order */
typedef enum GSortOrder_ { SORT_ASC, SORT_DESC } GSortOrder;

/* Sorting of each panel, metric and order */
typedef struct GSort_ {
  GModule module;
  GSortField field;
  GSortOrder sort;
} GSort;

extern GSort module_sort[TOTAL_MODULES];
extern const int sort_choices[][SORT_MAX_OPTS];
;

GRawData* sort_raw_num_data(GRawData* raw_data, int ht_size);
GRawData* sort_raw_str_data(GRawData* raw_data, int ht_size);
const char* get_sort_field_key(GSortField field);
const char* get_sort_field_str(GSortField field);
const char* get_sort_order_str(GSortOrder order);
int can_sort_module(GModule module, int field);
int get_sort_field_enum(const char* str);
int get_sort_order_enum(const char* str);
int strcmp_asc(const void* a, const void* b);
int cmp_ui32_asc(const void* a, const void* b);
int cmp_ui32_desc(const void* a, const void* b);
void parse_initial_sort(void);
void set_initial_sort(const char* smod, const char* sfield, const char* ssort);
void sort_holder_items(GHolderItem* items, int size, GSort sort);

#endif
