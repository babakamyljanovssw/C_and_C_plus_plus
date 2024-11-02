#include<stdio.h>
#include<stdlib.h>
int main()
{
    int N;
    printf("Enter an integer: ");
    scanf("%d", &N);
    printf("The multiplication table of %d is:\n", N);

    for (int i = 1; i <= 10; i++)
    {
        printf("%d * %d = %d\n", N, i, i*N);
    }
    return 0;
}