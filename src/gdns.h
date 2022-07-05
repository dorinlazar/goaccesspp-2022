#pragma once
#ifndef GDNS_H_INCLUDED
#define GDNS_H_INCLUDED

#define H_SIZE 1025
#define QUEUE_SIZE 400

typedef struct GDnsThread_ {
  pthread_cond_t not_empty; /* not empty queue condition */
  pthread_cond_t not_full;  /* not full queue condition */
  pthread_mutex_t mutex;
  pthread_t thread;
} GDnsThread;

extern GDnsThread gdns_thread;

char* reverse_ip(const char* str);
void dns_resolver(char* addr);
void gdns_free_queue(void);
void gdns_init(void);
void gdns_queue_free(void);
void gdns_thread_create(void);

#endif
