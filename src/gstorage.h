#pragma once
#ifndef GSTORAGE_H_INCLUDED
#define GSTORAGE_H_INCLUDED

#include "commons.h"
#include "parser.h"

/* Total number of storage metrics (GSMetric) */
#define GSMTRC_TOTAL 19
#define DB_PATH "/tmp"

/* Enumerated Storage Metrics */
typedef enum GSMetric_ {
  MTRC_KEYMAP,
  MTRC_ROOTMAP,
  MTRC_DATAMAP,
  MTRC_UNIQMAP,
  MTRC_ROOT,
  MTRC_HITS,
  MTRC_VISITORS,
  MTRC_BW,
  MTRC_CUMTS,
  MTRC_MAXTS,
  MTRC_METHODS,
  MTRC_PROTOCOLS,
  MTRC_AGENTS,
  MTRC_METADATA,
  MTRC_UNIQUE_KEYS,
  MTRC_AGENT_KEYS,
  MTRC_AGENT_VALS,
  MTRC_CNT_VALID,
  MTRC_CNT_BW,
} GSMetric;

#define GAMTRC_TOTAL 8
/* Enumerated App Metrics */
typedef enum GAMetric_ {
  MTRC_DATES,
  MTRC_SEQS,
  MTRC_CNT_OVERALL,
  MTRC_HOSTNAMES,
  MTRC_LAST_PARSE,
  MTRC_JSON_LOGFMT,
  MTRC_METH_PROTO,
  MTRC_DB_PROPS,
} GAMetric;

/* Each record contains a data value, i.e., Windows XP, and it may contain a
 * root value, i.e., Windows, and a unique key which is the combination of
 * date, IP and user agent */
typedef struct GKeyData_ {
  const void* data;
  uint32_t dhash;
  uint32_t data_nkey;
  uint32_t cdnkey; /* cache data nkey */

  uint32_t rhash;
  const void* root;
  const void* root_key;
  uint32_t root_nkey;
  uint32_t crnkey; /* cache root nkey */

  void* uniq_key;
  uint32_t uniq_nkey;

  uint32_t numdate;
} GKeyData;

typedef struct GParse_ {
  GModule module;
  int (*key_data)(GKeyData* kdata, GLogItem* logitem);

  /* data field */
  void (*datamap)(GModule module, GKeyData* kdata);
  void (*rootmap)(GModule module, GKeyData* kdata);
  void (*hits)(GModule module, GKeyData* kdata);
  void (*visitor)(GModule module, GKeyData* kdata);
  void (*bw)(GModule module, GKeyData* kdata, uint64_t size);
  void (*cumts)(GModule module, GKeyData* kdata, uint64_t ts);
  void (*maxts)(GModule module, GKeyData* kdata, uint64_t ts);
  void (*method)(GModule module, GKeyData* kdata, const char* data);
  void (*protocol)(GModule module, GKeyData* kdata, const char* data);
  void (*agent)(GModule module, GKeyData* kdata, uint32_t agent_nkey);
} GParse;

typedef struct httpmethods_ {
  const char* method;
  int len;
} httpmethods;

typedef struct httpprotocols_ {
  const char* protocol;
  int len;
} httpprotocols;

extern const httpmethods http_methods[];
extern const httpprotocols http_protocols[];
extern size_t http_methods_len;
extern size_t http_protocols_len;

char* get_mtr_str(GSMetric metric);
int excluded_ip(GLogItem* logitem);
uint32_t* i322ptr(uint32_t val);
uint64_t* uint642ptr(uint64_t val);
void count_process_and_invalid(GLog* glog, const char* line);
void count_process(GLog* glog);
void free_gmetrics(GMetrics* metric);
void insert_methods_protocols(void);
void process_log(GLogItem* logitem);
void set_data_metrics(GMetrics* ometrics, GMetrics** nmetrics, GPercTotals totals);
void set_module_totals(GPercTotals* totals);
void uncount_invalid(GLog* glog);
void uncount_processed(GLog* glog);
GMetrics* new_gmetrics(void);

#endif // for #ifndef GSTORAGE_H
