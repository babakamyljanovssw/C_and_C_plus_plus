#include<stdio.h>
#include<stdlib.h>
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(int X, Stack S);
int Top(Stack S);
void Pop(Stack S);
struct Node
{
    int Element;
    PtrToNode Next;
};
int IsEmpty(Stack S)
{
    return S->Next == NULL;
}
Stack CreateStack(void)
{
    Stack S;
    S = (struct Node*)malloc(sizeof(struct Node));
    if(S == NULL)
    {
        printf("Out of space!");
    }
    //MakeEmpty(S);
    S->Next = NULL;
    return S;
}
void MakeEmpty(Stack S)
{
    if(S == NULL)
    {
        printf("Must use Create stack first!\n");
        return;
    }
    else
        while(!IsEmpty(S)) 
        Pop(S);
}
void Push(int X, Stack S)
{
    PtrToNode TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell==NULL)
    {
        printf("Out of space!\n");
        return;
    }
    else
    {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}
int Top(Stack S)
{
    if(!IsEmpty(S)) return S->Next->Element;
    printf("Error! Empty Stack!\n");
    return 0; // Return value used to avoid warning
}
void Pop(Stack S)
{
    PtrToNode FirstCell;
    if(IsEmpty(S))
    {
        printf("Error! Empty stack!\n");
        return;
    }
    else
    {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}
void DisposeStack(Stack S)
{
    if (S!=NULL)
    {
        free(S);
    }
    
}
void print(Stack S)
{
    PtrToNode TempCell;
    TempCell = S->Next;
    while(TempCell!=NULL)
    {
        printf("%d ", TempCell->Element);
        TempCell = TempCell->Next;
    }
}
int main()
{
    Stack S;
    S = CreateStack();
    Push(5,S);
    Push(6,S);
    Push(8,S);
    Push(7,S);
    Pop(S);
    printf("%d\n",Top(S));
    Push(15,S);
    print(S);
    //MakeEmpty(S);
    DisposeStack(S);
    return 0;
}
