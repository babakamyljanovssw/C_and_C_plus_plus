#include<stdio.h>
#define DAY 7
const char *day(int n)
{
    static const char *days[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    return (n<0 || n>6) ? NULL : days[n];   
}
int main()
{
    const char *p;
    for (int i = 0; i < DAY; i++)
    {
        p = day(i);
        printf("%s\n",p);
    }
    return 0;
}