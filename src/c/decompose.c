#include<stdio.h>
#include<limits.h>
double decompose(double x, double *iptr)
{
    int i = (int)x;
    *iptr = (double)i;
    return x-i;
}
int main()
{
    double x, fracptr, iptr;
    printf("Please enter floating point number smaller than %d\n", INT_MAX);
    scanf("%lf",&x);
    fracptr = decompose(x,&iptr);
    printf("The integral part of %f is %.f, the fractional part is %f\n",x,iptr,fracptr);
    return 0;
}