#include<stdio.h>
int compare(int a, int b)
{
    if (a>b) return 1;
    else return -1;
}
void bubblesort(int *A, int n, int(*compare)(int,int))
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n-1; j++)
        {
            if (compare(A[j],A[j+1]) > 0)
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
}
int main()
{
    int A[] = {9,4,1,2,5,6,3};
    bubblesort(A,7,compare);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ",A[i]);
    }
    
}