#pragma once
#ifndef BROWSERS_H_INCLUDED
#define BROWSERS_H_INCLUDED

#define BROWSER_TYPE_LEN 13
#define MAX_LINE_BROWSERS 128
#define MAX_CUSTOM_BROWSERS 256

/* Each Browser contains the number of hits and the Browser's type */
typedef struct GBrowser_ {
  char browser_type[BROWSER_TYPE_LEN];
  int hits;
} GBrowser;

char* verify_browser(char* str, char* browser_type);
int is_crawler(const char* agent);
void free_browsers_hash(void);
void parse_browsers_file(void);

#endif
