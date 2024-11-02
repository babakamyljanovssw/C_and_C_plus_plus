#include<stdio.h>
#include<stdlib.h>

void func()
{
    static int a = 10;
    int b = 10;
    printf("a = %d b = %d\n",a,b);
    a++;
    b++;
    printf("a = %d b = %d\n",a,b);
}
int main()
{
    func();
    func();
    return 0;
}