/**
 * Program to benchmark computation time of incrementing a variable 10 million times
 */

#include <stdio.h>

int main()
{
    int i;
    for (i = 0; i < 20000000; i++)
    {
        i++;
    }
    printf("The value of i is %d\n", i);
}
