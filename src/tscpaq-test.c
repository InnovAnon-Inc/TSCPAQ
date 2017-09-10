#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tscpaq.h"

#define N (4)

int main(void) {
   int arr[] = {101, 202, 303, 404, 505};
   int *tmp;

   tscpaq_t q;
   tscaq_alloc_queue (&q, (size_t) N);

   tscaq_dumpq(&q, 1);
   tscaq_enqueue (&q, arr + 0);tscaq_dumpq(&q, 2);
   tscaq_enqueue (&q, arr + 1);tscaq_dumpq(&q, 3);
   tscaq_enqueue (&q, arr + 2);tscaq_dumpq(&q, 4);
   tscaq_enqueue (&q, arr + 3);tscaq_dumpq(&q, 5);
   tscaq_enqueue (&q, arr + 4);tscaq_dumpq(&q, 6);
   /*memset (arr, 0, sizeof (arr));*/
   printf("%i\n", *(int *) tscaq_dequeue(&q));
      tscaq_dumpq(&q, 7);
   printf("%i\n", *(int *) tscaq_dequeue(&q));
      tscaq_dumpq(&q, 8);
   printf("%i\n", *(int *) tscaq_dequeue(&q));
      tscaq_dumpq(&q, 9);
   tmp = (int *) tscaq_dequeue (&q);
   if (tmp == NULL) puts ("NULL");
   else printf("%i\n", *tmp);
      tscaq_dumpq(&q, 10);
   tmp = (int *) tscaq_dequeue (&q);
   if (tmp == NULL) puts ("NULL");
   else printf ("%i\n", *tmp);
      tscaq_dumpq(&q, 11);

   tscaq_free_queue (&q);
   return EXIT_SUCCESS;
}