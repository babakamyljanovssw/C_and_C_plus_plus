/*
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

Follow up: The O(n^2) is trivial, could you come up with the O(n logn) or the O(n) solution?

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
struct Stack
{
    int data;
    struct Stack *next;
};

struct Stack* CreateStack();
void Push(int n,struct Stack *S);
int Top(struct Stack *S);
int IsEmpty(struct Stack *S);
void Pop(struct Stack *S);
void Free_Stack(struct Stack* S);
bool find132pattern(int* nums, int numsSize);

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
void Push(int n,struct Stack *S)
{
    struct Stack *temp = (struct Stack*)malloc(sizeof(struct Stack));
    if(temp != NULL)
    {
        temp->data = n;
        temp->next = S->next;
        S->next = temp;
    }
    else
    {
        printf("No space!\n");
        return;
    }
}
void Pop(struct Stack *S)
{
    if(IsEmpty(S))
    {
        printf("Empty Stack!\n");
        return;
    }
    else
    {
        struct Stack *temp;
        temp = S->next;
        S->next = temp->next;
        free(temp);
    }
}
int Top(struct Stack *S)
{
    if( !IsEmpty(S) ) return S->next->data;
    else return 0;
}
int IsEmpty(struct Stack *S)
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
bool find132pattern(int* nums, int numsSize)
{
    struct Stack *S;
    S = CreateStack();
    if(numsSize < 3) return false;
    int last = INT_MIN;
    for (int i = numsSize-1; i >= 0; i--)
    {
        if( nums[i] < last) return true;
        while ( !IsEmpty(S) && Top(S) < nums[i])
        {
            last = Top(S);
            Pop(S);
        }
        Push(nums[i],S);
    }
    Free_Stack(S);
    return false;   
}
int main()
{
    int n;
    bool pattern;
    int arr[20];
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    scanf("%d",&arr[i]);
    pattern = find132pattern(arr,n);
    if( pattern ) printf("true");
    else printf("false");
    return 0;
}