#include<stdio.h>
#include<stdlib.h>

/**
 * program to reverse integer
 */

int main(int argc, char* argv[]){
    if(argc < 2){
        perror("\nInvalid number of arguments!");
        return 0;
    }

    int num;
    num = atoi(argv[1]);
    printf("\nThe input number is %d\n", num);

    int rev=0, neg=0, pop;
    if (num < 0){
        neg = 1;
        num = - num;
    }
    while(num > 0){
        pop = num % 10;
        if(rev > INT_MAX/10 || ( rev == INT_MAX/10 && pop > 7)) return 0;


        rev = rev * 10 + num % 10;
        num /= 10;
    }
    if(neg)
        rev = - rev;
    printf("The reversed number is %d\n", rev);
}