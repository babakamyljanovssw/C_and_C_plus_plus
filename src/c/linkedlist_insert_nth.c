#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
// insert node to linked list at n th position
void insert(struct node** head,int data,int n)
{
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = data;
    temp1->next = NULL;
    if (n == 1)
    {
        temp1->next = *head;
        *head = temp1;
        return;
    }
    struct node* temp2 = *head;
    for (int i = 0; i < n-2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void print(struct node** head)
{
    struct node* temp = *head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct node* head;
    head = NULL;
    insert(&head,2,1); // list 2
    insert(&head,3,2); // list 2 3
    insert(&head,4,1); // list 4 2 3
    insert(&head,5,2); // list 4 5 2 3
    insert(&head,8,3); // list 4 5 8 2 3
    insert(&head,7,6); // list 4 5 8 2 3 7
    insert(&head,9,6); // list 4 5 8 2 3 9 7
    print(&head);
}
