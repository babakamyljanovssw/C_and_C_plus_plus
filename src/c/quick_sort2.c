#include<stdio.h>
#include<stdlib.h>
#define size 100000
int Partition(long *A, int start, int end);
void QSort(long *A, int start, int end);
void QuickSort(long *A, int N);

int main()
{
    long A[size];
    int N;
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%ld", &A[i]);
    }
    QuickSort(A,N);
    printf("%ld",A[0]);
    for (int i = 1; i < N; i++)
    {
        printf(" %ld", A[i]);
    }
    return 0;
}
void QuickSort(long *A, int N)
{
    QSort(A, 0, N-1);
}
void QSort(long *A, int start, int end)
{
    if (start<end)
    {
        int pIndex = Partition(A, start, end);
        QSort(A,start,pIndex-1);
        QSort(A,pIndex+1,end);
    } 
}
int Partition(long *A, int start, int end)
{
    int pivot = A[end];
    int temp, pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (A[i]<=pivot)
        {
            temp = A[i];
            A[i] = A[pIndex];
            A[pIndex] = temp;
            pIndex++;
        }
    }
    temp = A[pIndex]; 
    A[pIndex] = A[end]; 
    A[end] = temp;
    return pIndex;
}