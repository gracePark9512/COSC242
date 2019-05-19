/*htable.c
  @author Group30. */ 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"
#include "container.h"

struct htablerec{
	int capacity;
	int num_keys;
	int *frequencies;
	container *keys;
};

/* method that creates new hash-table. 
   @param capacity indicates needed spaces.
   emalloc is used to allocate memories to either RBT or flexarray. */
htable htable_new(int capacity){
	int i;
	htable new = emalloc (sizeof *new);
	new->capacity = capacity;
	new->num_keys = 0;
	new->frequencies = emalloc(new->capacity *sizeof new->frequencies[0]);
	new->keys = emalloc(new->capacity *sizeof new->keys[0]);
	for(i = 0; i < new->capacity; i++){
		new->frequencies[i] = 0;
		new->keys[i] = NULL;
	}
	return new;
}

/*method that frees memory after execution
  @param h passes htable to method. */
void htable_free(htable h){
	int i;
	for(i = 0; i < h->capacity; i++){
		if(h->keys[i] != NULL){
			container_free(h->keys[i]);
		}
	}
	free(h->keys);
	free(h->frequencies);
	free(h);
}

/*method that changes word to int.
  @param *word points to word that is going to be converted.
  returns result that is converted int from word. */
static unsigned int htable_word_to_int(char *word) {
	unsigned int result = 0;
	while (*word != '\0') {
		result = (*word++ + 31 * result);
	}
	return result;
}

/*method that insert elements into the htable in right order
  @param h hash-table that elements are being inserted to.
  @param *str pointer to the word that is being inserted.
  @param c_type gives type of the container.
  returns 1 if words were inserted successfully.
  returns 0 if words were inserted unsuccessfully. */ 
int htable_insert(htable h, char *str, container_t c_type) {
    unsigned int hashkey;
    unsigned int index;
    hashkey = htable_word_to_int(str);
    index = (hashkey % h->capacity);
    /*
    printf("The word is %s\n", str);
    printf("The hashkey is %x\n", hashkey);
    printf("The index is %x\n", index);
    */

    if(h->keys[index] == NULL){
        container c = container_new(c_type);
        container_add(c, str);
        h->keys[index] = c;
        return 1;
    }else if(h->keys[index] != NULL){
        container_add(h->keys[index], str);
        h->num_keys++;
        return 1;
    }
    return 0;
}

/*method that prints all elements in hash-table.
  @param h, the hashtable that holds the elements.
  @param *stream, the file that is being streamed.
  @param f(char *str), function that takes character as parameter.*/
void htable_print(htable h, FILE *stream, void f(char *str)) {
    int i;
    int index = 0;
	for (i = 0; i < h->capacity; i++) {
		if (h->keys[i] != NULL) {
			fprintf(stream, "\n%d ", index);
			container_print(h->keys[i], f);
                        index++;
		}
	}
}

/*method that searches RBT or flexarray.
  @param h, hashtable that is being searched.
  @param *str, word that is being searched in RBT or flexarray.
  return 0 if successfully executed */
int htable_search(htable h, char *str) {
    unsigned int hashkey;
    unsigned int index;
    hashkey = htable_word_to_int(str);
    index = (hashkey % h->capacity);

    if(h->keys[index] != NULL){
        return container_search(h->keys[index], str);
    }    
    return 0;
}
