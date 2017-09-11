#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tscpaq.h"

#define N (4)

int main(void) {
   int arr[] = {101, 202, 303, 404, 505};
   int const *tmp;

   tscpaq_t q;
   tscpaq_alloc_queue (&q, (size_t) N);

   tscpaq_dumpq(&q, 1);
   tscpaq_enqueue (&q, arr + 0);tscpaq_dumpq(&q, 2);
   tscpaq_enqueue (&q, arr + 1);tscpaq_dumpq(&q, 3);
   tscpaq_enqueue (&q, arr + 2);tscpaq_dumpq(&q, 4);
   /*tscpaq_enqueue (&q, arr + 3);tscpaq_dumpq(&q, 5);
   tscpaq_enqueue (&q, arr + 4);tscpaq_dumpq(&q, 6);*/
   /*memset (arr, 0, sizeof (arr));*/
   tscpaq_dequeue (&q, (void const *restrict *)&tmp); printf ("%i\n", *tmp); tscpaq_dumpq(&q, 7);
   tscpaq_dequeue (&q, (void const *restrict *)&tmp); printf ("%i\n", *tmp); tscpaq_dumpq(&q, 8);
   tscpaq_dequeue (&q, (void const *restrict *)&tmp); printf ("%i\n", *tmp); tscpaq_dumpq(&q, 9);
   /*tscpaq_dequeue (&q, (void**)&tmp);
   if (tmp == NULL) puts ("NULL");
   else printf("%i\n", *tmp);
   tscpaq_dumpq(&q, 10);
   tscpaq_dequeue (&q, (void**)&tmp);
   if (tmp == NULL) puts ("NULL");
   else printf("%i\n", *tmp);
   tscpaq_dumpq(&q, 11);*/

   tscpaq_free_queue (&q);
   return EXIT_SUCCESS;
}