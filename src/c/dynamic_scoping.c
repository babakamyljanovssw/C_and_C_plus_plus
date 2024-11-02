#include<stdio.h>
#include<stdlib.h>

int func1(int);
int func2(int);
int a = 5;
int main()
{
    int a = 10;
    a = func1(a);
    printf("%d",a);
}
int func1(int b)
{
    b = b + 10;
    b = func2(b);
    return b;
}
int func2(int b)
{
    int c = a + b;
    return c;
}