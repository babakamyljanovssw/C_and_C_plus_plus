// leetcode find the kth node to last node
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
    if(temp != NULL)
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
    }
}
int kthToLAst(struct node *head,int k)
{
    struct node *fast, *slow;
    int count = 0;
    fast = slow = head;

    while (fast != NULL)
    {
        if(count >= k){
            slow = slow->next;
        }
        fast = fast->next;
        count++;
    }
    return slow->data;
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
    insert(&head,5);
    insert(&head,4);
    insert(&head,3);
    insert(&head,2);
    insert(&head,1);
    //print(head);
    printf("%d\n",kthToLAst(head,2));
    return 0;
}