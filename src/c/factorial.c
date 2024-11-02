#include<stdio.h>
#include<stdlib.h>

int fact(int N)
{
    if (N>=1)
    return N*fact(N-1);
    else
    return 1;
}

int main()
{
    int N;
    printf("Enter an integer: ");
    scanf("%d", &N);

    printf("The factorial of %d = %d\n", N, fact(N));
}