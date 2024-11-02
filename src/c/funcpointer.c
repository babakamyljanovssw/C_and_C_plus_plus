#include<stdio.h>
int Add(int a, int b)
{
    return a+b;
}
void PrintHello(char *c)
{
    printf("Hello %s\n",c);
}
int main()
{
    int c;
    int (*p)(int,int);
    p = &Add;       // p = Add;
    c = (*p)(2,3); // c= p(2,3);
    printf("%d\n",c);
    
    void (*ptr)(char*);
    ptr = PrintHello;
    ptr("Tom");
    return 0;
}