#include<stdio.h>
#include<stdlib.h>
int sumarray(int N, int *A)
{
    int sum = 0; 
    for (int i = 0; i < N; i++)
    {
        sum += *(A+i);
    }
    return sum;
}
int main()
{
    int a[5] = {1, 2, 5, 6, 9};
    int b[2][3] = {1, 5, 8, 7, 9, 3};
    int sum;
    sum = sumarray(5,a);
    printf("%d\n", sum);
    sum = sumarray(2*3, &b[0][0]);
    printf("%d\n", sum);
}