/*
Input: s = "abcabcababcc"
Output: true
Explanation:
"" -> "abc" -> "abcabc" -> "abcabcabc" -> "abcabcababcc"

Input: s = "cababc"
Output: false
Explanation: It is impossible to get "cababc" using the operation.

*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
struct Stack
{
    char data;
    struct Stack *next;
};
struct Stack* CreateStack();
void Push(char c,struct Stack *S);
char Top(struct Stack *S);
int IsEmpty(struct Stack *S);
void Pop(struct Stack *S);

struct Stack* CreateStack()
{
    struct Stack *S = malloc(sizeof(struct Stack));
    if(S != NULL)
    {
        S->next = NULL;
        return S;
    }
    else
    {
        printf("No space!\n");
        return NULL;
    }
}
void Push(char c,struct Stack *S)
{
    struct Stack *temp = (struct Stack*)malloc(sizeof(struct Stack));
    if(temp != NULL)
    {
        temp->data = c;
        temp->next = S->next;
        S->next = temp;
    }
    else
    {
        printf("No space!\n");
        return;
    }
}
char Top(struct Stack *S)
{
    if( !IsEmpty(S) ) 
    return S->next->data;
    else 
    return '\0';
}
int IsEmpty(struct Stack *S)
{
    return S->next == NULL;
}
void Pop(struct Stack *S)
{
    if(!IsEmpty(S))
    {
        struct Stack *temp;
        temp = S->next;
        S->next = temp->next;
        free(temp);
    }
    else return;
}
bool isValid(char *s)
{
    struct Stack *stack;
    stack = CreateStack();
    int length = strlen(s);
    char c1,c2;
    if((length % 3) != 0) return false;

    for(int i = 0; i < length; i++)
    {
        if (s[i] == 'a' || s[i] == 'b')
        {
            Push(s[i],stack);
        }
        else
        {
            c1 = Top(stack);
            Pop(stack);
            c2 = Top(stack);
            Pop(stack);
            if(c1 != 'b' && c2 != 'a') return false;
        } 
    }
    return true;
}
int main()
{
    char s[100];
    scanf("%s",s);

    if(isValid(s)) printf("true!\n");
    else printf("false!\n");
    return 0;
}