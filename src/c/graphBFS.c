#include<stdio.h>
#include<stdlib.h>
#define SIZE 40

struct Node
{
    int vertex;
    struct Node *next;
};
typedef struct Node *PtrToNode;
struct Graph
{
    int numVertices;
    int *Visited;
    PtrToNode *adjlist;
};
typedef struct Graph *PtrToGraph;

struct Queue
{
    int item[SIZE];
    int front;
    int rear;
};
struct Queue *CreateQueue();
void Enqueue(struct Queue *Q,int vertex);
int Dequeue(struct Queue *Q);
int IsEmpty(struct Queue *Q);

PtrToGraph CreateGraph(int size)
{
    PtrToGraph Graph = malloc(sizeof(struct Graph));
    if (Graph != NULL)
    {
        Graph->numVertices = size;
        Graph->adjlist = malloc(size * sizeof(struct Node));
        Graph->Visited = malloc(size * sizeof(int));
        int i;
        for ( i = 0; i < size; i++)
        {
            Graph->adjlist[i] = NULL;
            Graph->Visited[i] = 0;
        }
            
         return Graph;
    }
    else
    {
        printf("Out of space!\n");
        return NULL;
    }
}
PtrToNode GetNewNode(int i)
{
    PtrToNode NewNode = malloc(sizeof(struct Node));
    if (NewNode != NULL)
    {
        NewNode->vertex = i;
        NewNode->next = NULL;
        return NewNode;
    }
    else
    {
        printf("Out of space!\n");
        return NULL;
    }
}
void AddEdge(PtrToGraph Graph,int i,int j)
{
    PtrToNode NewNode;
    NewNode = GetNewNode(j);
    NewNode->next = Graph->adjlist[i];
    Graph->adjlist[i] = NewNode;

    NewNode = GetNewNode(i);
    NewNode->next = Graph->adjlist[j];
    Graph->adjlist[j] = NewNode;
}
void BFS(PtrToGraph Graph,int vertex)
{
    struct Queue *Q = CreateQueue();
    Graph->Visited[vertex] = 1;
    Enqueue(Q,vertex);
    while (!IsEmpty(Q))
    {
        int currentvertex = Dequeue(Q);
        printf("%d ",currentvertex);
        PtrToNode temp = Graph->adjlist[currentvertex];
        while (temp != NULL)
        {
            int adjVertex = temp->vertex;
            if (Graph->Visited[adjVertex] == 0)
            {
                Enqueue(Q,adjVertex);
                Graph->Visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
}
struct Queue *CreateQueue()
{
    struct Queue *Q = malloc(sizeof(struct Queue));
    if(Q != NULL)
    {
        Q->front = -1;
        Q->rear = -1;
        return Q;
    }
    else
    {
        printf("Out of space!\n");
        return NULL;
    }
}
void Enqueue(struct Queue *Q,int vertex)
{
    if(Q->rear == SIZE-1)
    {
        printf("Queue is full!\n");
        return;
    }
    else
    {
        if(Q->front == -1) Q->front++;
        Q->item[++Q->rear] = vertex;;
    }
}
int Dequeue(struct Queue *Q)
{
    int item;
    if(IsEmpty(Q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    else
    {
        item = Q->item[Q->front];
        Q->front++;
        if (Q->front > Q->rear)
        {
            Q->front = -1;
            Q->rear = -1;
        }
    }
    return item;
}
int IsEmpty(struct Queue *Q)
{
    if(Q->rear == -1) return 1;
    else return 0;
}
void print(PtrToGraph Graph)
{
    int v;
    PtrToNode temp;
    for ( v = 0; v < Graph->numVertices; v++)
    {
        printf("%d: ",v);
        temp = Graph->adjlist[v];
        while (temp != NULL)
        {
            printf("%d ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    PtrToGraph Graph = CreateGraph(5);
    AddEdge(Graph,0,1);
    AddEdge(Graph,0,2);
    AddEdge(Graph,0,3);
    AddEdge(Graph,1,2);
    AddEdge(Graph,2,4);
    print(Graph);
    printf("BFS %d: ",0);
    BFS(Graph,0);
    return 0;
}