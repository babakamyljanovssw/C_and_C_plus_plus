#include<stdio.h>
#include<stdlib.h>

struct Queue;
int IsEmpty(struct Queue* Q);
int IsFull(struct Queue* Q);
struct Queue* CreateQueue(int MaxElements);
void DisposeQueue (struct Queue* Q);
void MakeEmpty(struct Queue* Q);
void Enqueue (int X, struct Queue* Q);
int Front(struct Queue* Q);
void Dequeue(struct Queue* Q);
int FrontAndDequeue(struct Queue* Q);
void PrintQueue(struct Queue* Q);

#define MinQueueSize 5

struct Queue
{
    int capacity;
    int front;
    int rear;
    int size;
    int *Array;
};
int IsEmpty(struct Queue* Q)
{
    return Q->size == 0;
}
int IsFull(struct Queue* Q)
{
    return Q->capacity == Q->size;
}
struct Queue* CreateQueue(int MaxElements)
{
    struct Queue* Q;

    if (MaxElements < MinQueueSize) printf("Queue size is to small!\n");
    else Q = malloc(sizeof(struct Queue));

    if(Q == NULL) printf("Out of space!\n");
    else Q->Array = malloc(sizeof(int)*MaxElements);

    if(Q->Array == NULL) printf("Out of space!\n");
    else Q->capacity = MaxElements;
    MakeEmpty(Q);
    return Q;
}
void MakeEmpty(struct Queue* Q)
{
    Q->size = 0;
    Q->front = 1;
    Q->rear = 0;
}
void DisposeQueue(struct Queue* Q)
{
    if (Q != NULL)
    {
        free(Q->Array);
        free(Q);
    }
}
void Enqueue(int X, struct Queue* Q)
{
    if(IsFull(Q)) printf("Error: Full Queue!\n");
    else
    {
        Q->size++;
        Q->Array[++Q->rear] = X;   
    }
}
int Front(struct Queue* Q)
{
    if(IsEmpty(Q)) printf("Empty Queue!\n");
    else return Q->Array[Q->front];
}
void Dequeue(struct Queue* Q)
{
    if(IsEmpty(Q)) printf("Empty Queue!\n");
    else
    {
        Q->size--;
        Q->front++;
    }
}
int FrontAndDequeue(struct Queue* Q)
{
    int n = Q->Array[Q->front];
    if(IsEmpty(Q)) printf("Empty Queue!\n");
    else
    {
        Q->size--;
        Q->front++;
        return n;
    }
}
void PrintQueue(struct Queue* Q)
{
    for (int i = Q->front; i <= Q->rear; i++)
    {
        printf("%d ",Q->Array[i]);
    }
    printf("\n");
}
int main()
{
    int MaxElements = 10;
    //printf("Enter number elements of Array = ");
    //scanf("%d",&MaxElements);
    struct Queue* Q;
    Q = CreateQueue(MaxElements);

    Enqueue(5,Q);
    printf("Queue: ");
    PrintQueue(Q);

    Enqueue(8,Q);
    printf("Queue: ");
    PrintQueue(Q);

    Enqueue(15,Q);
    printf("Queue: ");
    PrintQueue(Q);

    Enqueue(3,Q);
    printf("Queue: ");
    PrintQueue(Q);

    printf("Front = %d\n",Front(Q));
    
    Dequeue(Q);
    printf("Queue: ");
    PrintQueue(Q);

    printf("Front and Dequeue = %d\n",FrontAndDequeue(Q));
    
    return 0;
}