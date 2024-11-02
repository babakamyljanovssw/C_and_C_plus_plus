#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack;
struct Stack* CreateStack();
void InfixToPostfix(char c[],int length);
int IsEmpty(struct Stack* S);
void Push(struct Stack* S, char c);
char Top(struct Stack* S);
void Pop(struct Stack* S);
int IsOperator(char c);
int HasLowerPriority(char op1,char op2);
int GetOperatorWeight(char op);

struct Stack
{
    char data;
    struct Stack* next;
};
struct Stack* CreateStack()
{
    struct Stack* S = malloc(sizeof(struct Stack));
    if (S == NULL) printf("Out of space!");
    else
    {
        S->next = NULL;
        return S;
    }
}
int IsOperator(char c)
{
    if ( (c=='*') || (c=='+') || (c=='/') || (c=='-') ) return 1;
    else return 0;
}
int IsEmpty(struct Stack* S)
{
    return S->next == NULL;
}
void Push(struct Stack* S, char c)
{
    struct Stack* TmpCell = (struct Stack*) malloc (sizeof(struct Stack));
    if(TmpCell == NULL) printf("Out of space!\n");
    else
    {
        TmpCell->data = c;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }   
}
char Top(struct Stack* S)
{
    if (!IsEmpty(S)) return S->next->data;
}
void Pop(struct Stack* S)
{
    if (!IsEmpty(S))
    {
        struct Stack* TmpCell = S->next;
        S->next = TmpCell->next;
        free(TmpCell);
    }
}
int GetOperatorWeight(char op)
{
    int weight = -1;
    switch (op)
    {
    case '+':
        weight = 1;
        break;
    case '-':
        weight = 1;
        break;
    case '*':
        weight = 2;
        break;
    case '/':
        weight = 2;
        break;
    default:
        break;
    }
    return weight;
}
int HasLowerPriority(char op1,char op2)
{
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);
    if (op1Weight == op2Weight) return 0;
    if (op1Weight < op2Weight) return 1;
    else return 0;
}
int IsOperand(char c)
{
    if (c >= '0' && c <= '9') return 1;
    if (c >= 'a' && c <= 'z') return 1;
    if (c >= 'A' && c <= 'Z') return 1;
    return 0;
}
void InfixToPostfix(char c[],int length)
{
    char string[50];
    int k = 0;
    struct Stack* S = CreateStack();
    for (int i = 0; i < length-1; i++)
    {
        if( c[i] == ' ') continue;

        else if(IsOperator(c[i]))
        {
            while ( (!IsEmpty(S)) && (Top(S) != '(') && (!HasLowerPriority(Top(S),c[i])) )
            {
                string[k++] = Top(S);
                Pop(S);
            }
            Push(S,c[i]);
        }
        else if (IsOperand(c[i]))
        {
            string[k++] = c[i];
        }
        else if (c[i] == '(')
        {
            Push(S,c[i]);
        }
        else if (c[i] == ')')
        {
            while ( !IsEmpty(S) && Top(S) != '(' )
            {
                string[k++] = Top(S);
                Pop(S);
            }
            Pop(S);
        }      
    }
    while (!IsEmpty(S))
    {
        string[k++] = Top(S);
        Pop(S);
    }
    string[k] = '\0';
    puts(string);
    return;
}
int main()
{
    char c[50];
    printf("Enter infix expression:\n");
    fgets(c,sizeof(c),stdin);
    InfixToPostfix(c,strlen(c));
    return 0;
}