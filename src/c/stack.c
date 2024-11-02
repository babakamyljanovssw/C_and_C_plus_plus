#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

int isEmpty()
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

void push(int x)
{
    printf("push %d to stack\n", x);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void pop()
{
    printf("pop stack\n");
    struct node *temp;
    if (isEmpty())
    {
        printf("Empty stack!\n");
        return;
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int top()
{
    printf("top stack\n");
    if (isEmpty())
    {
        printf("Empty stack!\n");
        return 0;
    }
    return head->data;
}

void print()
{
    printf("stack is: ");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    push(2);
    print();
    push(5);
    print();
    push(10);
    print();
    pop();
    print();
    push(8);
    print();
    printf("%d\n", top());
    return 0;
}