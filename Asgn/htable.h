/*================================
  =            Group 30          =
  ================================*/

#ifndef HTABLE_H_
#define HTABLE_H_

#include <stdio.h>
#include "container.h"

typedef struct htablerec *htable;

extern void htable_free(htable h);
extern int htable_insert(htable h, char *str, container_t c_type);
extern htable htable_new(int capacity);
extern void htable_print(htable h, FILE *stream, void f(char *str));
extern int htable_search(htable h, char *str);

#endif
