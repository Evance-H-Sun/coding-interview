#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxSubarray(int a[], int size);

int main(void)
{
    /* The input must contains at least one positive number.*/
    int a[] = {1,-2,3,10,-4,7,2,-5};
    int maxSum;
    int length = sizeof(a)/sizeof(int);
    maxSum = maxSubarray(a, length);
    /* printf("Size of type(int) and length of array is: %ld, %d\n", sizeof(int), length); */
    printf("Max sum of sub array is: %d\n", maxSum);

    return 0;
}

int maxSubarray(int a[], int length)
{
    /* Note: here a[] as the parameter, sizeof(a) == sizeof(int * a), NOT the array size */
    int i = 0;
    int maxSum = INT_MIN;
    /*
    int maxSum = 1<<(sizeof(int)*8 -1);
    printf("Min(int): 1<<(sizeof(int) -1)is: %d\n", maxSum);
    printf("INT_MIN in <limits.h> is: %d\n", INT_MIN);
    int MAX_INT = (1<<(sizeof(int)*8 -1))-1;
    */
    int sum = 0;
    while(i < length){
        sum = sum + a[i];
        i++;
        if(sum > maxSum){
            maxSum = sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    return maxSum;
}