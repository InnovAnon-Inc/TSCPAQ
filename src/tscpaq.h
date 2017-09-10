#ifndef _TSCPAQ_H_
#define _TSCPAQ_H_

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

void tscpaq_init_queue (tscpaq_t *q, void *arr, size_t n);
int tscpaq_alloc_queue (tscpaq_t *q, size_t n) ;
void tscpaq_free_queue (tscpaq_t *q) ;

/* ret type == elem type */
int tscpaq_dequeue (tscpaq_t *q, void **ret) ;
/* returns err code */
int tscpaq_enqueue (tscpaq_t *q, void *elem) ;
int tscpaq_isempty (tscpaq_t *q, bool *ret)
int tscpaq_isfull (tscpaq_t *q, bool *ret)
int tscpaq_gethead (tscpaq_t *q, void **ret)
void tscpaq_dumpq(tscpaq_t *q, int i) ;

#ifdef __cplusplus
}
#endif

#endif /* _TSCPAQ_H_ */