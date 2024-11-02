#include <stdio.h>
#include <stdlib.h>

struct Queue;
int isEmpty(struct Queue *Q);
int isFull(struct Queue *Q);
struct Queue *createQueue(int MaxElements);
void disposeQueue(struct Queue *Q);
void makeEmpty(struct Queue *Q);
void enqueue(int X, struct Queue *Q);
int front(struct Queue *Q);
int rear(struct Queue *Q);
void dequeue(struct Queue *Q);
int frontAndDequeue(struct Queue *Q);
void printQueue(struct Queue *Q);

#define MinQueueSize 5

struct Queue
{
    int capacity;
    int front;
    int rear;
    int size;
    int *Array;
};

int isEmpty(struct Queue *Q)
{
    return Q->size == 0;
}

int isFull(struct Queue *Q)
{
    return Q->capacity == Q->size;
}

struct Queue *createQueue(int MaxElements)
{
    printf("create queue\n");
    struct Queue *Q;

    if (MaxElements < MinQueueSize)
        printf("Queue size is to small!\n");
    else
        Q = malloc(sizeof(struct Queue));

    if (Q == NULL)
        printf("Out of space!\n");
    else
        Q->Array = malloc(sizeof(int) * MaxElements);

    if (Q->Array == NULL)
        printf("Out of space!\n");
    else
        Q->capacity = MaxElements;
    makeEmpty(Q);
    return Q;
}

void makeEmpty(struct Queue *Q)
{
    printf("make queue empty\n");
    Q->size = 0;
    Q->front = 1;
    Q->rear = 0;
}

void disposeQueue(struct Queue *Q)
{
    printf("dispose queue\n");
    if (Q != NULL)
    {
        free(Q->Array);
        free(Q);
    }
}

void enqueue(int X, struct Queue *Q)
{
    printf("enqueue %d to queue\n", X);
    if (isFull(Q))
        printf("Error: Full Queue!\n");
    else
    {
        Q->size++;
        Q->Array[++Q->rear] = X;
    }
}

int front(struct Queue *Q)
{
    printf("front of queue\n");
    if (isEmpty(Q))
        printf("Empty Queue!\n");
    else
        return Q->Array[Q->front];
}

int rear(struct Queue *Q)
{
    printf("rear of queue\n");
    if (isEmpty(Q))
        printf("Empty Queue!\n");
    else
        return Q->Array[Q->rear];
}

void dequeue(struct Queue *Q)
{
    printf("dequeue from queue\n");
    if (isEmpty(Q))
        printf("Empty Queue!\n");
    else
    {
        Q->size--;
        Q->front++;
    }
}

// return front and then dequeue also
int frontAndDequeue(struct Queue *Q)
{
    printf("get front and dequeue from queue: ");
    int n = Q->Array[Q->front];
    if (isEmpty(Q))
        printf("Empty Queue!\n");
    else
    {
        Q->size--;
        Q->front++;
        return n;
    }
}

void printQueue(struct Queue *Q)
{
    printf("queue is: ");
    for (int i = Q->front; i <= Q->rear; i++)
    {
        printf("%d ", Q->Array[i]);
    }
    printf("\n");
}

int main()
{
    int MaxElements = 10;
    struct Queue *Q;
    Q = createQueue(MaxElements);

    enqueue(5, Q);
    printQueue(Q);

    enqueue(8, Q);
    printQueue(Q);

    enqueue(15, Q);
    printQueue(Q);

    enqueue(3, Q);
    printQueue(Q);

    printf("%d\n", front(Q));
    printf("%d\n", rear(Q));

    dequeue(Q);
    printQueue(Q);

    printf("%d\n", frontAndDequeue(Q));
    printQueue(Q);

    return 0;
}