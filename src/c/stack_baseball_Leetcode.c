/*
  Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.

1 <= ops.length <= 1000
ops[i] is "C", "D", "+", or a string representing an integer in the range [-3 * 104, 3 * 104].
For operation "+", there will always be at least two previous scores on the record.
For operations "C" and "D", there will always be at least one previous score on the record.

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
    int score;
    struct Stack *next;
};
struct Stack* CreateStack();
void Push(int X,struct Stack *S);
int Top(struct Stack *S);
void Pop(struct Stack *S);
int IsEmpty(struct Stack *S);
int calPoints(char **ops, int opsSize);

struct Stack* CreateStack()
{
    struct Stack *S = (struct Stack*)malloc(sizeof(struct Stack));
    if (S != NULL)
    {
        S->next = NULL;
        return S;
    }
    else
    {
        printf("Out of space!\n");
        return NULL;
    }
}
void Push(int X,struct Stack *S)
{
    struct Stack *temp = (struct Stack*)malloc(sizeof(struct Stack));
    if(temp != NULL)
    {
        temp->score = X;
        temp->next = S->next;
        S->next = temp;
    }
    else
    {
        printf("Out of space!\n");
        return;
    }
}
int Top(struct Stack *S)
{
    if(!IsEmpty(S)) 
    return S->next->score;
    else{
        printf("Empty stack!\n");
        return 0;
    }
}
void Pop(struct Stack *S)
{
    if(!IsEmpty(S))
    {
        struct Stack *temp = S->next;
        S->next = temp->next;
        free(temp);
        return;  
    }
    else
    {
        printf("Empty stack!\n");
        return ;
    }
}
void FreeStack(struct Stack *S)
{
    while(!IsEmpty(S))
    Pop(S);
    free(S);
}
int IsEmpty(struct Stack *S)
{
    return S->next == NULL;
}
int calPoints(char **ops, int opsSize)
{
    struct Stack *S = CreateStack();
    int i,j,a=0,b,k = 0;
    for ( i = 0; i < opsSize; i++)
    {
        a = 0;
        k = 0;
        if( ops[i][0] == '-' || (ops[i][0] >= '0' && ops[i][0] <= '9') )
        {
            for ( j = 0; j < strlen(ops[i]); j++)
            {
                if (ops[i][j] == '-')
                {
                    ++k;
                }
                else
                {
                    a = (a * 10) + (ops[i][j] - '0');
                } 
            }
            if(k == 1)
            {
                Push(-a,S);
            }
            else
            {
                Push(a,S);
            }
        }
        else if(ops[i][0] == '+')
        {
            a = Top(S);
            Pop(S);
            b = Top(S);
            Push(a,S);
            Push(a + b,S);
        }
        else if (ops[i][0] == 'C')
        {
            Pop(S);
        }
        else if (ops[i][0] == 'D')
        {
            a = Top(S);
            Push(2 * a,S);
        }
    }
    b = 0;
    while (!IsEmpty(S))
    {
        a = Top(S);
        Pop(S);
        b += a;
    }
    FreeStack(S);
    return b;
}
int main()
{
    int i,j,m,n,length;
    char c[100];
    m = 1000;
    n = 30000;

    char **ops;
    ops = (char**)malloc(m*sizeof(char*));
    for ( i = 0; i < m; i++)
    {
        ops[i] = (char*)malloc(n*sizeof(char));
    }
    scanf("%d",&length);

    for ( i = 0; i < length; i++)
    {
        scanf("%s",&c);
        for ( j = 0; j < strlen(c); j++)
        {
            ops[i][j] = c[j];
        }
        ops[i][j] = '\0';
    }

    int result = calPoints(ops,length);
    printf("%d\n",result);
    for ( i = 0; i < m; i++)
    {
        free(ops[i]);
    }
    free(ops);
    return 0;
}