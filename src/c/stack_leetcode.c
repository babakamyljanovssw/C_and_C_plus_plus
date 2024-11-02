/*
We are given hours, a list of the number of hours worked per day for a given employee.

A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.

Return the length of the longest well-performing interval.

*/
#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int hr;
    struct Stack *next;
};
struct Stack* CreateStack();
void Push(int hr,struct Stack* S);
void Pop(struct Stack* S);
int Top(struct Stack* S);
int IsEmpty(struct Stack* S);
void Free_Stack(struct Stack* S);
int longestWPI(int* hours, int hoursSize);

struct Stack* CreateStack()
{
    struct Stack* S = malloc(sizeof(struct Stack));
    if(S != NULL)
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
void Push(int hr,struct Stack* S)
{
    struct Stack* temp;
    temp = (struct Stack*)malloc(sizeof(struct Stack));
    if (temp == NULL)
    {
        printf("Out of space!\n");
        return;
    }
    else
    {
        temp->hr = hr;
        temp->next = S->next;
        S->next = temp;
    }
}
void Pop(struct Stack* S)
{
    struct Stack* temp;
    if (IsEmpty(S))
    {
        printf("Error: Empty stack\n");
        return;
    }
    else
    {
        temp = S->next;
        S->next = S->next->next;
        free(temp);
    }
}
int Top(struct Stack* S)
{
    if (IsEmpty(S))
    {
        return 0; // returns 0 if stack is empty
    }
    return S->next->hr;
}
int IsEmpty(struct Stack* S)
{
    return S->next == NULL;
}
void Free_Stack(struct Stack* S)
{
    while (!IsEmpty(S))
    {
        Pop(S);
    }
    free(S);
}
int longestWPI(int* hours, int hoursSize)
{
    struct Stack *S;
    S = CreateStack();

    int i,j,tiring = 0,nontiring = 0,max;
    for ( i = 0; i < hoursSize; i++)
    {
        for ( j = i; j < hoursSize; j++)
        {
            if(hours[j] > 8) 
            ++tiring;
            else 
            ++nontiring;
            if( tiring > nontiring && tiring + nontiring > Top(S) ) 
            Push(tiring + nontiring,S);
        }
        if( tiring > nontiring && tiring + nontiring > Top(S) ) Push(tiring + nontiring,S);
        tiring = 0;
        nontiring = 0;
    }
    max = Top(S);
    Free_Stack(S);
    return max;
}
int main()
{
    int n;
    int arr[20];
    printf("Enter the number of days: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    scanf("%d",&arr[i]);
    int max = longestWPI(arr,n);
    printf("The longest well performing interval is: %d",max);
    return 0;
}