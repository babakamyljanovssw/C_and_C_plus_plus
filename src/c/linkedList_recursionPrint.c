#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
// insert node at beginning
/*void insert(struct node** head, int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    temp->next = *head;
    *head = temp;
}*/

// insert node at the end
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
void Reverseprint(struct node* head)
{
    if(head == NULL) return;
    Reverseprint(head->next);
    printf("%d ",head->data);
}
int main()
{
    struct node* head;
    head = NULL;
    insert(&head,6); // list 6
    insert(&head,5); // list 5 6
    insert(&head,2); // list 2 5 6
    insert(&head,9); // list 9 2 5 6
    Reverseprint(head);
    return 0;
}