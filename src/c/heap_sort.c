#include<stdio.h>
#include <stdlib.h>
#define size 100000
#define LeftChild(i) (2*(i)+1)
void PercDown(long A[], int i, int N);
void Heap_Sort(long a[], int N);

int main()
{
    long A[size];
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    scanf("%ld", &A[i]);
    Heap_Sort(A,N);
    printf("%ld",A[0]);
	for (int i = 1; i < N; i++)
	{
		printf(" %ld",A[i]);
	}
    return 0;
}
void PercDown(long A[], int i, int N)
{
    int tmp, child;
    for (tmp = A[i]; LeftChild(i) < N; i = child)
    {
        child = LeftChild(i);
        if ( (child!=N-1) && (A[child+1]>A[child]) )
        child++;
        if (tmp<A[child])
        A[i] = A[child];
        else 
        break;
    }
    A[i] = tmp; 
}
void Heap_Sort(long A[], int N)
{
    for (int i = N/2; i >= 0; i--)
    PercDown(A, i , N);
    
    for (int i = N - 1; i > 0; i--)
    {
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        PercDown(A, 0, i);
    }
}