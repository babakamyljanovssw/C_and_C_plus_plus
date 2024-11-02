#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void insert(struct node** head,int X)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    // insert at the beginning
    /*if(temp != NULL)
    {
        temp->data = X;
        temp->next = *head;
        *head = temp;
        return;
    }
    else
    {
        printf("Out of space!\n");
        return;
    }*/

    // insert at the end
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
struct node* rotate(struct node *head,int k)
{
    if(head == NULL || k <= 0) return head;

    struct node *current = head, *last;
    int count = 0, i = 0;;
    while(current != NULL)
    {
        count++;
        last = current;
        current = current->next;
    }
    if(count == 0) return head;

    k = k % count;
    count = count - k - 1;

    last->next = head;
    current = head;

    while (i < count)
    {
        current = current->next;
        i++;
    }
    head = current->next;
    current->next = NULL;
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
    int n,k,X;
    printf("\nn = ");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&X);
        insert(&head,X);
    }
    printf("\nk = ");
    scanf("%d",&k);
    head = rotate(head,k);
    print(head);
    return 0;
}