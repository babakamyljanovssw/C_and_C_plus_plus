#include<stdio.h>
#include<stdlib.h>
int main()
{
    int* p;
    p = (int*)malloc(sizeof(int));
    *p = 20;
    printf("Address = %d\n", p);
    printf("Value = %d\n", *p);
    int *A = (int*)malloc(5*sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        A[i] = i + 1;
    }
    int *B = (int*)realloc(A,2*5*sizeof(int));
    // int *B = (int*)realloc(NULL, n*sizeof(int)); equivalent to malloc
    // int *A = (int*)realloc(A,0); equivalent to free(A);
    printf("Prev block address = %d , new address = %d\n", A, B);
    for (int i = 0; i < 2*5; i++)
    {
        printf("%d\n", B[i]);
    }
    return 0;
}