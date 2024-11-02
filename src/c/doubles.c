#include<stdio.h>
#include<stdlib.h>
int main()
{
    int count = 0, a[20];
    scanf("%d", &a[0]);
    while(a[0]!=-1)
    {
        int k = 1;
        for ( ; a[k-1] != 0; k++)
        {
            scanf("%d", &a[k]);
        }
        count = 0;
        for (int i = 0; i < k-1; i++)
        {
            for (int j = i+1; j < k; j++)
            {
                if( (a[i]*2 == a[j]) || (a[j]*2 == a[i]) )
                count++;
            }
        }
        printf("%d\n", count);
        scanf("%d", &a[0]);
    }
    return 0;
}