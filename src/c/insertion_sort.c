#include <stdio.h>
#include <stdlib.h>
#define size 100000 
void InsertionSort(long* A, int N);
int main()
{
	long A[size];
    int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	scanf("%ld",&A[i]);
    InsertionSort(A,N);
	printf("%ld",A[0]);
	for (int i = 1; i < N; i++)
	{
		printf(" %ld",A[i]);
	}
	return 0;
}
void InsertionSort(long* A, int N)
{
	int i, j;
	long temp;
	for (i = 1; i < N; i++)
	{
		temp = A[i];
		for (j = i; j > 0 && A[j-1] > temp; j--)
			A[j] = A[j-1];
		A[j] = temp;
	}
}