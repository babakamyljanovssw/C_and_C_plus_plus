#include<stdio.h>
#define N 6 
int main()
{
    char word[N];
    char* p;
    p = &word[0];
    printf("Enter the word: ");
    for (int i = 0; i < N; i++)
    {
        *p = getchar(); // *p++ = getchar();
        p++;
    }
    for (int i = 0; i < N; i++)
    {
        p--;
        putchar(*p); // putchar(*--p);
    }
    return 0;
}