//Given a linked list, swap every two adjacent nodes and return its head.
// input 1->2->3->4
// output 2->1->4->3
 
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
// insert at the end
void insert(struct node** head,int X)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = X;
    temp->next = NULL;
    if(temp == NULL)
    {
        printf("no space!\n");
        return;
    }
    else if (*head == NULL)
    {
        *head = temp;
        return;
    }
    struct node *p = *head;
    while(p->next != NULL) 
    p = p->next;

    if(p->next == NULL)
    p->next = temp;
    
}
// input 1->2->3->4
// output 2->1->4->3
struct node* swapPairs(struct node *head)
{
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;
    struct node *prev, *current, *nextTemp;
    prev = NULL;
    current = head;
    nextTemp = current->next;
    head = nextTemp;
    while (current != NULL)
    {
        if(nextTemp == NULL) break;
        if(prev != NULL) prev->next = nextTemp;
        current->next = nextTemp->next;
        nextTemp->next = current;
        prev = current;
        current = current->next;
        nextTemp = current != NULL ? current->next : NULL;
    }
    return head;
}
void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct node *head = NULL;
    int n,X;
    printf("\nEnter number of nodes in the list= ");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&X);
        insert(&head,X);
    }
    head= swapPairs(head);
    printf("\nNew added linked list: ");
    print(head);
    return 0;
}