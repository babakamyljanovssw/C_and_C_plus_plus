#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack;
void Push(char b,struct stack* S);
void Pop(struct stack* S);
char Top(struct stack* S);
int IsEmpty(struct stack* S);
int IsBalance(char *c,int n,struct stack* S);
int IsSymbol(char c);
struct stack
{
    char data;
    struct stack* next;
};
struct stack* CreateStack()
{
    struct stack* S = malloc(sizeof(struct stack));
    if (S==NULL)
    {
        printf("Out of space!");
    }
    S->next = NULL;
    return S;
}
void Push(char b,struct stack* S)
{
    struct stack* TmpCell;
    TmpCell = (struct stack*)malloc(sizeof(struct stack));
    if (TmpCell==NULL)
    {
        printf("Out of space!\n");
        return;
    }
    else
    {
        TmpCell->data = b;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }
}
void Pop(struct stack* S)
{
    struct stack* TmpCell;
    if (IsEmpty(S))
    {
        printf("Error: Empty stack\n");
        return;
    }
    else
    {
        TmpCell = S->next;
        S->next = S->next->next;
        free(TmpCell);
    }
}
char Top(struct stack* S)
{
    if (IsEmpty(S))
    {
        printf("Error: Empty stack!]n");
        return 0;
    }
    return S->next->data;
}
int IsEmpty(struct stack* S)
{
    return S->next == NULL;
}
int IsSymbol(char c)
{
    if(c!='(' && c!=')' && c!='[' && c!=']' && c!='{' && c!='}') return 1;
    return 0;
}
int IsBalance(char c[],int n,struct stack* S)
{
    for (int i = 0; i < n-1; i++)
    {
        if(IsSymbol(c[i])) continue;
        if (c[i]=='(' || c[i]=='{' || c[i]=='[')
        {
            Push(c[i],S);
        }
        else if(IsEmpty(S)) return 0;
        else if (c[i]==')' || c[i]=='}' || c[i]==']')
        {
            if((Top(S) == '(' && c[i] == ')') || (Top(S) == '{' && c[i] == '}') || (Top(S) == '[' && c[i] == ']') ) Pop(S);
            else return 0;
        }
        else return 0;
    }
    if(!IsEmpty(S)) return 0;
    else return 1;
}
int main()
{
    struct stack *S;
    S = CreateStack();
    char c[1000];
    printf("Enter the symbols:\n");
    fgets(c,sizeof(c),stdin);
    if(IsBalance(c,strlen(c),S)) printf("Balanced!\n");
    else printf("Error: Is not balanced!\n");
    return 0;
}