#include<stdio.h>
#include<stdlib.h>

struct Queue;
struct Queue* CreateQueue();
void Enqueue(int X,struct Queue* Q);
int FrontAndDequeue(struct Queue* Q);
int IsEmpty(struct Queue* Q);
void MakeEmpty(struct Queue* Q);
void Print_Queue(struct Queue* Q);

struct Queue
{
    int data;
    struct Queue* next;
};
struct Queue* front = NULL;
struct Queue* rear = NULL;

struct Queue* CreateQueue()
{
    struct Queue* Q;
    Q = malloc(sizeof(struct Queue));
    if (Q == NULL)
        printf("Out of space!\n");
    else return Q;
}
void Enqueue(int X, struct Queue* Q)
{
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    if (temp == NULL)
    {
        printf("Out of space!\n");
        return;
    }
    if(front ==  NULL && rear == NULL)
    {
        Q->data = X;
        Q->next = NULL;
        rear = Q;
        front = Q;
    }
    else
    {
        temp->data = X;
        temp->next = NULL;
        rear->next = temp;
        rear = temp;
    } 
}
int FrontAndDequeue(struct Queue* Q)
{
    struct Queue* temp = front;
    int n = front->data;

    if(front == NULL)
    {
        printf("No element in Queue to dequeue!\n");
        return 0;
    }
    else if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
    }
    free(temp);
    return n;
}
void Print_Queue(struct Queue* Q)
{
    struct Queue* temp = front;
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct Queue* Q = CreateQueue();
    Enqueue(5,Q);
    Enqueue(6,Q);
    Enqueue(9,Q);
    printf("Queue:");
    Print_Queue(Q);
    int n = FrontAndDequeue(Q);
    printf("Front = %d\n",n);
    printf("Queue:");
    Print_Queue(Q);
    return 0;
}