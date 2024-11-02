#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x)
{
    if (top == MAX_SIZE-1)
    {
        printf("Error: stack overflow\n");
        return;
    }
    A[++top] = x;
}
void Pop()
{
    if (top == -1)
    {
        printf("Error: No element to pop\n");
        return;
    }
    top--;
}
int Top()
{
    return A[top];
}
int IsEmpty()
{
    if (top == -1)
    return 1;
    else 0;
}
void print()
{
    int i;
    printf("Stack: ");
    for ( i = 0; i <= top; i++)
        printf("%d ",A[i]);
    printf("\n");
}
int main()
{
    Push(2);print();
    Push(5);print();
    Push(10);print();
    Pop();print();
    Push(12);print(0);
    return 0;
}