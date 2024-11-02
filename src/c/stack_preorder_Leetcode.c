/*
Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
Input: "9,#,#,1"
Output: false
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
struct Stack
{
    int data;
    struct Stack *next;
};
struct Stack* CreateStack();
void Push(int c,struct Stack *S);
int Top(struct Stack *S);
int IsEmpty(struct Stack *S);
void Pop(struct Stack *S);
void FreeStack(struct Stack *S);
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
void Push(int c,struct Stack *S)
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
int Top(struct Stack *S)
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
void FreeStack(struct Stack *S)
{
    while(!IsEmpty(S))
    Pop(S);
    free(S);
}
bool isValidSerialization(char * preorder)
{
    struct Stack *S = CreateStack();
    int i,a,length;
    length = strlen(preorder);
    a = 0;
    if(length == 1 && preorder[0] == '#') return true;
    if(length == 1 && preorder[0] >= '0' && preorder[0] <= '9') return false;
    for( i = length - 1; i >= 0; i-- )
    {
        if(preorder[i] == ',') continue;
        else if (preorder[i] >= '0' && preorder[i] <= '9')
        {
            while (preorder[i] != ',' && i >= 0)
            {
                a = (a * 10) + (preorder[i] - 48) ;
                i--;
            }
            if(IsEmpty(S)){
                return false;
            }
            Pop(S);

            if(IsEmpty(S)){
                return false;
            }
            Pop(S);
            
            Push(a,S);
            a = 0;
        }
        else if (preorder[i] == '#')
        {
            Push((int)preorder[i],S);
        }
    }
    a = Top(S);
    Pop(S);
    if(a != 35 && IsEmpty(S)) 
    return true;
    else
    return false;
    FreeStack(S);
}
int main()
{
    char s[100];
    scanf("%s",s);

    if(isValidSerialization(s)) printf("true!\n");
    else printf("false!\n");
    return 0;
}