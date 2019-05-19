#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "htable.h"
#include "mylib.h"

struct htablerec {
    int capacity;
    int num_keys;
    char **keys;
};

static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;

    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    return result;
}

htable htable_new(int capacity) {
    int i;
    htable h = emalloc(sizeof *h);
    h->capacity = capacity;
    h-> num_keys = 0;
    h-> keys = emalloc (h->capacity *sizeof h->keys[0]);

    for(i=0; i<h->capacity; i++){
        h->keys[i] = NULL;
    }
    return h;
}


void htable_free(htable h) {
    int i;
    for(i=0; i<h->capacity; i++){
        free(h->keys[i]);
    }
    free(h->keys);
    free(h);
}


int htable_insert(htable h, char *key) {
    unsigned int position= (htable_word_to_int(key) % h->capacity);
    int i;
    if(h->keys[position] == NULL){
        h->keys[position] = emalloc(strlen(key) +1 *sizeof h->keys[position]);
        strcpy(h->keys[position], key);
        h->num_keys++;
        return 1;
    }
    if(strcmp(h->keys[position], key) == 0){
        return 1;
    }else{
        for(i=0; i<h->capacity; i++){
           if(h->keys[position] == NULL){
        h->keys[position] = emalloc(strlen(key) +1 *sizeof h->keys[position]);
        strcpy(h->keys[position], key);
        h->num_keys++;
        return 1;
    }
           position = position+1 % h->capacity;
        }
    }
    return 0;
}
    


void htable_print(htable h, FILE *stream) {
 int i;
    for (i = 0; i < h->capacity; i++) {
        fprintf(stream, "%2d %s\n", i, h->keys[i] == NULL ? "" : h->keys[i]);
    }

}
