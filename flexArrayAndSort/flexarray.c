#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

void *emalloc(size_t s) {
    void *result = malloc(s);
    
    if (NULL == result) {
        fprintf(stderr, "memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void *erealloc(void *p, size_t s) {
    void * result = realloc(p, s);

    if (NULL == result) {
        fprintf(stderr, "memory reallocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}



flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}

void flexarray_append(flexarray f, int num) {
    if (f->itemcount == f->capacity) {
        f->capacity += f->capacity;
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }
    f->items[f->itemcount++] = num;
}

void flexarray_print(flexarray f) {
    int i;
    for (i = 0; i < f->itemcount; i++) {
        printf("%d\n", f->items[i]);
    }
}

    void flexarray_sort(flexarray f) {
        int i, j;
        for(i=1; i<f->itemcount; i++){
            int id = f->items[i];
            if(i== f->itemcount/2){
                int d;
                for(d=0; d<f->itemcount; d++){
                    fprintf(stderr,"%d\n", f->items[d]);
                }
            }
            for(j=i; j>0 && f->items[j-1] > id; j--){
                f->items[j] = f->items[j-1];
            }
            f->items[j] = id;
        }
    }
void flexarray_free(flexarray f) {
    free(f);
}
