#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char** generate_Parenthesis(int n, char *str1)
{
    int i, j, length, size, pair_count = 0, k, l;
    length = strlen(str1);
    char *array[100]; // array of strings
    char temp;
    // copy string 1 to string 2
    char str2[2*n];
    strcpy(str2,str1);
    int visited[length];
    size = 0;
    array[size] = malloc(length+1);
    strcpy(array[size],str1);
    
    char **ptr = array;
    k = 1;
    l = length/2;

    // O(n) n=length
    for( i = 0; i < length; i++) visited[i] = 0;
    
    for ( i = length/2-1; i < length-1; )
    {
        if(i+1 != length-1 && str2[i] == '(' && str2[i+1] == ')' && !visited[i])
        {
            temp = str2[i];
            str2[i] = str2[i+1];
            str2[i+1] = temp;
            array[++size] = malloc(length+1);
            strcpy(array[size],str2);
            i++;
        }
        else if(i+1 == length-1)
        {
            if(++pair_count < n-1)
            {
                visited[k-1] = visited[k] = 1;
                temp = str1[l];
                str1[l] = str1[k];
                str1[k] = temp;
                k += 2;
                l++;
                array[++size] = malloc(length+1);
                strcpy(array[size],str1);
                strcpy(str2,str1);
                i = length/2-1;
            }
            else i++;
        }
        else i++;
    }
    array[++size] = NULL;
    return ptr;
}

int main()
{
    int n;
    printf("Enter number of pairs: ");
    scanf("%d",&n);
    char c[2*n];

    int i,j;
    for ( i = 0, j = 2*n; i < n;)
    {
        c[i++] = '(';
        c[--j] = ')';
    }
    c[2*n] = '\0';
    char **str = generate_Parenthesis(n,c);
    i = 0;
    while (str[i] != NULL)
    {
        printf("%s\n",str[i]);
        i++;
    }
    system("pause");
}