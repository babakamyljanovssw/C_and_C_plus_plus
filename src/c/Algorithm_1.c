/*
5
green
red
blue
red
red
3
pink
orange
pink
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

enum entry{legitimate,empty,deleted};
struct Node
{
    char* colour;
    int count;
    enum entry info;
};
typedef struct Node cell;
struct hashTable
{
    unsigned int table_size;
    cell* cells;
};
typedef struct hashTable* HASH_TABLE;

int nextprime(unsigned int n)
{
    int k;
    while (k != 2)
    {
        k = 0;
        n++;
        for (int i = 1; i < n/2; i++)
        {
            if (n % i == 0)
            k++;
        }
        k++;
    }
    return n;
}
HASH_TABLE initialize(unsigned int n)
{
    if(n < 3) {
        printf("Table size is to small!\n");
        return NULL;
    }
    HASH_TABLE H;
    H = (HASH_TABLE)malloc(sizeof(struct hashTable));
    if(H == NULL) {
        printf("Out of space, unsuccess to allocate memory!\n");
        return NULL;
    }

    H->table_size = nextprime(n);
    H->cells = (cell*)malloc(sizeof(struct Node) * H->table_size);
    if(H->cells == NULL)
    {
        printf("Out of space, unsuccess to allocate memory!\n");
        return NULL;
    }
    int i;
    for ( i = 0; i < H->table_size; i++)
    {
        H->cells[i].colour = 0;
        H->cells[i].count = 0;
        H->cells[i].info = empty;
    }
    return H;
}
void Dispose(HASH_TABLE H)
{
    free(H->cells);
    free(H);
}
int hash(int i,int size)
{
    return i % size;
}
void insert(HASH_TABLE H,char key[])
{
    int index;
    index = hash(key[0],H->table_size);


    if (H->cells[index].info == empty)
    {
        H->cells[index].colour = strdup(key);
        H->cells[index].count++;
        H->cells[index].info = legitimate;
        return;
    }
    else if (!strcmp(H->cells[index].colour,key))
    {
        H->cells[index].count++;
        return;
    }
    int k = key[0];
    while (H->cells[index].info != empty && strcmp(H->cells[index].colour,key))
    {
        k++;
        index = k % H->table_size;
    }

    H->cells[index].colour = strdup(key);
    H->cells[index].count++;
    H->cells[index].info = legitimate;
    return;
}
int main()
{
    HASH_TABLE H = initialize(10);
    int n,i;
    scanf("%d",&n);
    while (n != 0)
    {
        char s[15];
        for ( i = 0; i < n; i++)
        {
            scanf("%s",&s);
            insert(H,s);
        }
    }
    Dispose(H);
    return 0;
}