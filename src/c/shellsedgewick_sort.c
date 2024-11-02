#include <stdio.h>
#include <stdlib.h>
#define size 100000 
void shellsedgewick_sort(long *a, int n);

int main() 
{
	int i, N;
	long A[size];
	scanf("%d", &N);
	for (i = 0;i < N;i++)
	scanf("%ld", &A[i]);
	shellsedgewick_sort(A, N);
	printf("%ld", A[0]);
	for (i = 1;i < N;i++)
	printf(" %ld", A[i]);
	return 0;
}
void shellsedgewick_sort(long *A, int N) 
{
	int i, j, d, si;
	int Sedgewick[] = { 929, 505, 209, 109, 41, 19, 5, 1, 0 };
	long temp;
	for (si = 0; Sedgewick[si] >= N; si++);
	for (; Sedgewick[si] > 0; si++) 
    {
		d = Sedgewick[si];
		for (i = d; i < N; i++) {
			temp = A[i];
			for (j = i; j >= d && A[j - d] > temp; j -= d)
				A[j] = A[j - d];
			A[j] = temp;
		}
	}
}