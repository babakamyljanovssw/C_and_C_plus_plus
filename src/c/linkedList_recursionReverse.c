#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head;
void insert(struct node** head, int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    struct node* temp2 = *head;
    while (temp2->next != NULL) temp2 = temp2->next;
    temp2->next = temp;
}
struct node* Reverse(struct node* head)
{
    if (head->next == NULL) return head;
    struct node* temp = Reverse(head->next);
    struct node* prevnode = head->next; // just 1 line p->next->next = p;
    prevnode->next = head;
    head->next=NULL;
    return temp;
}
void print(struct node** head)
{
    struct node* temp = *head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct node* head;
    head = NULL;
    insert(&head,6); // list 6
    insert(&head,5); // list 5 6
    insert(&head,2); // list 2 5 6
    insert(&head,9); // list 9 2 5 6
    head = Reverse(head);
    print(&head);
    return 0;
}