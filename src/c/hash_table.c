#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned int hash(const char *key)
{
    int index = 0;
    while ( *key != '\0' ) 
    
        index = ( index << 5 ) + *key++;
    
    return index;
}
int main()
{
    char *key = "name";
    puts(key);
    unsigned int index = hash(key);
    printf("%u\n",index);
    return 0;
}