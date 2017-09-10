#ifndef _CAQ_H_
#define _CAQ_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <sys/types.h>

#include <pthread.h>
#include <semaphore.h>

#include <cpaq.h>

typedef struct {
	cpaq_t cpaq;
	pthread_mutex_t mutex;
	sem_t empty, full;
} tscpaq_t;

void init_queue (tscpaq_t *q, void *arr, size_t n);
int alloc_queue (tscpaq_t *q, size_t n) ;
void free_queue (tscpaq_t *q) ;

/* ret type == elem type */
int dequeue (tscpaq_t *q, void **ret) ;
/* returns err code */
int enqueue (tscpaq_t *q, void *elem) ;
int isempty (tscpaq_t *q, bool *ret)
__attribute__ ((pure)) ;
int isfull (tscpaq_t *q, bool *ret)
__attribute__ ((pure)) ;
int gethead (tscpaq_t *q, void **ret)
__attribute__ ((pure)) ;
void dumpq(tscpaq_t *q, int i) ;

#ifdef __cplusplus
}
#endif

#endif /* _CAQ_H_ */