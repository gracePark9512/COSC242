/*flexarray.c
  @author Group 30*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "flexarray.h"


struct flexarrayrec{
  int capacity;
  int itemcount;
  char **items;
};

/*method to create new flexarray.
  returns result, which creates empty flexarray.
*/
flexarray flexarray_new(){
    flexarray result = emalloc(sizeof(*result));
    result->capacity =2;
    result->itemcount = 0;
    result->items = emalloc(result -> capacity * sizeof result -> items[0]);
    return result;
}

/*method is called by container_add to add elements in to flexarray.
  @param f flexarray that elements are added on to
  @param *str elements that are being added
*/ 
flexarray flexarray_append(flexarray f, char *str){
  if(f->itemcount == f->capacity){
    f->capacity += f->capacity;
    f->items = erealloc(f->items, f-> capacity * sizeof f -> items[0]);
  }
  f-> items[f->itemcount] = emalloc(strlen(str) +1);
  strcpy(f->items[f->itemcount], str);
  f->itemcount++;
  return f;
}

/*method that prints all the elements in the flexarray.
  method is called by container_print()
  @param f flextarray that contains elements that being printed.
*/ 
void flexarray_print(flexarray f){
  int i;
  for (i =0; i< f->itemcount; i++){
      printf("%s, ",f->items[i]);
  }
}

/*methods that frees the elements in flexarray that is already allocated.
  @param f flexarray that holds elements and waiting to be free
*/
flexarray flexarray_free(flexarray f){
    free(f);
    return f;
}

/*methods that search words that matched the input.
  called by container_search
  @param f flexarray that is being searched
  @param *str element that is being searched
  returns 1 if element is found in the array 
  returns 0 if element is not fount in the array
*/
int is_present(flexarray f, char *str){
    int i;
    for(i = 0; i < f->itemcount; i++){
        if(strcmp(f->items[i], str) == 0){
            return 1;
        }
    }
    return 0;
 }

/*method that prints itmes in flexarray.
  @param f flexarray that is going to be printed 
  @func(char *str) function that takes place as parameter
*/
void visit(flexarray f, void func(char *str)){
    int j;
    
    for(j = 0; j < f-> itemcount; j++){
        func(f->items[j]);
    }
    return;
}







