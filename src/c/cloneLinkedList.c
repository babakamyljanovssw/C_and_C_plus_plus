#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *random;
};
struct node* NewNode(int X);
void print(struct node *head);
struct node* Copy_Clone(struct node *head);
struct node* NewNode(int X)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Out of space!\n");
        return NULL;
    }
    else
    {
        temp->data = X;
        temp->next = NULL;
        temp->random = NULL;
        return temp;
    }
}
void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("node = %d ",temp->data);

        if(temp->random == NULL)
        printf("random = NULL\n");
        else printf("random = %d\n",temp->random->data);

        temp = temp->next;
    }
}
struct node* Copy_Clone(struct node *head)
{
    if(head == NULL) return head;
    struct node *current_temp = head, *next_temp, *clone_temp;
    // copy linked list. make clone/copy node for each node. make the next pointer of clone to the original node's next
    while (current_temp != NULL)
    {
        next_temp = current_temp->next;
        clone_temp = NewNode(current_temp->data);
        current_temp->next = clone_temp;
        clone_temp->next = next_temp;
        current_temp = next_temp;
    }
    // copy the random pointers from the original node to its clone
    current_temp = head;
    while (current_temp != NULL)
    {
        clone_temp = current_temp->next;
        clone_temp->random = current_temp->random != NULL ? current_temp->random->next : NULL;
        current_temp = clone_temp->next;
    }
    
    // split original and clone lists
    current_temp = head;
    struct node *newhead = current_temp->next;

    while (current_temp != NULL)
    {
        clone_temp = current_temp->next;
        current_temp->next = clone_temp->next;
        clone_temp->next = current_temp->next != NULL ? current_temp->next->next : NULL;
        current_temp = current_temp->next;
    }
    return newhead;
}
int main()
{
    struct node *head;
    head = NewNode(7);
    head->next = NewNode(3);
    head->next->next = NewNode(11);
    head->next->next->next = NewNode(10);
    head->next->next->next->next = NewNode(1);

    head->random = NULL;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;
    printf("\nOriginal linked list:\n");
    print(head);

    struct node *clone = Copy_Clone(head);
    printf("\nClone linked list:\n");
    print(clone);
    return 0;
}