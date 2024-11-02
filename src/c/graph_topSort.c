#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};
typedef struct Node *PtrToNode;
struct Graph
{
    int numVertices;
    int *Indegree;
    PtrToNode *adjlist;
};
typedef struct Graph *PtrToGraph;

struct Queue
{
    int *item;
    int front;
    int rear;
    int capacity;
};
struct Queue *CreateQueue(int N);
void Enqueue(struct Queue *Q,int vertex);
int Dequeue(struct Queue *Q);
int IsEmpty(struct Queue *Q);
void DisposeQueue(struct Queue *Q);

PtrToGraph CreateGraph(int size)
{
    PtrToGraph Graph = malloc(sizeof(struct Graph));
    if (Graph != NULL)
    {
        Graph->numVertices = size;
        Graph->adjlist = malloc(size * sizeof(struct Node));
        Graph->Indegree = malloc(size * sizeof(int));
        int i;
        for ( i = 0; i < size; i++)
        {
            Graph->adjlist[i] = NULL;
            Graph->Indegree[i] = 0;
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
    // we are creating edge from i to j, so indegree j will increase by one
    Graph->Indegree[j]++;
}
void Topsort(PtrToGraph Graph)
{
    struct Queue *Q = CreateQueue(Graph->numVertices);
    int count = 0;
    int i,V;
    for ( i = 0; i < Graph->numVertices; i++)
    {
        if(Graph->Indegree[i] == 0)
        Enqueue(Q,i);
    }
    printf("Topological sort is: ");
    while (count < Graph->numVertices)
    {
        while (!IsEmpty(Q))
        {
            V = Dequeue(Q);
            count++;
            printf("%d ",V);
            PtrToNode temp = Graph->adjlist[V];
            while (temp != NULL)
            {
                if(--Graph->Indegree[temp->vertex] == 0)
                Enqueue(Q,temp->vertex);
                temp = temp->next;
            }
        }
        if(count != Graph->numVertices)
        {
            printf("Error: Graph has a cycle!\n");
            return;
        }
    }
}
struct Queue *CreateQueue(int N)
{
    struct Queue *Q = malloc(N * sizeof(struct Queue));
    if(Q != NULL)
    {
        Q->front = -1;
        Q->rear = -1;
        Q->item = malloc(N * sizeof(int));
        Q->capacity = N;
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
    if(Q->rear == Q->capacity-1)
    {
        printf("Queue is full!\n");
        return;
    }
    else
    {
        if(Q->front == -1) Q->front++;
        Q->item[++Q->rear] = vertex;
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
void DisposeQueue(struct Queue *Q)
{
    free(Q);
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
void printIndegree(PtrToGraph Graph)
{
    int v;
    for ( v = 0; v < Graph->numVertices; v++)
        printf("Indegree of %d is %d\n",v,Graph->Indegree[v]);
    
}
int main()
{
    PtrToGraph Graph = CreateGraph(7);
    AddEdge(Graph,0,1);
    AddEdge(Graph,0,2);
    AddEdge(Graph,0,3);
    AddEdge(Graph,1,3);
    AddEdge(Graph,1,4);
    AddEdge(Graph,2,5);
    AddEdge(Graph,3,2);
    AddEdge(Graph,3,5);
    AddEdge(Graph,3,6);
    AddEdge(Graph,4,3);
    AddEdge(Graph,4,6);
    AddEdge(Graph,6,5);

    printf("Graph:\n");
    print(Graph);

    printf("Indegree of Vertices:\n");
    printIndegree(Graph);

    Topsort(Graph);
    
    return 0;
}