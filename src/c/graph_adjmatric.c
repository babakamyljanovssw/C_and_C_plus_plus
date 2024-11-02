#include<stdio.h>
#include<stdlib.h>
#define V 4

void initialize(int adjmatrix[][V])
{
    int i, j;
    for ( i = 0; i < V; i++)

    for ( j = 0; j < V; j++)
       
    adjmatrix[i][j] = 0;
}
void addedge(int adjmatrix[][V],int i,int j)
{
    adjmatrix[i][j] = 1;
    adjmatrix[j][i] = 1;
}
void print(int adjmatrix[][V])
{
    int i, j;
    for ( i = 0; i < V; i++)
    {
        printf("%d: ",i);
        for ( j = 0; j < V; j++)
        {
            printf("%d ",adjmatrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int adjmatrix[V][V];
    initialize(adjmatrix);
    addedge(adjmatrix,0,1);
    addedge(adjmatrix,0,2);
    addedge(adjmatrix,1,2);
    addedge(adjmatrix,0,3);
    print(adjmatrix);
    return 0;
}