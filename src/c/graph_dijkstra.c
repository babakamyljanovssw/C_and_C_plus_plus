#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define INFINITY 999999
struct Node
{
    int vertex;
    int weight;
    struct Node *next;
};
typedef struct Node *PtrToNode;
struct Graph
{
    int numVertices;
    PtrToNode *adjlist;
    bool *visited;
    int *dist;
    int *path;
};
typedef struct Graph *PtrToGraph;

PtrToGraph CreateGraph(int size)
{
    PtrToGraph G = malloc(sizeof(struct Graph));
    if(G != NULL)
    {
        G->numVertices = size;
        G->adjlist = malloc(size*sizeof(struct Node));
        G->visited = (bool*)malloc(size*sizeof(bool));
        G->dist = (int*)malloc(size*sizeof(int));
        G->path = (int*)malloc(size*sizeof(int));

        for (int i = 1; i <= size; i++)
        {
            G->adjlist[i] = NULL;
            G->visited[i] = false;
            G->dist[i] = INFINITY;
            G->path[i] = 0;
        }
        return G;
    }
    else
    {
        printf("Out of space!\n");
        return NULL;
    }
}
PtrToNode GetNewNode(int v2,int weight)
{
    PtrToNode temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp != NULL)
    {
        temp->vertex = v2;
        temp->weight = weight;
        temp->next = NULL;
        return temp;
    }
    else
    {
        printf("Out of space!\n");
        return NULL;
    }
}
void AddEdge(PtrToGraph G,int v1,int v2,int weight)
{
    // creating edge from vertex v1 to a vertex v2 with weight 
    PtrToNode NewNode;
    NewNode = GetNewNode(v2,weight);
    NewNode->next = G->adjlist[v1];
    G->adjlist[v1] = NewNode;
}
int MinWeight(PtrToGraph G)
{
    int i,min = INFINITY,vertex;
    for ( i = 1; i <= G->numVertices; i++)
    {
        if(!G->visited[i] && G->dist[i] < min)
        {
            min = G->dist[i];
            vertex = i;
        }
    }
    return vertex;
}
void Dijkstra(PtrToGraph G,int start)
{
    G->dist[start] = 0;
    int count = 0;
    int V,W;
    PtrToNode temp;
    while (count < G->numVertices)
    {
        V = MinWeight(G); // smallest unknown weighted vertex
        if(V == -1) break;
        G->visited[V] = true;
        count++;
        temp = G->adjlist[V];
        while (temp != NULL)
        {
            W = temp->vertex;
            if(!G->visited[W] && (G->dist[V] + temp->weight) < G->dist[W])
            {
                G->dist[W] = G->dist[V] + temp->weight;
                G->path[W] = V;
            }
            temp = temp->next;
        }
    }
}
void print(PtrToGraph G,int start)
{
    for (int i = 1; i <= G->numVertices; i++)
    {
        if(i != start)
            printf("Vertex%d - distance = %d, path = Vertex%d\n",i,G->dist[i],G->path[i]);
    }
    
}
int main()
{
    int n,v1,v2,weight,i,e;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);
    PtrToGraph G = CreateGraph(n); 
    for ( i = 0; i < e; i++)
    {
        scanf("%d %d %d",&v1,&v2,&weight);
        AddEdge(G,v1,v2,weight);
    }
    printf("Enter the vertex that you want to find the shortest path to any vertex: ");
    scanf("%d",&v1);
    Dijkstra(G,v1);
    printf("Dijkstra shortest path from Vertex%d to any vertex in graph: \n",v1);
    print(G,v1);
    return 0;
}