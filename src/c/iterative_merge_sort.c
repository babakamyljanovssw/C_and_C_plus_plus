#include <stdio.h>

#define ElementType int
#define MAXN 100

void merge_pass( ElementType list[], ElementType sorted[], int N, int length ){
    for (int i=0; i<N; i=i+2*length) {
        int p1,p2,p3;
        p1=i;
        p2=i+length;
        p3=p1;
        while (p1<i+length&&p2<i+length+length&&p1<N&&p2<N) {
            if(list[p1]<list[p2]){
                sorted[p3]=list[p1];
                p3++;
                p1++;
            }
            else{
                sorted[p3]=list[p2];
                p3++;
                p2++;
            }
        }
        if(p1==i+length){
            while (p2<i+length+length) {
                sorted[p3]=list[p2];
                p3++;
                p2++;
            }
        }
        if(p2==i+length+length){
            while (p1<i+length) {
                sorted[p3]=list[p1];
                p3++;
                p1++;
            }
        }
        if(p2>=N){
            while (p1<i+length) {
                sorted[p3]=list[p1];
                p3++;
                p1++;
            }
        }
        if(p1>=N){
            while (p2<i+length) {
                sorted[p3]=list[p2];
                p3++;
                p2++;
            }
        }
    }
}

void output( ElementType list[], int N )
{
    int i;
    for (i=0; i<N; i++) printf("%d ", list[i]);
    printf("\n");
}

void  merge_sort( ElementType list[],  int N )
{
    ElementType extra[MAXN];  /* the extra space required */
    int  length = 1;  /* current length of sublist being merged */
    while( length < N ) { 
        merge_pass( list, extra, N, length ); /* merge list into extra */
        output( extra, N );
        length *= 2;
        merge_pass( extra, list, N, length ); /* merge extra back to list */
        output( list, N );
        length *= 2;
    }
} 


int main()
{
    int N, i;
    ElementType A[MAXN];

    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%d", &A[i]);
    merge_sort(A, N);
    output(A, N);

    return 0;
}