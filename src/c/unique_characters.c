// leetcode interview question: unique characters in string
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

bool isUnique(char *str)
{
    int i;
    bool *chars = (bool*)malloc(26*sizeof(bool));
    for( i = 0; i < 26; i++) 
        chars[i] = true;

    for( i = 0; i < strlen(str); i++){
        if(chars[str[i] - 'a'] == true){
            chars[str[i] - 'a'] = false;
        }
        else{
            return false;
        }
    }
    return true;
}
int main()
{
    char *s = "abc";
    if(isUnique(s)) printf("true");
    else printf("false");
    return 0;
}