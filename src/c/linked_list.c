#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// inserts x to the beginning of the list
void insert_beginning(struct node **head, int x)
{
    printf("insert %d at the beginning\n", x);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    temp->next = *head;
    *head = temp;
}

// inserts x after the previous node
void insert_afterprev(struct node *prev_node, int x)
{
    if (prev_node == NULL)
    {
        printf("Previous node cannot be empty");
        return;
    }

    printf("insert %d after %d\n", x, prev_node->data);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = prev_node->next;
    prev_node->next = temp;
}

// inserts x to the end of the list
void insert_end(struct node **head, int x)
{
    printf("insert %d at the end\n", x);

    struct node *p = *head, *t;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if (*head == NULL)
    {
        temp->next = NULL;
        return;
    }
    while (p != NULL)
    {
        t = p;
        p = p->next;
    }
    if (t->next == NULL)
    {
        t->next = temp;
    }
}

// delete node at give position from the list
void delete(struct node **head, int pos)
{
    printf("delete node at position %d\n", pos);

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
        while ((temp != NULL) && (i <= pos - 1))
        {
            t = temp;
            temp = temp->next;
            i++;
        }
        t->next = NULL;
        free(temp);
        return;
    }

    for (i = 1; (temp != NULL) && (i <= pos - 1); i++)
    {
        t = temp;
        temp = temp->next;
    }
    t->next = t->next->next;
    free(temp);
}

void print(struct node *head)
{
    printf("linked list is: ");
    while (head != NULL)
    {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    insert_beginning(&head, 3);
    print(head);
    insert_beginning(&head, 5);
    print(head);
    insert_beginning(&head, 6);
    print(head);
    insert_afterprev(head->next, 4);
    print(head);
    insert_end(&head, 9);
    print(head);
    delete (&head, 3);
    print(head);
    return 0;
}
