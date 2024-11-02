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
    PtrToNode *adjlist;
};
typedef struct Graph *PtrToGraph;

PtrToGraph CreateGraph(int size)
{
    PtrToGraph Graph = malloc(sizeof(struct Graph));
    Graph->numVertices = size;
    Graph->adjlist = malloc(size*sizeof(struct Node));

    int i;
    for ( i = 0; i < size; i++)
        Graph->adjlist[i] = NULL;
    return Graph;
}
PtrToNode GetNewNode(int v)
{
    PtrToNode temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp != NULL)
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
void AddEdge(PtrToGraph Graph,int i,int j)
{
    // make edge from i to j
    PtrToNode NewNode;

    NewNode = GetNewNode(j);
    NewNode->next = Graph->adjlist[i];
    Graph->adjlist[i] = NewNode;

    // as it is undirected graph we also need to make edge from j to i
    NewNode = GetNewNode(i);
    NewNode->next = Graph->adjlist[j];
    Graph->adjlist[j] = NewNode;
}
void print(PtrToGraph Graph)
{
    PtrToNode temp;
    int v;
    for ( v = 0; v < Graph->numVertices; v++)
    {
        temp = Graph->adjlist[v];
        printf("\n%d Vertex:\n",v);
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
    PtrToGraph Graph = CreateGraph(4);
    AddEdge(Graph,0,1);
    AddEdge(Graph,0,2);
    AddEdge(Graph,0,3);
    AddEdge(Graph,1,2);
    print(Graph);
    return 0;
}