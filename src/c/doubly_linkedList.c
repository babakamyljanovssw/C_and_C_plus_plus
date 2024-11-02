#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
// insert at the beginning
void insertATHead(struct node** head, int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *head;
    temp->prev = NULL;
    struct node* temp2 = *head;
    temp2->prev=temp;
    *head = temp;
}
//  insert node at the end
void insert(struct node** head, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    struct node *temp2 = *head;
    while(temp2->next != NULL) temp2 = temp2->next;
    temp->prev = temp2;
    temp2->next = temp;
}
void delete(struct node** head,int n)
{
    struct node* current = *head;
    if (n==1)
    {
        *head = current->next;
        free(current);
        return;
    }
    for (int i = 0; i < n-1; i++)
    {
        current = current->next;
    }
    struct node *prevnode = current->prev, *nextnode = current->next;
    if (current->next == NULL)
    {
        prevnode->next = NULL;
        free(current);
        return;
    }
    prevnode->next = nextnode;
    nextnode->prev = prevnode;
    free(current);
}
void print(struct node* head)
{
    struct node* temp = head;
    if (temp == NULL) return;
    printf("Forward: ");
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void Recursionprint(struct node *head)
{
    if(head==NULL) return;
    printf("%d ",head->data);
    print(head->next);
    printf("\n");
}
void ReversePrint(struct node* head)
{
    struct node* temp = head;
    if(temp == NULL) return;

    // going to last node
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    // traversing backward using prev
    printf("Reverse: ");
    while (temp!=NULL)
    {
        printf("%d ", temp->data);
        temp= temp->prev;
    }
    printf("\n");
}
int main()
{
    struct node* head = NULL;
    insert(&head,5);
    insert(&head,6);
    insert(&head,8);
    insert(&head,1);
    insertATHead(&head,9);
    //delete(&head,4);
    //Recursionprint(head);
    print(head);
    ReversePrint(head);
    return 0;
}