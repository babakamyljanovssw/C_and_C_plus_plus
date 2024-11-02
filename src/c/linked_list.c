#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
// insert at beginning
void insert_beginning(struct node** head,int a)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = a;     //(*temp).head
    temp->next = NULL;  //(*temp).next
    //if(*head!=NULL) 
    temp->next = *head;
    *head = temp;
}
// insert after given previous node
void insert_afterprev(struct node*prev_node,int a)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (prev_node == NULL)
    {
        printf("Previous node cannot be empty");
        return ;
    }
    temp->data = a;
    temp->next = prev_node->next;
    prev_node->next = temp;
}
// insert at the end
void insert_end(struct node** head,int a)
{
    struct node* p = *head, *t;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = a;
    temp->next = NULL;
    if (*head == NULL)
    {
        temp->next = NULL;
        return;   
    }
    while(p!=NULL)
    {
        t = p;
        p = p->next;
    }
    if(t->next == NULL)
    {
        t->next = temp;
    }
}
// delete node i^th position 
void delete(struct node** head,int pos)
{
    struct node *temp = *head, *t;
    int i;
    if (pos == 1)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    if (pos == 5)
    {
        i = 1;
        while ((temp!=NULL) && (i <= pos-1))
        {
            t = temp;
            temp = temp->next;
            i++;
        }
        t->next = NULL;
        free(temp);
        return;
    }
    for ( i = 1; (temp!=NULL) && (i <= pos-1); i++)
    {
        t = temp;
        temp = temp->next;
    }
    t->next = t->next->next;
    free(temp);
}
void print(struct node* head)
{
    printf("List is: ");
    while (head != NULL)
    {
        printf(" %d",head->data);
        head = head->next;
    }
    printf("\n");
}
int main()
{
    struct node* head;
    head = NULL;
    insert_beginning(&head,3);
    insert_beginning(&head,5);
    insert_beginning(&head,6);
    insert_afterprev(head->next,4);
    insert_end(&head,9);
    delete(&head,3);
    print(head);
    return 0;
}
