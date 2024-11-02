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
    int *Visited;
    PtrToNode *adjlist;
};
typedef struct Graph *PtrToGraph;

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
void DFS(PtrToGraph Graph,int vertex)
{
    PtrToNode temp = Graph->adjlist[vertex];
    Graph->Visited[vertex] = 1;
    printf("%d ",vertex);
    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;
        if (Graph->Visited[connectedVertex] == 0)
        {
            DFS(Graph,connectedVertex);
        }
        temp = temp->next;
    }
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
    printf("DFS %d: ",0);
    DFS(Graph,0);
    return 0;
}