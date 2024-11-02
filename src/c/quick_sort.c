#include <stdio.h>
#include <stdlib.h>
#define size 100000 
#define Cutoff 3
void Quicksort(long* A, int N);
int Median3(long* A, int Left, int Right);
void Qsort(long* A, int Left, int Right);
void InsertionSort(long* A, int N);
int main()
{
	long A[size];
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	scanf("%ld",&A[i]);
	Quicksort(A,N);
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
void Quicksort(long* A, int N)
{
	Qsort(A, 0, N-1);
}
int Median3(long* A, int Left, int Right)
{
	int temp, Center = (Left + Right)/2;
	if (A[Left]>A[Center])
	{
		temp = A[Left]; A[Left] = A[Center]; A[Center] = temp;
	}
	if (A[Left]>A[Right])
	{
		temp = A[Left]; A[Left] = A[Right]; A[Right] = temp;
	}
	if (A[Center]>A[Right])
	{
		temp = A[Center]; A[Center] = A[Right]; A[Right] = temp;
	}
	temp = A[Center]; A[Center] = A[Right-1]; A[Right-1] = temp;
	return A[Right-1];
}
void Qsort(long* A, int Left, int Right)
{
	int i, j, temp;
	long Pivot;
	if (Left + Cutoff <= Right)
	{
		Pivot = Median3(A, Left, Right);
		i = Left; j = Right - 1;
		for ( ; ; )
		{
			while (A[++i] < Pivot)
			{}
			while (A[--j] > Pivot)
			{}
			if (i < j)
			{
				temp = A[i]; A[i] = A[j]; A[j] = temp;
			}
			else 
			    break;
		}
		temp = A[i]; A[i] = A[Right-1]; A[Right-1] = temp;
		Qsort(A, Left, i-1);
		Qsort(A, i+1, Right);
	}
	else
	    InsertionSort(A + Left, Right - Left + 1);
}