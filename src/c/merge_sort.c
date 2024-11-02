#include <stdio.h>
#include <stdlib.h>
#define size 100000
#define FatalError printf("%s");
void Merge(long *A, long *tmp, int start, int end, int middle);
void Msort(long *A, long *tmp, int start, int end);
void Mergesort(long *A, int n);

int main() 
{
	int i, N;
	long A[size];
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	scanf("%ld", &A[i]);
	Mergesort(A, N);
	printf("%ld", A[0]);
	for (i = 1; i < N; i++)
		printf(" %ld", A[i]);
	return 0;
}
void Mergesort(long *A, int N) 
{
	long *tmp = (long*)malloc(N*sizeof(long));
    if (tmp!=NULL)
    {
        Msort(A, tmp, 0, N - 1);
        free(tmp);
    }
    else
    FatalError("No space for tmp Array!");
}
void Msort(long *A, long *tmp, int start, int end) {
	int middle;
	if (start < end) {
		middle = (start + end) / 2;
		Msort(A, tmp, start, middle);
		Msort(A, tmp, middle + 1, end);
		Merge(A, tmp, start, end, middle);
	}
} 
void Merge(long *A, long *tmp, int start, int end, int middle) {
	int l, r, s;
	s = start;
	l = start;
	r = middle + 1;
	while (l <= middle && r <= end) {
		if (A[l] <= A[r]) tmp[s++] = A[l++];
		else tmp[s++] = A[r++];
	}
	while (l <= middle) tmp[s++] = A[l++];
	while (r <= end) tmp[s++] = A[r++];
	for (;start <= end;start++)
		A[start] = tmp[start];
}