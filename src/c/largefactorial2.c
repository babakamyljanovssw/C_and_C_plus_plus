#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("enter number = ");
    scanf("%d",&n);

    unsigned long long int prod = 1;
    for (int i = 2; i <= n; i++)
    {
        prod *= i;
    }
    printf("%llu",prod);
    system("pause");
    return 0;
}