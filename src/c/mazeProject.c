#include<stdio.h>
#include<stdlib.h>

#define SIZE 50
int A[SIZE][SIZE]; // Adjacency matrix to represent the maze, 0 as pathways and 1 as obstackles
int M,N;
int directory[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; /* this 2D array is for move: 
                                                      (-1,0) - UP, (0,1) - RIGHT
                                                      (1,0) - DOWN, (0,-1) - LEFT */

int visited[SIZE][SIZE]; // to mark visited positions

struct DFS_Stack;
struct Point;

int IsEmpty(struct DFS_Stack* S);
struct DFS_Stack* CreateStack();
void Push(struct DFS_Stack* S,int i, int j, int dir);
struct DFS_Stack* Top(struct DFS_Stack* S);
void DFS(struct Point a, struct Point b, int A[][SIZE]);
void Reverse_Print(struct DFS_Stack* S);

struct Point
{
    int x;
    int y;
};
// Implementation of stack. It stores the position(x,y) of path from a to b and directions(d) (0,1,2,3 as 'UP,RIGHT,DOWN,LEFT')
struct DFS_Stack
{
    int x;
    int y;
    int d;
    struct DFS_Stack* Next;
};
// Create Empty Stack
struct DFS_Stack* CreateStack()
{
    struct DFS_Stack* S = malloc(sizeof(struct DFS_Stack));
    if (S == NULL)
    {
        printf("Out of space!");
    }
    S->Next = NULL;
    return S;
}
// Check whether Stack is empty or no
int IsEmpty(struct DFS_Stack* S)
{
    return S->Next == NULL;
}
// Insert Element into Stack
void Push(struct DFS_Stack* S,int i, int j, int dir)
{
    struct DFS_Stack* TmpCell = (struct DFS_Stack*)malloc(sizeof(struct DFS_Stack));
    if (TmpCell == NULL)
    {
        printf("Out of space!\n");
        return;
    }
    TmpCell->x = i;
    TmpCell->y = j;
    TmpCell->d = dir;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}
// To get Top of Stack
struct DFS_Stack* Top(struct DFS_Stack* S)
{
    if (IsEmpty(S)) printf("Error! Empty stack\n");
    else return S->Next;
}
// Remove Top of Stack
void Pop(struct DFS_Stack* S)
{
    struct DFS_Stack* TmpCell = S->Next;
    if (IsEmpty(S))
    {
        printf("Error! Empty stack\n");
        return;
    }
    else
    {
        S->Next = TmpCell->Next;
        free(TmpCell);
    }
}
// Using Depth First Search Algorithm to find path in the maze
void DFS(struct Point a, struct Point b, int A[][SIZE])
{
    int currentX, currentY, dir, nextX, nextY, endX, endY;

    struct DFS_Stack* S, *Ptr;
    S = CreateStack();
    
    // here I initialized inlet's row and column indices to currentX,Y variables
    currentX = a.x;
    currentY = a.y;
    visited[currentX][currentY] = 1; // before start to search I marked inlet as visited.
    Push(S,currentX,currentY,-1); /* here the stack is empty that is why I am filling first element of stack
                                   with inlet indices. Because if stack is empty I cannot go inside while() loop */
    while (!IsEmpty(S))
    {
        for (int dir = 0; dir < 4; dir++) // this loop for to get directions
        {
            // check if I get to the exit from maze
            if ((nextX == b.x) && (nextY == b.y))
            {
                Reverse_Print(S);
                return;
            }
            // moving to the new position
            nextX = currentX + directory[dir][0];
            nextY = currentY + directory[dir][1];
            // cheking whether new postion is in range of given Matrix and possibility to move there
            if( (nextX>=0) && (nextX<M) && (nextY>=0) && (nextY<N) && (A[nextX][nextY]==0) )
            {
                if (!visited[nextX][nextY]) // I cannot move if I was there once
                {
                    // Insert position and direction into stack and then mark them as visited
                    Push(S,currentX,currentY,dir);
                    visited[nextX][nextY] = 1;
                    // initialize dir as -1 for to search four directions from the new position that I moved
                    currentX = nextX; currentY = nextY; dir = -1;
                }
            }
        }
        /* If I cannot find a way to move, then I need to get previous position by Topping of stack, then Remove it
           and start to search from there a new path*/
        Ptr = Top(S);
        currentX = Ptr->x; currentY = Ptr->y;
        Pop(S);
    }
    // if stack gets empty it concludes that there is no path
    printf("There is no path!\n");
    return;
}
// print Stack in reverse order
void Reverse_Print(struct DFS_Stack* S)
{
    struct DFS_Stack* TmpCell;
    TmpCell = Top(S);
    if (TmpCell->d == -1) return;
    int x = TmpCell->x, y = TmpCell->y, d = TmpCell->d;
    Pop(S);
    Reverse_Print(S);
    printf("(%d %d %d) ",x,y,d);
    TmpCell = TmpCell->Next;
}
int main()
{
    struct Point a, b;
    int i, j;
    // Number of rows
    printf("M = ");
    scanf("%d",&M);
    // Number of adjacent relationships per element
    printf("N = ");
    scanf("%d",&N);
    for ( i = 0; i < M; i++)
    for ( j = 0; j < N; j++) scanf("%d",&A[i][j]);
    // inlet postions of maze
    printf("Entrance to maze = ");
    scanf("%d %d",&a.x,&a.y);
    // exit positions from maze
    printf("Exit of the maze = ");
    scanf("%d %d",&b.x,&b.y);
    DFS(a,b,A);
    system("pause");
    return 0;
}