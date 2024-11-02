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
// delete node at n th position
void delete(struct node** head, int n)
{
    struct node* temp = *head;
    if (n == 1)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; i < n-2; i++)
    {
        temp = temp->next;
    }
    struct node* temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
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
// reverse linked list using iterative method
struct node* reverse(struct node** head)
{
    struct node *prev,*current,*next;
    current = *head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    return *head;
}
int main()
{
    struct node* head;
    head = NULL;
    insert(&head,6); // list 6
    insert(&head,5); // list 5 6
    insert(&head,2); // list 2 5 6
    insert(&head,9); // list 9 2 5 6
    print(&head);
    //head = reverse(&head);
    //print(&head);
    int n;
    //printf("Enter the position of node that you want to delete: ");
    //scanf("%d",&n);
    //delete(&head,n);
    //print(&head);
    return 0;
}