#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define min_pq_size 3
#define mindata INT_MIN
struct PriorityQueue
{
    int maxsize;
    int size;
    int *elements;
};

struct PriorityQueue* Create_PQ(int N){
    if (N < min_pq_size){
        printf("Size is too small\n");
        return NULL;
    }
    struct PriorityQueue* PQ;
    PQ = malloc(sizeof(struct PriorityQueue));
    if(PQ == NULL) {
        printf("Out of space!\n");
    }
    else{
        PQ->elements = (int*)malloc(N * sizeof(int));
        if(PQ->elements == NULL){
            printf("Out of space");
        }
        else{
            PQ->maxsize = N;
            PQ->size = 0;
            PQ->elements[0] = mindata;
            return PQ;
        }
    }
}
int main(){
    struct PriorityQueue* PQ = Create_PQ(10);
    
}