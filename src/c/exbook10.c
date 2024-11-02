#include<stdio.h>
void find_ijmax(int nrow, int ncol, int a[nrow][ncol], int *i_maxp, int *j_maxp)
{
    int maxvalue = a[0][0];
    for (int i = 0; i < nrow; i++)
    {
        for (int j = 0; j < ncol; j++)
        {
            if (a[i][j]>maxvalue)
            {
                maxvalue = a[i][j];
                *i_maxp = i;
                *j_maxp = j;
            }
        }
    }
}
int main()
{
    int nrow, ncol, i_maxp, j_maxp;
    scanf("%d %d",&nrow,&ncol);
    int a[nrow][ncol];
    for (int i = 0; i < nrow; i++)
    {
        for (int j = 0; j < ncol; j++)
        {
            scanf("%d",&a[i][j]);
        } 
    }
    find_ijmax(nrow,ncol,a,&i_maxp,&j_maxp);
    printf("Indices of max value are %d's row %d column",i_maxp+1,j_maxp+1);
    return 0; 
}