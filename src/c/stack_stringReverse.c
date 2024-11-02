#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define EmptyTOS (-1)

struct stack* CreateStack(int maxElements);
void MakeEmpty(struct stack* S);
int IsEmptyStack(struct stack* S);
void Push(char c,struct stack* S);
void Reverse(char c[],int n,struct stack* S);
char TopAndPop(struct stack* S);
int IsFull(struct stack* S);
struct stack
{
    int Capacity;
    char *A;
    int top;
};
struct stack* CreateStack(int maxElements)
{
    struct stack* S;
    S = malloc(sizeof(struct stack));
    if(S==NULL) printf("Out of space!\n");
    S->A = malloc(sizeof(char)*sizeof(maxElements));
    if(S->A == NULL) printf("Out of space!\n");
    S->Capacity = maxElements;
    MakeEmpty(S);
    return S;
}
void MakeEmpty(struct stack* S)
{
    S->top = EmptyTOS;
}
int IsEmptyStack(struct stack* S)
{
    return S->top == EmptyTOS;
}
int IsFull(struct stack* S)
{
    return S->top > S->Capacity;
}
void Push(char c,struct stack* S)
{
    if(IsFull(S))
    {
        printf("Error:Full stack!\n");
        return;
    }
    else
    S->A[++S->top] = c;
}
char TopAndPop(struct stack* S)
{
    if(!IsEmptyStack(S)) return S->A[S->top--];
    printf("Error: Empty stack!\n");
    return 0;
}
void Reverse(char c[],int n,struct stack* S)
{
    int i;
    for ( i = 0; i < n-1; i++)
    {
        Push(c[i],S);
    }
    for ( i = 0; i < n-1; i++)
    {
        c[i] = TopAndPop(S);
    }
}
int main()
{
    struct stack* S;
    S = CreateStack(101);
    char c[51];
    printf("Enter a string:");
    fgets(c,sizeof(c),stdin);
    Reverse(c,strlen(c),S);
    printf("%s",c);
    return 0;
}