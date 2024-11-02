#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 100
int B[MAXSIZE];

bool IsSame(int A[], int B[], int N) {
     for (int i = 0; i < N; i++) {
        if (A[i] != B[i])
            return false;
    }
    return true;
}

void Print(int A[], int N) {
    printf("%d", A[0]);
    for (int i = 1; i < N; i++) {
        printf(" %d", A[i]);
    }
    printf("\n");
}

void PercDown(int A[], int N, int p) {
    int parent, child;
    int temp = A[p];
    for (parent = p; 2 * parent + 1 < N; parent = child) {
        child = 2 * parent + 1;
        if (child + 1 < N && A[child + 1] > A[child])
            child++;
        if (temp < A[child])
            A[parent] = A[child];
        else
            break;
    }
    A[parent] = temp;
}

void Heap_Sort(int A[], int N) {
    for (int p = N / 2 - 1; p >= 0; p--)
        PercDown(A, N, p);
    for (int i = N - 1; i > 0; i--) {
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;

        PercDown(A, i, 0);

        if (IsSame(A, B, N)) {
            temp = A[--i];
            A[i] = A[0];
            A[0] = temp;
            PercDown(A, i, 0);

            printf("Heap Sort\n");
            Print(A, N);
            return;
        }
    }
}

void InsertSort(int A[],int N) {
	int temp,i,j;
	for(i = 1; i < N; i++) {
		temp = A[i];
		for(j=i; j>0 && A[j-1]> temp; j--)
			A[j] = A[j-1];
		A[j] = temp;
		
		if(IsSame(A,B,N)) {
			temp = A[++i];
			for(j=i; j>0 && A[j-1]> temp; j--)
				A[j] = A[j-1];
			A[j] = temp;
            printf("Insertion Sort\n");
            Print(A, N);
			return ;
		}
	}
}
int main()
{
    int N, A[MAXSIZE];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &B[i]);

    int insert_A[MAXSIZE], heap_A[MAXSIZE];
    for (int i = 0; i < N; i++) {
        insert_A[i] = A[i];
        heap_A[i] = A[i];
    }

    InsertSort(insert_A, N);
    Heap_Sort(heap_A, N);
    return 0;
}