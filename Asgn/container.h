/*================================
  =            Group 30          =
  ================================*/

/**
 * 	Libary for container.c
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_
typedef struct containerrec *container;
typedef enum container_e {RED_BLACK_TREE, FLEX_ARRAY} container_t;

extern container container_new(container_t c_type);
extern container container_add(container c, char *word);
extern int       container_search(container c, char *word);
extern void      container_free(container c);
extern void      container_print(container c, void f(char *str));

#endif
