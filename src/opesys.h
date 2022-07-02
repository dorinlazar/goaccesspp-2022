#pragma once
#ifndef OPESYS_H_INCLUDED
#define OPESYS_H_INCLUDED

#define OPESYS_TYPE_LEN 10

/* Each OS contains the number of hits and the OS's type */
typedef struct GOpeSys_ {
  char os_type[OPESYS_TYPE_LEN];
  int hits;
} GOpeSys;

char* verify_os(char* str, char* os_type);

#endif
