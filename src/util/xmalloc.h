#pragma once
#ifndef XMALLOC_H_INCLUDED
#define XMALLOC_H_INCLUDED

char* xstrdup(const char* s);
void* xcalloc(size_t nmemb, size_t size);
void* xmalloc(size_t size);
void* xrealloc(void* oldptr, size_t size);

#endif
