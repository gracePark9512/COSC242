/*================================
  =            Group 30          =
  ================================*/

/**
 * 	Libary for MyLib.c
 */

#ifndef MYLIB_H_
#define MYLIB_H_

#include <assert.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>

extern void *emalloc(size_t);
extern void *erealloc(void *, size_t);
extern int getword(char *s, int limit, FILE *stream);

#endif
