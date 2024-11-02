#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define INFINITY INT_MAX
int heapsize = 0;

struct Node
{
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph
{
    int size;
    struct Node** adjlist;
    bool* visited;
    int* path;
    int* dist;
};
int PQ[10];

struct Graph* CreateGraph(int N)
{
    struct Graph* G = malloc(sizeof(struct Graph));
    if (G != NULL)
    {
        G->size = N+1;
        G->adjlist = malloc(G->size * (sizeof(struct Node)));
        G->dist = (int*)malloc(G->size * sizeof(int));
        G->path = (int*)malloc(G->size * sizeof(int));
        G->visited = (bool*)malloc(G->size * sizeof(bool));
        for (int i = 1; i < G->size; i++)
        {
            G->adjlist[i] = NULL;
            G->dist[i] = INFINITY;
            G->path[i] = 0;
            G->visited[i] = false;
        }
        return G;
    }
    else
    {
        printf("No space!\n");
        return NULL;
    }   
}
struct Node* GetNewNode(int v,int w)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp != NULL)
    {
        temp->vertex = v;
        temp->weight = w;
        temp->next = NULL;
        return temp;
    }
    else
    {
        printf("No space!\n");
        return NULL;
    }
}
// Undirected graph. Adding edge from v1 to v2 and from v2 to v1
void AddEdge(struct Graph* G,int v1,int v2,int cost)
{
    struct Node* temp = GetNewNode(v2,cost);
    if(temp != NULL)
    {
        temp->next = G->adjlist[v1];
        G->adjlist[v1] = temp;
    }
    temp = GetNewNode(v1,cost);
    if(temp != NULL)
    {
        temp->next = G->adjlist[v2];
        G->adjlist[v2] = temp;
    }
}

void InsertPQ(struct Graph* G,int v)
{
    int i;
    i = ++heapsize;
    while (G->dist[PQ[i/2]] > G->dist[v])
    {
        PQ[i] = i / 2;
        i /= 2;
    }
    PQ[i] = v;
}
int DeleteMin(struct Graph* G)
{
    int min,last,hole,child;
    min = PQ[1];
    last = PQ[heapsize--];
    for ( hole = 1; hole * 2 <= heapsize; hole = child )
    {
        child = hole * 2;
        if( (child != heapsize) && (G->dist[PQ[child+1]] < G->dist[PQ[child]]) )
            child++;
        if(G->dist[last] > G->dist[PQ[child]])
            PQ[hole] = PQ[child];
        else
            break;
    }
    PQ[hole] = last;
    return min;
}
void UpdatePQ(struct Graph* G,int v)
{
    int i = 1;
    while (PQ[i] != v)
    {
        i++;
    }
    while (G->dist[PQ[i/2]] > G->dist[v])
    {
        PQ[i/2] = PQ[i];
        i /= 2;
    }
    PQ[i] = v;
}
bool isEmptyPQ()
{
    if(heapsize == 0) 
       return true;
    else 
       return false;
}
void Prims(struct Graph* G,int start){
    int v,d,adj;
    struct Node* temp;
    G->dist[start] = 0;
    G->path[start] = 0;
    InsertPQ(G,start);

    while( !isEmptyPQ() ){
        v = DeleteMin(G);
        G->visited[v] = true;
        temp = G->adjlist[v];
        
        while (temp != NULL){
            d = temp->weight;
            adj = temp->vertex;
            if( !G->visited[adj] ){
                if( G->dist[adj] == INFINITY ){
                    G->dist[adj] = d;
                    G->path[adj] = v;
                    InsertPQ(G,adj);
                }
                else if( d < G->dist[adj] ){
                    G->dist[adj] = d;
                    G->path[adj] = v;
                    UpdatePQ(G,adj);
                }
            }
            temp = temp->next;
        }
    }
}
void Print(struct Graph* G,int start)
{
    for (int i = 1; i < G->size; i++)
    {
        if(i != start)
           printf("Path to %d = %d. Distance = %d\n",i,G->path[i],G->dist[i]);
    } 
}
int main()
{
    int NumVertices,NumEdges,v1,v2,cost;
    printf("Enter numebr of vertices = ");
    scanf("%d",&NumVertices);
    printf("Enter number of edges = ");
    scanf("%d",&NumEdges);
    struct Graph* G = CreateGraph(NumVertices);
    if(G != NULL){
        for (int i = 0; i < NumEdges; i++)
        {
            scanf("%d %d %d",&v1,&v2,&cost);
            AddEdge(G,v1,v2,cost);
        }
    }
    Prims(G,1);
    Print(G,1);
    return 0;  
}