#include<stdio.h>
void Double(int* A, int size) // int* A or int A[] are same
{
    int i, sum = 0;
    for (i = 0; i < size; i++)
    {
        //sum+= A[i]; // *(A+i)
        A[i] = 2*A[i];
    }
} 

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    /*printf("%d\n",A);   // A+i
    printf("%d\n", *A); // *(A+i)
    printf("%d\n",&A[0]); // &A[i]
    printf("%d", A[0]);   // A[i]
    int *p = A; // p = &A[0]
    p++;*/

    int size = sizeof(A)/sizeof(A[0]);
    Double(A, size); // A can be used for &A[0]
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}