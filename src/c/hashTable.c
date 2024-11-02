// hash table using linear probing
#include <stdio.h>
#include <stdlib.h>

#define min_tableSize = 11

typedef struct Node* Node_ptr;
struct Node
{
    int data;
    Node_ptr next;
};
typedef Node_ptr List;
typedef Node_ptr Position;

struct hashTable
{
    unsigned int table_size;
    List* table_list;
}
typedef struct hashTable* HASH_TABLE;

HASH_TABLE initialize(unsigned int size)
{
    HASH_TABLE H;
    if (size < min_tableSize)
    {
        printf("Table size is small");
        return NULL;
    }
    
    H = (HASH_TABLE)malloc(sizeof(HASH_TABLE)*)
}