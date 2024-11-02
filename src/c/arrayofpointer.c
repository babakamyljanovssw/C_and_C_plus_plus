#include<stdio.h>
int main()
{
    char *A[3] = {"abc","def","ghi"};
    char *temp;
    // before swap
    printf("%s %s %s\n",A[0],A[1],A[2]);
    temp = A[0];
    A[0] = A[1];
    A[1] = temp;
    // After the swap
    printf("%s %s %s\n",A[0],A[1],A[2]);
    return 0;
}