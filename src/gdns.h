#pragma once
#ifndef GDNS_H_INCLUDED
#define GDNS_H_INCLUDED

#define H_SIZE     1025
#define QUEUE_SIZE 400

typedef struct GDnsThread_ {
  pthread_cond_t not_empty;     /* not empty queue condition */
  pthread_cond_t not_full;      /* not full queue condition */
  pthread_mutex_t mutex;
  pthread_t thread;
} GDnsThread;

typedef struct GDnsQueue_ {
  int head;                     /* index to head of queue */
  int tail;                     /* index to tail of queue */
  int size;                     /* queue size */
  int capacity;                 /* length at most */
  char buffer[QUEUE_SIZE][H_SIZE];      /* data item */
} GDnsQueue;

extern GDnsThread gdns_thread;

char *gqueue_dequeue (GDnsQueue * q);
char *reverse_ip (char *str);
int gqueue_empty (GDnsQueue * q);
int gqueue_enqueue (GDnsQueue * q, const char *item);
int gqueue_find (GDnsQueue * q, const char *item);
int gqueue_full (GDnsQueue * q);
int gqueue_size (GDnsQueue * q);
void dns_resolver (char *addr);
void gdns_free_queue (void);
void gdns_init (void);
void gdns_queue_free (void);
void gdns_thread_create (void);
void gqueue_destroy (GDnsQueue * q);
void gqueue_init (GDnsQueue * q, int capacity);

#endif
