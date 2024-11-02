#include<stdio.h>
typedef int (*FuncPtr)(double f1 ,double f2);
int Func(double f1, double f2)
{
    printf("f1 = %f\nf2 = %f\n",f1,f2);
    return 0;
}
int main()
{
    FuncPtr pf;
    pf = Func;
    pf(10.0,20.0);
    return 0;
}