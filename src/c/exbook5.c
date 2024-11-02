#include<stdio.h>
#include<stdlib.h>
void swap(int **p, int **q)
{
    int *temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
int main()
{
    int a = 5, b = 6;
    int *p = &a, *q = &b;
    int **pp = &p, **qq = &q;
    printf("Before swap - a = %d, b = %d\n",*p,*q);
    swap(pp,qq);
    printf("After swap - a = %d, b = %d\n",*p,*q);
    return 0;
}