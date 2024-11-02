#include<stdio.h>
#include<stdlib.h>
struct minStack
{
    int data;
    int min;
    struct minStack *next;
};
struct minStack* minStackCreate()
{
    struct minStack* S = (struct minStack*)malloc(sizeof(struct minStack));
    if(S == NULL)
    {
        printf("No space!\n");
        return NULL;
    }
    else
    {
        S->next = 0;
        S->min = 2147483647; // INT_MAX value
        return S;
    }
}
void minStackPush(struct minStack *S,int X)
{
    struct minStack *temp = (struct minStack*)malloc(sizeof(struct minStack));
    if(temp == NULL)
    {
        printf("No space!\n");
        return;
    }
    else
    {
        temp->data = X;
        temp->next = S->next;
        if(X < S->min) temp->min = S->min = X;
        else temp->min = S->min;
        S->next = temp;
    }
}
void minStackPop(struct minStack *S)
{
    if(S->next != NULL) // if stack is not empty
    {
        struct minStack *temp = S->next;
        S->next = temp->next;
        free(temp);
        S->min = S->next->min;
        return;
    }
    else
    {
        printf("Stack is empty!\n");
        return;
    }
}
int minStackTop(struct minStack *S)
{
    if(S->next != NULL)
    {
        return S->next->data;
    }
    else
    {
        printf("Stack is empty!\n");
        return 0;
    }
}
int minStackGetMin(struct minStack *S)
{
    if(S->next != NULL)
    {
        return S->min;
    }
    else
    {
        printf("Stack is empty!\n");
        return 0;
    }
}
void minStackFree(struct minStack *S)
{
    if(S == NULL)
    {
        printf("Create Stack first!\n");
        return;
    }
    else while (S->next != NULL)
    {
        minStackPop(S);
    }
    free(S);
}
int main()
{
    int min,top;
    struct minStack *S;
    S = minStackCreate();
    minStackPush(S,-2);
    minStackPush(S,0);
    minStackPush(S,-3);
    min = minStackGetMin(S);
    printf("min: %d\n",min);
    minStackPop(S);
    top = minStackTop(S);
    printf("top: %d\n",top);
    min = minStackGetMin(S);
    printf("min: %d\n",min);
    return 0;
}