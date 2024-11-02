#include<stdio.h>
#include<stdlib.h>

struct PQ;
struct PQ* Create(int N);
void Insert(struct PQ *head,int X);
void swap(int *a,int *b);
void heapify(struct PQ *head,int size,int i);
int size = 0;
void print(struct PQ* head);
void DeleteMin(struct PQ *head);

struct PQ
{
    int capacity;
    int *Array;
};
struct PQ* Create(int N)
{
    struct PQ *head;
    head = malloc(sizeof(struct PQ));
    if (head == NULL)
    {
        printf("Out of space!]n");
        return NULL;
    }
    head->Array = malloc(N+1 * sizeof(int));
    if (head->Array == NULL)
    {
        printf("Out of space!\n");
        return NULL;
    }
    head->capacity = N;

    return head;
}
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(struct PQ *head,int size,int i)
{
    if(size == 1) printf("There only one element in the heap");
    else
    {
        int left,right,smallest;
        smallest = i;    // parent
        left = i*2+1;   //left child
        right = i*2+2; // right child
        if(left < size && head->Array[left] < head->Array[smallest]) smallest = left;
        if(right <size && head->Array[right] < head->Array[smallest]) smallest = right;

        if(smallest != i)
        {
            swap(&head->Array[i],&head->Array[smallest]);
            heapify(head,size,smallest);
        }
    }
}
void Insert(struct PQ *head,int X)
{
    if(size == 0)
    {
        head->Array[0] = X;
        size++;
    }
    else
    {
        head->Array[size] = X;
        size++;
        for ( int i = size/2 - 1; i >= 0; i--)
        {
            heapify(head,size,i);
        }
    }
}
void DeleteMin(struct PQ *head)
{
    swap(&head->Array[0],&head->Array[size-1]); // swapping the min heap with it's last element
    size--; // remove it
    for (int i = size/2-1; i >= 0; i--)
    {
        heapify(head,size,i);
    }
}
void print(struct PQ* head)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ",head->Array[i]);
    }
    printf("\n");
}
int main()
{
    struct PQ *head = Create(10);
    Insert(head,13);
    Insert(head,21);
    Insert(head,16);
    Insert(head,24);
    Insert(head,31);
    Insert(head,19);
    Insert(head,68);
    Insert(head,65);
    Insert(head,26);
    Insert(head,32);
    Insert(head,14);
    DeleteMin(head);
    print(head);
    return 0;
}