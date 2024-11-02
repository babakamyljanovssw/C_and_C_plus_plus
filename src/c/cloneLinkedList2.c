#include<stdio.h>
#include<stdlib.h>
#define SIZE 11

struct node;
struct hashtable;
struct node* NewNode(int X);
void print(struct node *head);
struct node* Copy_Clone(struct node *head);

struct node
{
    int data;
    struct node *next;
    struct node *random;
};
struct hashnode
{
    struct node *orig;
    struct node *clone;
    struct hashnode *next;
};
struct hashtable
{
    int size;
    struct hashnode **list;
};

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
struct hashtable *CreateTable(int n)
{
    struct hashtable *T = (struct hashtable*)malloc(sizeof(struct hashtable));
    if(T != NULL)
    {
        T->size = n;
        T->list = (struct hashnode**)malloc(n * sizeof(struct hashnode));
        int i;
        for ( i = 0; i < n; i++)
            T->list[i] = NULL;
        return T;
    }
    else
    {
        printf("No space!\n");
        return NULL;
    }
}
int HashCode(struct hashtable *T,int key)
{
    int i = 0;
    int pos = (key + i) % T->size;
    while (T->list[pos] != NULL)
    {
        ++i;
        pos = (key + i) % T->size;
    }
    return pos;
}
struct node* get(struct hashtable *T,struct node *temp)
{
    int i = 0;
    if(temp == NULL) return NULL;
    int pos = (temp->data + i) % T->size;
    while (T->list[pos]->orig->data != temp->data)
    {
        ++i;
        pos = (temp->data + i) % T->size;
    }
    return T->list[pos]->clone;
}
void Insert(struct hashtable *T,struct node *orig,struct node *clone)
{
    int pos = HashCode(T,orig->data);
    struct hashnode *temp = (struct hashnode*)malloc(sizeof(struct hashnode));
    if(temp != NULL)
    {
        temp->orig = orig;
        temp->clone = clone;
        temp->next = T->list[pos];
        T->list[pos] = temp;
        return;
    }
    else
    {
        printf("No space!\n");
        return;
    }
}
struct node* Copy_Clone(struct node *head)
{
    struct hashtable *T = CreateTable(SIZE); // SIZE is number of nodes in the linked list
    struct node *current, *clone;
    current = head;
    while (current != NULL)
    {
        clone = NewNode(current->data);
        Insert(T,current,clone);
        current = current->next;
    }
    current = head;
    struct node *temp1, *temp2, *temp3;
    while (current != NULL)
    {
        temp1 = get(T,current); // mapping to current and get it's clone
        temp2 = get(T,current->next); // mapping to next node of current and get it's clone
        temp1->next =  temp2 != NULL ? temp2 : NULL; // declaring second clone to the first clone's next
        temp3 = get(T,current->random); // mapping to random pointer node of currentand get it's clone
        temp1->random = temp3 != NULL ? temp3 : NULL; // declaring random pointer to the first clone's raddom
        current = current->next;
    }
    return get(T,head);
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