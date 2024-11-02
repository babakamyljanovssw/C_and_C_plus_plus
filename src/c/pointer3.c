#include<stdio.h>
#include<string.h>
void print(char* c1)
{
    int i = 0;
    while (c1[i] != '\0') // *(c1+i) is also can use; while(*c1 != 0){ printf(*c1), c1++} this also works
    {
        printf("%c",c1[i]);
        i++;
    }
    
}
int main()
{
    char c[20]; // no 0 termination. we can implement also c[20] = "JOHN"; here automatically stores 0 termination
    c[0]='J';
    c[1]='O';
    c[2]='H';
    c[3]='N';
    c[4]='\0';
    int length = strlen(c);
    //printf("%s\n",c);
    //printf("Length = %d\n",length);
    char c1[20] = "Hello";
    print(c1);
    return 0;
}