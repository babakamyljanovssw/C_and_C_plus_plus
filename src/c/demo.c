#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
    int a, b, sum=0;
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("\nEnter second number: ");
    scanf("%d", &b);
    sum = a + b;
    printf("The sum= %d\n", sum);
    return 0;
}