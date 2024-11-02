#include <stdio.h>
#include <string.h>
char s[1003][20];
int main()
{
    int a[1000], n, i, j, max, t;
    while(scanf("%d ",&n)!=EOF)
    {
        if(n==0) break;
        max = 0;
        for(i = 0; i < n; i++)
        {
            a[i]=0;
            gets(s[i]);
            for(j = 0; j <= i; j++)
            {
                if(strcmp(s[j],s[i])==0)
                    a[i]++;
            }
        }
        for(i = 0; i < n; i++)
        {
            if(max<a[i])
            {
                max = a[i];
                t = i;
            }
        }
        printf("%s\n",s[t]);
    }
    return 0;
}