#include <stdio.h>
#include <stdlib.h>


int is_prime(int candi){
    int n;
    for(n =2; n<candi; n++){
        if(candi%n == 0){
            return 0;
        }
    }
        return 1;
  }

    int main(void){
        int candi =2;
        int num_print = 0;
        while (num_print < 200){
            if(is_prime(candi)==1){
                printf("%5d", candi);
                num_print++;
                
            if(num_print%10 == 0){
                printf("\n");
            }
            }
            candi++;
        }
        return EXIT_SUCCESS;
    }
