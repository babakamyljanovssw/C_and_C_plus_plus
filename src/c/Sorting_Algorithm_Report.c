#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000 
#define Cutoff 10

void percdown(long *a, int n, int i);
void merge(long *a, long *tmp, int start, int end, int middle);
void msort(long *a, long *tmp, int start, int end);
void q_sort(long *a, int left, int right);

void insertion_sort(long *a, int n);
void shellsedgewick_sort(long *a, int n);
void heap_sort(long *a, int n);
void merge_sort(long *a, int n);
void quick_sort(long *a, int n);

int main() {
	int i, n;
	long a[N];
	scanf("%d", &n);
	for (i = 0;i < n;i++)
	scanf("%ld", &a[i]);
    // tStart = clock();
	//insertion_sort(a, n);
	//shellsedgewick_sort(a, n);
	//heap_sort(a, n);
	//merge_sort(a, n);
	quick_sort(a, n);
	printf("%ld", a[0]);
	for (i = 1;i < n;i++)
		printf(" %ld", a[i]);
   //printf("\nTime taken: %2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}

// Insertion Sort
void insertion_sort(long *a, int n) {
	int i, j;
	long temp;
	for (i = 1;i < n;i++) {
		temp = a[i];
		for (j = i; j > 0 && a[j - 1] > temp; j--) 
				a[j] = a[j - 1];
		a[j] = temp;
	}
}
 
// Shell Sort using Sedgewick sequence
void shellsedgewick_sort(long *a, int n) {
	int i, j, d, si;
	int Sedgewick[] = { 929, 505, 209, 109, 41, 19, 5, 1, 0 };
	long temp;
	for (si = 0;Sedgewick[si] >= n;si++)
		;
	for (;Sedgewick[si] > 0;si++) {
		d = Sedgewick[si];
		for (i = d;i < n;i++) {
			temp = a[i];
			for (j = i;j >= d && a[j - d] > temp;j -= d)
				a[j] = a[j - d];
			a[j] = temp;
		}
	}
}
 
// Heap Sort
void heap_sort(long *a, int n) {
	int i;
	long temp;
	for (i = (n - 2) / 2; i >= 0; i--)
		percdown(a, n, i);
	for (i = n - 1;i > 0;i--) {
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		percdown(a, i, 0);
	}
}
void percdown(long *a, int n, int i) {
	int child;
	long x = a[i];
	for (;i * 2 + 1 <= n - 1;i = child) {
		child = i * 2 + 1;
		if (child < n - 1 && a[child + 1] > a[child])
			child++;
		if (x >= a[child]) break;
		else a[i] = a[child];
	}
	a[i] = x;
}
 
// Merge Sort
void merge_sort(long *a, int n) {
	long *tmp = (long*)malloc(n*sizeof(long));
	if (tmp!=NULL)
	{
		msort(a, tmp, 0, n - 1);
	    free(tmp);
	}
	else
	{
		printf("No space!");
		return -1;
	}
}
void msort(long *a, long *tmp, int start, int end) {
	int middle;
	if (start < end) {
		middle = (start + end) / 2;
		msort(a, tmp, start, middle);
		msort(a, tmp, middle + 1, end);
		merge(a, tmp, start, end, middle);
	}
} 
void merge(long *a, long *tmp, int start, int end, int middle) {
	int l, r, s;
	s = start;
	l = start;
	r = middle + 1;
	while (l <= middle && r <= end) {
		if (a[l] <= a[r]) tmp[s++] = a[l++];
		else tmp[s++] = a[r++];
	}
	while (l <= middle) tmp[s++] = a[l++];
	while (r <= end) tmp[s++] = a[r++];
	for (;start <= end;start++)
		a[start] = tmp[start];
}

// Quick Sort
void quick_sort(long *a, int n) {
	q_sort(a, 0, n - 1);
}
 
void q_sort(long *a, int left, int right) {
	long pivot, temp;
	int i, j, center;
 
	if (right - left + 1 > Cutoff) {
		center = (left + right) / 2;
		if (a[center] < a[left]) {
			temp = a[center];a[center] = a[left];a[left] = temp;
		}
		if (a[right] < a[left]) {
			temp = a[right];a[right] = a[left];a[left] = temp;
		}
		if (a[right] < a[center]) {
			temp = a[right];a[right] = a[center];a[center] = temp;
		}
		temp = a[right - 1];a[right - 1] = a[center];a[center] = temp;
		pivot = a[right - 1];
 
		i = left;
		j = right - 1;
		for (;;) {
			while (a[++i] < pivot);
			while (a[--j] > pivot);
			if (i < j) {
				temp = a[i];a[i] = a[j];a[j] = temp;
			}
			else break;
		}
		temp = a[i];a[i] = a[right - 1];a[right - 1] = temp;
 
		q_sort(a, left, i - 1);
		q_sort(a, i + 1, right);
	}
	else
		insertion_sort(a + left, right - left + 1);
}