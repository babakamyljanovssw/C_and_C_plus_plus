#include<stdio.h>
#include<stdlib.h>
int main()
{
    /*long long value1 = 100000, value2;
    long long *llptr;
    llptr = &value1;
    printf("%lld\n",*llptr);*/
    
    int *p = (int*)malloc(10*sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        *(p+i) = 5;
    }
    free(p);
    char *str = (char*)malloc(12*sizeof(char));
    str = "This string";
    printf("%s\n",str);
    free(str);
    return 0;
}