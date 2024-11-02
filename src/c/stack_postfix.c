#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack;
struct Stack* CreateStack();
void Evaluate_Postfix(struct Stack* S,char c[],int length);
void Push(struct Stack* S,int num);
int TopandPop(struct Stack* S);
int Perform(char c, int Op1, int Op2);
int IsEmpty(struct Stack* S);

struct Stack
{
    int data;
    struct Stack* next;
};
int IsEmpty(struct Stack* S)
{
    return S->next == NULL;
}
struct Stack* CreateStack()
{
    struct Stack* S = malloc(sizeof(struct Stack));
    if(S == NULL) printf("Out of space!");
    else
    {
        S->next = NULL;
        return S;
    }
}
void Push(struct Stack* S,int num)
{
    struct Stack* TmpCell = (struct Stack*)malloc(sizeof(struct Stack));
    if (TmpCell == NULL)
    {
        printf("Out of space!\n");
        return;
    }
    else
    {
        TmpCell->data = num;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }
}
int TopandPop(struct Stack* S)
{
    if (IsEmpty(S))
    {
        printf("Empty stack! No element to top and pop!\n");
    }
    else
    {
        struct Stack* TmpCell = S->next;
        int num = TmpCell->data;
        S->next = TmpCell->next;
        free(TmpCell);
        return num;
    }
}
int Perform(char c, int Op1, int Op2)
{
    if(c == '+') return (Op1 + Op2);
    if(c == '-') return (Op1 - Op2);
    if(c == '*') return (Op1 * Op2);
    if(c == '/') return (Op1 / Op2);
}
void Evaluate_Postfix(struct Stack* S,char c[],int length)
{
    int Op1, Op2, result,k,i,num = 0;
    for ( i = 0; i < length-1; i++)
    {
        if( ( (c[i] >= '0') && (c[i] <= '9')) )
        {
            k = (int)c[i];
            k = k - 48;
            num = num * 10 + k;
        }
        else if( (c[i] == ' ') && ((c[i-1] != '*') && (c[i-1] != '+') && (c[i-1] != '-') && (c[i-1] != '/')) )
        {
            Push(S,num);
            num = 0;
        }
        else if( (c[i] == '*') || (c[i] == '+') || (c[i] == '-') || (c[i] == '/') )
        {
            Op2 = TopandPop(S);
            Op1 = TopandPop(S);
            result = Perform(c[i],Op1,Op2);
            Push(S,result);
        }
    }
    result = TopandPop(S);
    printf("%d\n",result);
    return;
}
int main()
{
    struct Stack* S = CreateStack();
    char c[50];
    printf("Enter the postfix expression:\n");
    fgets(c,sizeof(c),stdin);
    Evaluate_Postfix(S,c,strlen(c));
    return 0;
}