#include<stdio.h>
#include<stdlib.h>
int k;
// recursive counting
int staircase(int n)
{
    int i,total = 0;
    if (n == 0) return 1;
    for ( i = 1; i <= k; i++)
    if(n-i >= 0) total += staircase(n-i);
    return total;
}
// dynamic programming bottom up counting
int bottom_up(int n)
{
    int i,j,total;
    int *array = (int*)malloc(n+1*sizeof(int));
    array[0] = 1;
    for ( i = 1; i < n+1; i++)
    {
        total = 0;
        for ( j = 1; j <= k; j++)
            if(i-j >= 0) total += array[i-j];
        array[i] = total;
    }
    return array[n];
}
int main()
{
    int n;
    scanf("%d",&k);
    scanf("%d",&n);
    //printf("%d\n",staircase(n));
    printf("%d\n",bottom_up(n));
    return 0;
}