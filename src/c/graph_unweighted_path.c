#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define INFINITY INT_MAX
#define NotVertex -1
struct Node
{
    int vertex;
    struct Node* next;
};
struct Graph
{
    int numvertices;
    struct Node** adjlist;
    bool* visited;
    int* dist;
    int* path;
};
struct Queue
{
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;
};
struct Queue* CreateQueue(int N)
{
    struct Queue* Q = malloc(sizeof(struct Queue));
    if(Q != NULL)
    {
        Q->arr = (int*)malloc(N*sizeof(int));
        Q->front = -1;
        Q->rear = -1;
        Q->size = 0;
        Q->capacity = N;
    }
    else
    {
        printf("Out of space!\n");;
        return NULL;
    }
}
int isFull(struct Queue* Q)
{
    return Q->size == Q->capacity;
}
int isEmpty(struct Queue* Q)
{
    return Q->size == 0;
}
void Enqueue(struct Queue* Q,int v)
{
    if (isFull(Q))
    {
        printf("Queue is full!\n");
        return;
    }
    else if(Q->front == -1)
    {
        Q->front++;
    } 
    Q->rear++;  
    Q->arr[Q->rear] = v;
    Q->size++;
}
int Dequeue(struct Queue* Q)
{
    if(isEmpty(Q))
    {
        printf("Queue is empty! can't deque!\n");
        return 0;
    }
    else
    {
        int top = Q->arr[Q->front++];
        Q->size--;
        if(Q->front > Q->rear)
        {
            Q->front = -1;
            Q->rear = -1;
        }
        return top;
    } 
}
void DisposeQueue(struct Queue* Q)
{
    free(Q->arr);
    free(Q);
}
struct Graph* CreateGraph(int N)
{
    struct Graph* G = malloc(sizeof(struct Graph));
    if(G != NULL)
    {
        G->adjlist = malloc(N * sizeof(struct Node));
        G->numvertices = N;
        G->visited = (bool*)malloc(N*sizeof(bool));
        G->dist = (int*)malloc(N*sizeof(int));
        G->path = (int*)malloc(N*sizeof(int));
        for (int i = 0; i < N; i++)
        {
            G->adjlist[i] = NULL;
            G->visited[i] = false;
            G->dist[i] = INFINITY;
            G->path[i] = NotVertex;
        }
        return G;
    }
}
struct Node* GetNewNode(int v)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp != NULL)
    {
        temp->vertex = v;
        temp->next = NULL;
        return temp;
    }
    else
    {
        printf("Out of space!\n");
        return NULL;
    } 
}
void AddEdge(struct Graph* G,int i,int j)
{
    struct Node* temp = GetNewNode(j);
    if (temp != NULL)
    {
        temp->next = G->adjlist[i-1];
        G->adjlist[i-1] = temp;
    }
}
void Unweighted(struct Graph* G,int start)
{
    int v,w;
    struct Node* temp;
    struct Queue* Q = CreateQueue(G->numvertices);
    Enqueue(Q,start);
    G->dist[start-1] = 0;
    while (!isEmpty(Q))
    {
        v = Dequeue(Q);
        if(!G->visited[v - 1])
        {
            G->visited[v - 1] = true;
            temp = G->adjlist[v - 1];
            while (temp != NULL)
            {
                w = temp->vertex;
                if(G->dist[w - 1] == INFINITY)
                {
                    G->dist[w - 1] = G->dist[v - 1] + 1;
                    G->path[w - 1] = v;
                    Enqueue(Q,w);          
                }
                temp = temp->next;
            } 
        }
        
    }
    DisposeQueue(Q);
}
void print(struct Graph* G,int start)
{
    for (int i = 0; i < G->numvertices; i++)
    {
        if (i != start-1)
        {
            printf("Path to %d = %d. Distance = %d\n",i+1,G->path[i],G->dist[i]);
        }
    }   
}
int main()
{
    int N,E,i,v1,v2;
    printf("Enter the number of vertices = ");
    scanf("%d",&N);
    struct Graph* G = CreateGraph(N);
    printf("Enter the number of edges = ");
    scanf("%d",&E);
    for ( i = 0; i < E; i++)
    {
        scanf("%d %d",&v1,&v2);
        AddEdge(G,v1,v2);
    }
    Unweighted(G,3);
    print(G,3);
    return 0;
}