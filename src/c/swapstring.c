#include<stdio.h>
int main()
{
    char s1[100], s2[100] = "Hello World";
    char *s1p, *s2p;
    s1p = &s1[0];
    s2p = &s2[0];
    while (*s2p != '\0')
    {
        *s1p++ = *s2p++;
    }
    *s1p = '\0';
    printf("%s", s1);
    return 0;
}