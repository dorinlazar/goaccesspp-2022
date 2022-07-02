#pragma once
#ifndef JSON_H_INCLUDED
#define JSON_H_INCLUDED

#define TAB "\t\t\t\t\t\t\t\t\t\t\t"
#define NL "\n\n\n"

#include "parser.h"

typedef struct GJSON_ {
  char* buf;     /* pointer to buffer */
  size_t size;   /* size of malloc'd buffer */
  size_t offset; /* current write offset */
} GJSON;

char* get_json(GHolder* holder, int escape_html);

void output_json(GHolder* holder, const char* filename);
void set_json_nlines(int nl);

void fpskeyival(FILE* fp, const char* key, int val, int sp, int last);
void fpskeysval(FILE* fp, const char* key, const char* val, int sp, int last);
void fpskeyaval(FILE* fp, const char* key, const char* val, int sp, int last);

void fpclose_arr(FILE* fp, int sp, int last);
void fpclose_obj(FILE* fp, int iisp, int last);
void fpjson(FILE* fp, const char* fmt, ...) __attribute__((format(printf, 2, 3)));
void fpopen_arr_attr(FILE* fp, const char* attr, int sp);
void fpopen_obj_attr(FILE* fp, const char* attr, int sp);
void fpopen_obj(FILE* fp, int iisp);

#endif
