#include <stdio.h>
#include <stdbool.h>

typedef struct node *node_ptr;

struct node {
    int data;
    node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr POSITION;

int is_empty(LIST L) {
    return L == NULL || L->next == NULL;
}

int main() {
    LIST L = NULL;

    bool p = is_empty(L);

    if (p) {
        printf("List is empty\n");
    } else {
        printf("List is not empty\n");
    }

    return 0;
}
