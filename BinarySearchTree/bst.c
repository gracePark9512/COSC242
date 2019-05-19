#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bst.h"
#include "mylib.h"

struct bstnode {
    char *key;
    bst left;
    bst right;
};


bst bst_free(bst b) {
    if (b == NULL) {
        return b;
    }
    
    bst_free(b->left);
    bst_free(b->right);
    free(b->key);
    free(b);
    return b;
}


bst bst_new() {
    return NULL;

}


void bst_inorder(bst b, void f(char *s)) {
    if (b == NULL) {
        return;
    }
    bst_inorder(b->left, f);
    f(b->key);
    bst_inorder(b->right, f);
    
}

bst bst_insert(bst b, char *str) {
    if (b == NULL){
       bst newB = emalloc(sizeof *newB);
       newB->key = emalloc(strlen(str)+1 * sizeof str[0]);
        strcpy(newB->key, str);
        newB ->left= NULL;
        newB -> right = NULL;
        return newB;

    }
    else if(strcmp(b->key, str) ==0){
            return b;
        
    }
    else if (strcmp(str, b->key) < 0) {
        b->left = bst_insert(b->left, str);
    } else{
        b->right = bst_insert(b->right, str);
    }
    return b;
}


void bst_preorder(bst b, void f(char *s)) {
    if (b == NULL) {
        return;
    }
    f(b->key);
    bst_inorder(b->left, f);
    
    bst_inorder(b->right, f);
}

int bst_search(bst b, char *str) {
    if(b==NULL){
        return 0;  
    }
    
    if(strcmp(b->key,str)==0){
        return 1;
    }
    if(strcmp(b->key,str) > 0){
        return bst_search(b->left, str);   
    }
    
    return bst_search(b->right, str);

}
