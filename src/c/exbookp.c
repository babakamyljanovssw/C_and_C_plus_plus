#include<stdio.h>
#define Year 2
#define Month 12
const char *month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
int main()
{
    int a[][Month] = {367, 654, 545, 556, 565, 526, 437, 389, 689, 554, 526, 625,
                  429, 644, 586, 626, 652, 546, 449, 689, 597, 679, 696, 568};
    int total = 0;
    double average;
    printf("%-10s%-10s\n","Month", "Sales(x1,000 $)");
    printf("---------------------------------------\n");
    for (int i = 0; i < Month; i++)
    {
        for (int j = 0; j < Year; j++)
        {
            total += a[j][i]; 
        }
        average = (double)total/(double)Year;
        printf("%-10s%8.2f\n",month[i],average);
        total = 0;
    }
    return 0;
}