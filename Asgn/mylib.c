#include <stdio.h> /* for fprintf */
#include <stdlib.h> /* for size_t, malloc, realloc, exit */
#include <assert.h>
#include <ctype.h>

#include "mylib.h"

/**allocates size bytes of memory and does necessaru checks
   @param s, takes specific size into argument.**/
void *emalloc(size_t s) {
    void *p = malloc(s);
    if(!p){
        fprintf(stderr, "Memory Allocation Failed! \n");
        exit(EXIT_FAILURE);
    }
    return p;
}
/**creates extra memory when needed
   @param *p, pointer
   @param s, takes specific size into argument.**/
void *erealloc(void *p, size_t s) {
    void *r = realloc(p,s);
    if (!r){
        fprintf(stderr,"Memory Allocation Failed!");
        exit(EXIT_FAILURE);
    }
    return r;
}

/**method that reads in words one at a time and uses isalnum() to make sure
   character passed is alphanumeric. also makes sure 'i' isnt at the EOF
   (end of file).
   @param s, word that is read in from file
   @param count, count variable to keep track of characters in words
   @param *stream, the file from which the words are read from.
   returns an int.**/
int getword(char *s, int limit, FILE *stream) {
	int c;
	char *w = s;
	assert(limit > 0 && s != NULL && stream != NULL);
	while (!isalnum(c = getc(stream)) && EOF != c)
		;
	if (EOF == c) {
		return EOF;
} else if (--limit > 0) {
		*w++ = tolower(c);
	}
	while (--limit > 0) {
		if (isalnum(c = getc(stream))) {
			*w++ = tolower(c);
		} else if ('\'' == c) {
			limit++;
		} else {
			break;
		}
	}
	*w = '\0';
	return w - s;
}
