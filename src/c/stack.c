#include<stdio.h>
#include<stdlib.h>
void Push(int x);
void Pop();
int Top();
int IsEmpty();
void print();
struct node
{
    int data;
    struct node* next;
};
struct node* top = NULL;

void Push(int x)
{
    struct node* temp =(struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}
void Pop()
{
    struct node* temp;
    if(IsEmpty())
    {
        printf("Empty stack!\n");
        return;
    }
    else
    {
        temp = top;
        top = top->next;
        free(temp);
    }
}
int Top()
{
    if(IsEmpty())
    {
        printf("Empty stack!\n");
        return 0;
    }
    return top->data;
}
int IsEmpty()
{
    if(top == NULL) return 1;
    else return 0;
}
void print()
{
    struct node *temp = top;
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    Push(2);
    Push(5);
    Push(10);
    print();
    Pop();
    Push(8);
    print();
    printf("%d\n",Top());
    system("pause");
    return 0;
}