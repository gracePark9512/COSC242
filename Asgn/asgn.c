/*asgn.c
  @author Group 30*/
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>

#include "mylib.h"
#include "flexarray.h"
#include "htable.h"
#include "container.h"

#define DEFAULT 3877

void print_key(char *str){
    printf("%s ", str);
}

/*main method.
  @param argc, integer that counts terminal inputs.
  @param **argv, points to the position where inputs are being executed*/
int main(int argc, char **argv){
    htable h;
    char word[256];
    FILE *dictionary;
    
    int capacity = DEFAULT;
    int printInfo = 0;
    int printHtable = 0;
    int unknown_words_num = 0;
    container_t c_type = FLEX_ARRAY;
    
    clock_t fillStart, fillEnd, searchStart, searchEnd;
    double fillTime = 0;
    double searchTime = 0;

    const char *optstring;
    char option;
    
    optstring = "rs:pih";
    while ((option = getopt(argc, argv, optstring)) != EOF) {
        switch (option) {
            case 'r':
                c_type = RED_BLACK_TREE;
                break;
            case 's':
                capacity = atoi(optarg);
                break; 
            case 'p':
                printHtable = 1;
                break;
            case 'i':
                printInfo = 1;
                break;
            case 'h':               
            default:
                fprintf(stderr, "Instructions on how to use this program:\n");
                fprintf(stderr, "Enter -r to use a robust chaining method.\n");
                fprintf(stderr, "Enter -s followed by a table size to set the");
                fprintf(stderr, " hashtable size.\n");
                fprintf(stderr, "Enter -p to print the hash table.\n");
                fprintf(stderr, "Enter -i to print info about how long it took");
                fprintf(stderr, " to fill hash table.\n");
                exit(EXIT_FAILURE);
        }
    }

    if(optind < argc){
        if(NULL == (dictionary = fopen(argv[optind], "r"))){
            fprintf(stderr, "Couldn't open file. Exit Program.\n");
            exit(EXIT_FAILURE);
        } else{
            fillStart = clock();
            h = htable_new(capacity);
            while (getword(word, sizeof word, dictionary) != EOF) {
                htable_insert(h, word, c_type);
            }
            fillEnd = clock();
            fillTime = (fillEnd - fillStart) / (double)CLOCKS_PER_SEC;
        }
        fclose(dictionary);

        if(printHtable){
            htable_print(h, stdout, print_key);
        } else{
            searchStart = clock();
            while (getword(word, sizeof word, stdin) != EOF) {
                if(htable_search(h, word) == 0){
                    fprintf(stdout, "%s\n", word);
                    unknown_words_num++;
                }
            }
            searchEnd = clock();
            searchTime = (searchEnd - searchStart) / (double) CLOCKS_PER_SEC;
        }
        htable_free(h);
    }



    if(printInfo){
        fprintf(stderr, "Fill time : %f\n", fillTime);
        fprintf(stderr, "Search time : %f\n", searchTime);
        fprintf(stderr, "Unknown words : %d\n", unknown_words_num);
    }

    return EXIT_SUCCESS;
}
