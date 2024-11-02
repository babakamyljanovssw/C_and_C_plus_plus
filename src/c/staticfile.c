#include<stdio.h>
#include<stdlib.h>
int count = 1;
int f()
{
    static int count = 1;
    for (int i = 0; i < count; i++)
    {
        printf("*");
    }
    printf("\n");
    count++;
    return 0;
}
int main()
{
    f();
    f();
    f();
    return 0;
}