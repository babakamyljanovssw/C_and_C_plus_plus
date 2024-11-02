#include<stdio.h>
#include<stdlib.h>
int main()
{
    int N, a, b;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int new1 = 0, new2 = 0, new3 = 0, sum = 0;
        scanf("%d%d", &a, &b);

        for (a; a != 0; a/=10)
        {
            new1 = (new1 * 10) + (a % 10);
        }
        for (b; b != 0; b/=10)
        {
            new2 = (new2 * 10) + (b%10);
        }
        sum = new1 + new2;
        
        for (sum; sum != 0; sum/=10)
        {
            new3 = (new3 * 10) + (sum % 10);
        }
        printf("%d\n", new3);   
    }
    return 0;
}