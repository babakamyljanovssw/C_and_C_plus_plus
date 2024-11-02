#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 50 // the maximum size of the grid, we can change it if we want bigger than it
int dir[4][2]={ {-1,0},{0,1},{1,0},{0,-1} }; // creating 2d array to get up right down left indices of grid
char grid[SIZE][SIZE]; // the grid represented by obstacles and pathways. (obstacles = # and pathways = .)
int visited[SIZE][SIZE]; // creating 2d array to mark visited indices
int M,N; // M = count of rows, N = count of columns
int next_in_level_count = 0; // counting nodes in each level
int left_in_level_count = 1; // counting left nodes in each level
int move_count = 0;
bool reach_exit = false;

struct Queue;
struct Queue* RQ;
struct Queue* CQ;
struct Queue* CreateQueue(int N);
int isFull(struct Queue* Q);
int isEmpty(struct Queue* Q);
void Enqueue(struct Queue* Q,int val);
int Dequeue(struct Queue* Q);
void DisposeQueue(struct Queue* Q);
void Explore(int i,int j);
void BFS();

struct Point
{
    int x;
    int y;
};
struct Point prev[SIZE][SIZE]; // creating 2d array to keeptracking prev path

struct Queue
{
    int size;
    int capacity;
    int* arr;
    int front;
    int rear;
};
struct Queue* CreateQueue(int N)
{
    struct Queue* Q = malloc(sizeof(struct Queue));
    if(Q != NULL)
    {
        Q->capacity = N;
        Q->size = 0;
        Q->front = -1;
        Q->rear = -1;
        Q->arr = (int*)malloc(N*sizeof(int));
        if(Q->arr != NULL){
            return Q;
        }
        else{
            printf("Out of space!\n");
            return NULL;
        }
    }
    else{
        printf("Out of space!\n");
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
void Enqueue(struct Queue* Q,int val)
{
    if(!isFull(Q))
    {
        if(Q->front == -1)
           Q->front++;
        Q->rear++;
        Q->size++;
        Q->arr[Q->rear] = val;
    }
    else
    {
        printf("Queue is full!\n");
        return;
    }
}
int Dequeue(struct Queue* Q)
{
    if(!isEmpty(Q))
    {
        int top = Q->arr[Q->front];
        Q->front++;
        if(Q->front > Q->rear){
            Q->front = Q->rear = -1;
        }
        return top;
    }
    else
    {
        printf("Queue is empty!\n");
        return 0;
    }
}
void DisposeQueue(struct Queue* Q)
{
    free(Q->arr);
    free(Q);
}

void Explore(int i,int j)
{
    int r,c;
    for (int k = 0; k < 4; k++)
    {
        // moving into the new position int the grid
        r = i + dir[k][0];
        c = j + dir[k][1];

        if( (r < 0) || (r >= M) ) continue; // whether row indice is not in the range of grid then skip it
        if( (c < 0) || (c >= N) ) continue; // whether column indice is not in the range of grid then skip it

        if(visited[r][c]) continue; // whether the new position is already visited then skip it
        if(grid[r][c] == '#') continue; // whther the new position is obstacle then skip it
        
        Enqueue(RQ,r); // enqueue row indice into row queue
        Enqueue(CQ,c); // enqueue column indice into column queue
        visited[r][c] = 1;
        next_in_level_count++;
        prev[r][c].x = i;
        prev[r][c].y = j;
    }
}
void Reconstruct_path(int k,int l)
{
    
}
// finding path from source to exit using BFS algorithm.
void BFS()
{
    int i,j;
    RQ = CreateQueue(M*N); // Creating queue for keeping row indices
    CQ = CreateQueue(M*N); // Creating queue for keeping column indices
    Enqueue(RQ,0); // enqueue the row indice of start into row queue
    Enqueue(CQ,0); // enqueue the column indice of start into column queue
    visited[0][0] = 1; // marking startin postion as visited
    while (!isEmpty(RQ)) // or !isEmpty(CQ)
    {
        i = Dequeue(RQ);
        j = Dequeue(CQ);
        if(grid[i][j] == 'E'){
            reach_exit = true;
            Reconstruct_path(i,j);
            break;
        }
        Explore(i,j);
        left_in_level_count--;
        if(left_in_level_count == 0){
            left_in_level_count = next_in_level_count;
            next_in_level_count = 0;
            move_count++;
        }
    }
}

int main()
{
    int i,j;
    M = 5;
    N = 7;
    //printf("Enter number of rows in the grid = ");
    //scanf("%d",&M);
    //printf("Enter number of columns in the grid = ");
    //scanf("%d",&N);
    for ( i = 0; i < M; i++)
        for ( j = 0; j < N; j++)
            scanf("%c",&grid[i][j]);
    for ( i = 0; i < M; i++)
        for ( j = 0; j < N; j++)
            visited[i][j] = 0;
    BFS();
    if(reach_exit)
    {
        printf("Have path!\n");
    }
    else
    {
        printf("No path!\n");
    }
    return 0;
}