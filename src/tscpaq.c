#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tscpaq.h"

/*#define n (4)*/

/*
int Q[n];
int head = 0;
int tail = 0;
*/

int tscpaq_init_queue (tscpaq_t *q, void *arr, size_t n) {
   init_queue (&(q->cpaq), arr, n);
   q->mutex = (pthread_mutex_t) PTHREAD_MUTEX_INITIALIZER;
   if (sem_init (&(q->full),  0, (unsigned int) n) != 0) return -1;
   if (sem_init (&(q->empty), 0,                 0) != 0) return -2;
   return 0;
}

int tscpaq_alloc_queue (tscpaq_t *q, size_t n) {
	void *arr = malloc (n * sizeof (void *));
	if (arr == NULL) return -1;
	tscpaq_init_queue (q, arr, n);
	return 0;
}

void tscpaq_free_queue (tscpaq_t *q) {
	free_queue (&(q->cpaq));
}

int tscpaq_enqueue (tscpaq_t *q, void *elem) {
   if (pthread_mutex_lock (&(q->mutex)) != 0) return -1;
   do {
      if (pthread_mutex_unlock (&(q->mutex)) != 0) return -2;
      if (sem_wait (&(q->full)) != 0) return -3;
      if (pthread_mutex_lock (&(q->mutex)) != 0) return -4;
   } while (isfull (&(q->cpaq))) ;
   if (enqueue (q->cpaq, elem) != 0) {
      /*sem_post (&(q->empty));*/
      /*q->done = true;*/
      pthread_mutex_unlock (&(q->mutex));
      return -5;
   }
   if (sem_post (&(q->empty)) != 0) {
      pthread_mutex_unlock (&(q->mutex));
      return -6;
   }
   if (pthread_mutex_unlock (&(q->mutex)) != 0) return -7;
   return 0;
}

int tscpaq_dequeue (tscpaq_t *q, void **ret) {
   if (pthread_mutex_lock (&(q->mutex)) != 0) return -1;
   do {
      if (pthread_mutex_unlock (&(q->mutex)) != 0) return -2;
      if (sem_wait (&(q->empty)) != 0) return -3;
      if (pthread_mutex_lock (&(q->mutex)) != 0) return -4;
   } while (isempty (&(q->cpaq))) ;
   *ret = dequeue (&(q->cpaq));
   /*if (ret == NULL) {*/
      /*sem_post (&(q->full));*/
      /*q->done = true;*/
   /*   pthread_mutex_unlock (&(q->mutex));
      return -5;
   }*/
   if (sem_post (&(q->full)) != 0) {
      pthread_mutex_unlock (&(q->mutex));
      return -6;
   }
   if (pthread_mutex_unlock (&(q->mutex)) != 0) return -7;
   return 0;
}

int tscpaq_isempty (tscpaq_t *q, bool *ret) {
   if (pthread_mutex_lock (&(q->mutex)) != 0) return -1;
   *ret = isempty (&(q->cpaq));
   if (pthread_mutex_unlock (&(q->mutex)) != 0) return -2;
   return 0;
}

int tscpaq_isfull (tscpaq_t *q, bool *ret) {
   if (pthread_mutex_lock (&(q->mutex)) != 0) return -1;
   *ret = isfull (&(q->cpaq));
   if (pthread_mutex_unlock (&(q->mutex)) != 0) return -2;
   return 0;
}

int tscpaq_gethead (tscpaq_t *q, void **ret) {
   if (pthread_mutex_lock (&(q->mutex)) != 0) return -1;
   *ret = gethead (&(q->cpaq));
   if (pthread_mutex_unlock (&(q->mutex)) != 0) return -2;
   return 0;
}


void tscpaq_dumpq(tscpaq_t *q, int i) {
   if (pthread_mutex_lock (&(q->mutex)) != 0) return -1;
   dumpq (&(q->cpaq), i);
   if (pthread_mutex_unlock (&(q->mutex)) != 0) return -2;
   return 0;
}