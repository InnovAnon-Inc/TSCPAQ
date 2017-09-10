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

__attribute__ ((nonnull (1, 2), nothrow, warn_unused_result))
int tscpaq_init_queue (
   tscpaq_t *restrict q,
   void *restrict arr,
   size_t n) {
   init_queue (&(q->cpaq), arr, n);
   q->mutex = (pthread_mutex_t) PTHREAD_MUTEX_INITIALIZER;
   error_check (sem_init (&(q->full),  0, (unsigned int) n) != 0) return -1;
   error_check (sem_init (&(q->empty), 0,                 0) != 0) return -2;
   return 0;
}

__attribute__ ((nonnull (1), nothrow, warn_unused_result))
int tscpaq_uninit_queue (tscpaq_t *restrict q) {
   error_check (pthread_mutex_destroy (&(q->mutex)) != 0) return -1;
   error_check (sem_destroy (&(q->full)) != 0) return -2;
   error_check (sem_destroy (&(q->empty)) != 0) return -3;
   return 0;
}

__attribute__ ((nonnull (1), nothrow, warn_unused_result))
int tscpaq_alloc_queue (
   tscpaq_t *restrict q,
   size_t n) {
   void *restrict arr = malloc (n * sizeof (void *));
   error_check (arr == NULL) return -1;
   tscpaq_init_queue (q, arr, n);
   return 0;
}

__attribute__ ((nonnull (1), nothrow, warn_unused_result))
int tscpaq_free_queue (tscpaq_t *restrict q) {
   free_queue (&(q->cpaq));
   error_check (tscpaq_uninit_queue (q) != 0) return -1;
   return 0;
}

__attribute__ ((nonnull (1, 2), nothrow, warn_unused_result))
int tscpaq_enqueue (
   tscpaq_t *restrict q,
   void *restrict elem) {
   error_check (pthread_mutex_lock (&(q->mutex)) != 0) return -1;
   do {
      error_check (pthread_mutex_unlock (&(q->mutex)) != 0) return -2;
      error_check (sem_wait (&(q->full)) != 0) return -3;
      error_check (pthread_mutex_lock (&(q->mutex)) != 0) return -4;
      /* TODO isfull() is unexptected ? */
   } while (isfull (&(q->cpaq))) ;
   error_check (enqueue (&(q->cpaq), elem) != 0) {
      /*sem_post (&(q->empty));*/
      /*q->done = true;*/
      pthread_mutex_unlock (&(q->mutex));
      return -5;
   }
   error_check (sem_post (&(q->empty)) != 0) {
      pthread_mutex_unlock (&(q->mutex));
      return -6;
   }
   error_check (pthread_mutex_unlock (&(q->mutex)) != 0) return -7;
   return 0;
}

__attribute__ ((nonnull (1, 2), nothrow, warn_unused_result))
int tscpaq_dequeue (
   tscpaq_t *restrict q,
   void const *restrict *restrict ret) {
   error_check (pthread_mutex_lock (&(q->mutex)) != 0) return -1;
   do {
      error_check (pthread_mutex_unlock (&(q->mutex)) != 0) return -2;
      error_check (sem_wait (&(q->empty)) != 0) return -3;
      error_check (pthread_mutex_lock (&(q->mutex)) != 0) return -4;
   } while (isempty (&(q->cpaq))) ;
   *ret = dequeue (&(q->cpaq));
   /*if (ret == NULL) {*/
      /*sem_post (&(q->full));*/
      /*q->done = true;*/
   /*   pthread_mutex_unlock (&(q->mutex));
      return -5;
   }*/
   error_check (sem_post (&(q->full)) != 0) {
      pthread_mutex_unlock (&(q->mutex));
      return -6;
   }
   error_check (pthread_mutex_unlock (&(q->mutex)) != 0) return -7;
   return 0;
}

__attribute__ ((nonnull (1, 2), nothrow, warn_unused_result))
int tscpaq_isempty (
   tscpaq_t *restrict q,
   bool *restrict ret) {
   error_check (pthread_mutex_lock (&(q->mutex)) != 0) return -1;
   *ret = isempty (&(q->cpaq));
   error_check (pthread_mutex_unlock (&(q->mutex)) != 0) return -2;
   return 0;
}

__attribute__ ((nonnull (1, 2), nothrow, warn_unused_result))
int tscpaq_isfull (
   tscpaq_t *restrict q,
   bool *restrict ret) {
   error_check (pthread_mutex_lock (&(q->mutex)) != 0) return -1;
   *ret = isfull (&(q->cpaq));
   error_check (pthread_mutex_unlock (&(q->mutex)) != 0) return -2;
   return 0;
}

__attribute__ ((nonnull (1, 2), nothrow, warn_unused_result))
int tscpaq_gethead (
   tscpaq_t *restrict q,
   void const *restrict *restrict ret) {
   error_check (pthread_mutex_lock (&(q->mutex)) != 0) return -1;
   *ret = gethead (&(q->cpaq));
   error_check (pthread_mutex_unlock (&(q->mutex)) != 0) return -2;
   return 0;
}

__attribute__ ((nonnull (1), nothrow, warn_unused_result))
int tscpaq_dumpq(
   tscpaq_t *restrict q,
   int i) {
   error_check (pthread_mutex_lock (&(q->mutex)) != 0) return -1;
   dumpq (&(q->cpaq), i);
   error_check (pthread_mutex_unlock (&(q->mutex)) != 0) return -2;
   return 0;
}