#include<stdio.h>
int main()
{
    int A[2][3] = {{3, 5, 7},{2, 4, 6}};
    printf("%d\n", *(*A+1));
    return 0;
}