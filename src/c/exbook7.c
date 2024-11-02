#include<stdio.h>
const char *monthstr(int month)
{
    static const char *montharray[12] = { "January", "February", "March", "April", "May", "June", "July", "August",
                                    "September", "October", "November", "December" };
    return (month<0 || month>12) ? NULL : montharray[month-1];
}
int main()
{
    int i;
    for ( i = 1; i <= 12; i++)
    {
        printf("%s\n",monthstr(i));
    }
    return 0;
}