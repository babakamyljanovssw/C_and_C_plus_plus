#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* strcopy(char *dp, const char *sp)
{
    while (*sp!='\0')
    {
        *dp++ = *sp++;
    }
    *dp = '\0';
    return dp;
}
int main()
{
    const char *s2 = "Hello World";
    char *s1;
    s1 = (char*)malloc(sizeof(char)*(strlen(s2)+1));
    if (s1 = NULL)
    {
        printf("No memory!");
        exit -1;
    }
    else
    {
        strcopy(s1,s2);
        printf("%s\n",s1);
        free(s1);
        return 0;
    }
}