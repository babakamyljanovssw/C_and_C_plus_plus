#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define MAX_ARRAY_LIMIT 100
#define RANDOM_BASE     50
void randomGenerator(int *a, int size);
void SelectKthLargest(int *a, int size, int kth);
static int cmpinteger(const void *p1, const void *p2);
void ArrayPrint(int *a, int start, int end);
void resortKth(int *a, int kth);
 
int main()
{
 
    int a[MAX_ARRAY_LIMIT] = {0};
    int k = 20;
    int i = 0;
 
    (void)randomGenerator(a, MAX_ARRAY_LIMIT);
     
    fprintf(stdout, "Random Generator generates Array as following:\n");

    /* Here only print out little part of this array 
      If MAX_ARRAY_LIMIT is greater than  a thousand,
      only print 10 percents of those data in the array.
     */

    if(MAX_ARRAY_LIMIT > 10000)
    {
        /* Print 4% data */
        while(i < MAX_ARRAY_LIMIT)
        {
            (void)ArrayPrint(a, i, i+40);
            i+=1000;
        }
    } else if(MAX_ARRAY_LIMIT > 5000)
    {
        while(i < MAX_ARRAY_LIMIT) {
            (void)ArrayPrint(a, i, i+40);
            i+=800;
        }
    }
    else if(MAX_ARRAY_LIMIT > 1000)
    {
        while(i < MAX_ARRAY_LIMIT) {
            (void)ArrayPrint(a, i, i+40);
            i+=400;
        }
    }
    else if(MAX_ARRAY_LIMIT > 400)
    {
        while(i < MAX_ARRAY_LIMIT) {
            (void)ArrayPrint(a, i, i+40);
            i+=100;
        }
    }
    else if(MAX_ARRAY_LIMIT > 200)
    {
        while(i < MAX_ARRAY_LIMIT) {
            (void) ArrayPrint(a, i, i+40);
            i+=40;
        }
    }
    else
        (void) ArrayPrint(a, i, i+MAX_ARRAY_LIMIT);
 
    (void)ArrayPrint(a, 0, MAX_ARRAY_LIMIT);
 
    fprintf(stdout, "And the first %d ones are : \n", k);
    (void)ArrayPrint(a, 0, k);
     
    SelectKthLargest(a, MAX_ARRAY_LIMIT, k);
    printf("Print the array after sorting :\n");
    (void)ArrayPrint(a, 0, MAX_ARRAY_LIMIT);
 
    printf("The %4dth largest value is : %4d\n", k, *(a+k-1));
     
 
    exit(EXIT_SUCCESS);
}
 
void ArrayPrint(int *a, int start, int end)
{
    int i = 0;
    for(i = start;i < end; i++){
        if((i - start) % 10 == 0)
            fprintf(stdout, "\n");
        fprintf(stdout, "\t%4d", *(a+i));
    }
    fprintf(stdout, "\n");
}
 
void randomGenerator(int *a, int size)
{
    int i = 0;
 
    for(; i < size; i++)
        *(a+i) =(int)rand()%RANDOM_BASE;
}
 
void resortKth(int *a, int kth)
{
    int i = kth - 2; /* The 2th last in the a[0],a[1], ...,a[kth - 2], a[kth - 1] */
    int tmp;
    int j;
    while((*(a + kth - 1) > *(a+i)) && i > 0) 
        i--;
     
    tmp = *(a+kth - 1);
    for(j = kth - 2; j > i; j--) {
        *(a+j+1) = *(a+j);
    }
 
    *(a+j) = tmp;
}
 
static int cmpinteger(const void *p1, const void *p2)
{
    return ((*(int *const *)p1) < (*(int * const *)p2));
}
 
void SelectKthLargest(int *a, int size, int kth)
{
    assert(kth < size);
    /* Sort the first k data in decreasing order */
    qsort(a, kth, sizeof(int), cmpinteger);
 
    (void)ArrayPrint(a, 0, kth);
 
    /* Now remaining element is read one by one. As a new
      element arrives, it's ignored if it's smaller than the
      kth element in the array. Otherwise, it's placed in its
      correct spot in the array, bumping one element out of the
      array. When the algorithms ends, the element in the kth
      position is returned as the answer
     */
    /* loop */
    int i = kth;
    int base = *(a + kth - 1);
    int tmp;
 
    for(; i < size; i++) {
        if(*(a+i) > *(a + kth - 1)) {
            /* Swap Value */
            tmp = *(a+ kth -1 );
            *(a+ kth -1 ) = *(a+i);
            *(a+i) = tmp;
 
            /* Resort the first k data */
            (void)resortKth(a, kth);
        }
    }
}