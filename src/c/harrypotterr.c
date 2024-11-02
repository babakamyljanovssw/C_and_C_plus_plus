#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxVertexNum 100   //The maximum number of vertices is set to 100
#define INFINITY 65535      // ∞ is set to the maximum value of a double-byte unsigned integer 65535
typedef int Vertex;      // Use vertex subscripts to represent vertices, which are integers
typedef int WeightType;  // The weight of the edge is set to integer

/* Definition of edge */
struct ENode
{
    Vertex V1, V2;      // Directed edge <V1, V2> 
    WeightType Weight; // Weights 
};
struct GNode
{
    int Nv;	/* Number of vertices */
    int Ne;	/* Number of edges */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* Adjacency matrix */
};

typedef struct GNode *PtrToGNode;
typedef struct ENode *PtrToENode;
typedef PtrToGNode MGraph; // Graph type stored in adjacency matrix
typedef PtrToENode Edge;


void Floyd( MGraph Graph, WeightType D[][MaxVertexNum] );
MGraph BuildGraph();
void InsertEdge( MGraph Graph, Edge E );
MGraph CreateGraph( int VertexNum );
WeightType FindMaxDist( WeightType D[][MaxVertexNum],Vertex i, int N );
void FindAnimal( MGraph Graph );


void FindAnimal( MGraph Graph )
{
    WeightType D[MaxVertexNum][MaxVertexNum], MaxDist, MinDist;  Vertex Animal, i;	
	Floyd( Graph, D ); 
	MinDist = INFINITY;
    for ( i=0; i<Graph->Nv; i++ )
    {
        MaxDist = FindMaxDist( D, i, Graph->Nv );
        if ( MaxDist == INFINITY ) // Explain that there are animals that cannot be transformed from i
        {
            printf("0\n");
            return;
        }
        if ( MinDist > MaxDist ) // Find the animal that the longest distance is smaller
        {
            MinDist = MaxDist; Animal = i+1; /* Update distance,record number */
        }
    }
    printf("%d %d\n", Animal, MinDist);
}

WeightType FindMaxDist( WeightType D[][MaxVertexNum],Vertex i, int N )
{
    WeightType MaxDist; Vertex j;
    MaxDist = 0;
    for( j=0; j<N; j++ ) // Find the longest distance from i to other animal j
    if ( i!=j && D[i][j]>MaxDist )
    MaxDist = D[i][j];
    return MaxDist;
}

MGraph CreateGraph( int VertexNum )
{
    // Initialize a graph with VertexNum vertices but no edges */
	Vertex V, W;
    MGraph Graph;
    Graph = (MGraph)malloc(sizeof(struct GNode)); /* Build graph */
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    // Initialize the adjacency matrix
    // Note: The default vertex number here starts from 0 to (Graph->Nv-1)
    for (V=0; V<Graph->Nv; V++)
    for (W=0; W<Graph->Nv; W++)  Graph->G[V][W] = INFINITY;
    return Graph;
}
void InsertEdge( MGraph Graph, Edge E )
{
    /* Insert edge <V1, V2> */
    Graph->G[E->V1][E->V2] = E->Weight;
    /* If it is an undirected graph, insert edges <V2, V1> */
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
    MGraph Graph; 
    Edge E;
    int Nv, i;
    scanf("%d", &Nv);	// Number of vertices
    Graph = CreateGraph(Nv); // Initialize a graph with Nv vertices but no edges
    scanf("%d", &(Graph->Ne));	// Read in the number of edges  
    if ( Graph->Ne != 0 ) // If there is edge
    {
        E = (Edge)malloc(sizeof(struct ENode)); // Create edge nodes
        // Read in the edge, the format is "start point end point weight", insert the adjacency matrix
        for (i=0; i<Graph->Ne; i++) 
        {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            E->V1--;
            E->V2--;
            InsertEdge( Graph, E );
        }
    }
    return Graph;
}
void Floyd( MGraph Graph, WeightType D[][MaxVertexNum] )
{
    Vertex i, j, k;
    /* Initialization */
    for ( i=0; i<Graph->Nv; i++ )
    for( j=0; j<Graph->Nv; j++ )
    {
        D[i][j] = Graph->G[i][j];
    }
    for( k=0; k<Graph->Nv; k++ ) 
	for( i=0; i<Graph->Nv; i++ )
    for( j=0; j<Graph->Nv; j++ )
    if( D[i][k] + D[k][j] < D[i][j] )
    {
        D[i][j] = D[i][k] + D[k][j];
        if ( i==j && D[i][j]<0 ) // If a negative circle is found 
        return;           // If it can't be solved correctly, return false
    }
}
int main()
{
    MGraph Graph = BuildGraph();
    FindAnimal(Graph);
    return 0;
}