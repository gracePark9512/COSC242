/*================================
  =            Group 30            =
  ================================*/

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "container.h"
#include "rbt.h"
#include "flexarray.h"
#include "mylib.h"

struct containerrec {
	container_t type;
	void *contents;
};

/**
 * 	Acts a shell to pass parameters to methods from rbt.c and
 flexarrays.c.
 * 	@param - A type of container that indicates if its going to be
 a RBT container or flexarray container.
 *	@return - container with an empty RBT or flexarray.
 *	Special note - the method called depends on if the container type
 is classed as RBT or not.
*/
container container_new(container_t c_type){
    container c = emalloc(sizeof *c);
    c->type = c_type;
    if(c->type == RED_BLACK_TREE){
        c->contents = rbt_new();
    }else{
        c->contents = flexarray_new();
    }
    return c;
}

/**
 * 	Acts a shell to pass parameters to methods from rbt.c and
 flexarrays.c.
 * 	@param - A type of container that indicates if its going to be
 a RBT container or flexarray container.
 *	@return - container with an empty RBT or flexarray.
 *	Special note - the method called depends on if the container type
 is classed as RBT or not.
*/
container container_add(container c, char *word) {
	if (c->type == RED_BLACK_TREE) {
		c->contents = rbt_insert(c->contents, word);
	} else {
		c->contents = flexarray_append(c->contents, word);
	}
	return c;
}

/**
 * 	Acts a shell to pass parameters to methods from rbt.c and
 flexarrays.c.
 * 	@param - The container which holds the type of storage of 
 either RBT or flexarray.
 *	@param - The string that is being searched for.
 *	@return - '1' if the String was found and '0' if not.
 *	Special note - the method called depends on if the container type
 is classed as RBT or not.
*/
int container_search(container c, char *word){
	int search;
	if (c->type == RED_BLACK_TREE){
		search = rbt_search(c->contents, word);
	}else{
		search = is_present(c->contents, word);
	}
	return search;
}

/**
 * 	Acts a shell to pass parameters to methods from rbt.c and
 flexarrays.c.
 * 	@param - The container which holds the type of storage of 
 either RBT or flexarray.
 *	Special note - the method called depends on if the container type
 is classed as RBT or not.
*/
void container_free(container c){
	if (c->type == RED_BLACK_TREE){
		c->contents = rbt_free(c->contents);
	}else{
		c->contents = flexarray_free(c->contents);
	}
}

/**
 * 	Acts a shell to pass parameters to methods from rbt.c and
 flexarrays.c.
 * 	@param - The container which holds the type of storage of 
 either RBT or flexarray.
 @param - A function that is to be passed into the methods from
 rbt.c and flexarray.c.
 *	Special note - the method called depends on if the container type
 is classed as RBT or not.
*/
void container_print(container c, void f(char *str)){
	if (c->type == RED_BLACK_TREE){
		rbt_preorder(c->contents, f);
	}else{
		visit(c->contents, f);
	}
}
