#include<stdio.h>
int main()
{
    int i, j;
    printf("        1   2   3   4   5   6   7   8   9   10\n");
    printf("  ------------------------------------------\n");
    for (int i = 1; i <= 10; i++)
    {
        printf("%4d|", i);
        for (int j = 1; j <= i; j++)
        {
            printf("%4d", i*j);
        }
        printf("\n");
    }
    printf("----------------------------------------------\n");
    return 0;
}