#include <stdio.h>
#include <stdlib.h>

int main(void){
    double  s1, s2, s3 = 0.0;
    int  n;
    int id =0;
    double win = 0.0;

    while(4 == scanf("%d%lg%lg%lg",&n, &s1, &s2, &s3)){
        double check =0.0;
        if(s1<=s2 && s1<=s3){
            check = (s2+s3)/2;
        }else if(s2<=s1 && s2<=s3){
            check = (s1 +s3)/2;
        }else{
            check = (s1 +s2)/2;
        }

        if (check > win){
            id = n;
            win = check;
        }
    }
    printf("%d\n",id);
    return EXIT_SUCCESS;
}


        
