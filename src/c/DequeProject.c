#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>

#define ERROR (-1)*(int)pow(10,9)
struct Deque;
struct Deque* CreateDeque();           // Create an empty deque
int Push(int X);     // Insert item X on the front end of deque D
int Pop();            // Remove the front item from deque D and return it
int Inject(int X); // Insert item X on the rear end of deque D
int Eject();        // Remove the rear item from deque D and return it
bool IsEmpty();
struct Deque* Front = NULL;
struct Deque* Rear = NULL;
struct Deque* D;
struct Deque
{
    int data;
    struct Deque* prev;
    struct Deque* next;
};
struct Deque* CreateDeque()
{
    struct Deque* D = malloc(sizeof(struct Deque));
    if(D == NULL)
    {
        printf("Out of Space!\n");
        return NULL;
    }
    else return D;

}
int Push(int X)
{
    struct Deque* TmpCell = (struct Deque*)malloc(sizeof(struct Deque));
    if (TmpCell == NULL)
    {
        printf("Fail. Out of Space!\n");
        return 0;
    }
    if (Front == NULL && Rear == NULL)
    {
        D->data = X;
        D->prev = NULL;
        D->next = NULL;
        Front = D;
        Rear = D;
    }
    else
    {
        TmpCell->data = X;
        TmpCell->prev = NULL;
        TmpCell->next = Front;
        Front->prev = TmpCell;
        Front = TmpCell;
        D = Front;
    }
    return 1;
}
int Pop()
{
    struct Deque* TmpCell = Front;
    if(Front == NULL && Rear == NULL)
    {
        return ERROR;
    }
    else
    {
        int value = Front->data;
        Front = Front->next;
        D = Front;
        free(TmpCell);
        return value;
    }
}
int Inject(int X)
{
    struct Deque* TmpCell = (struct Deque*)malloc(sizeof(struct Deque));
    if (TmpCell == NULL)
    {
        printf("Fail. Out of Space!\n");
        return 0;
    }
    if (Front == NULL && Rear == NULL)
    {
        D->data = X;
        D->prev = NULL;
        D->next = NULL;
        Front = D;
        Rear = D;
    }
    else
    {
        TmpCell->data = X;
        TmpCell->prev = Rear;
        TmpCell->next = NULL;
        Rear->next = TmpCell;
        Rear = TmpCell;
    }
    return 1;
}
int Eject()
{
    struct Deque* TmpCell = Rear;
    if (Front == NULL && Rear == NULL)
    {
        return ERROR;
    }
    else
    {
        int value = Rear->data;
        Rear = Rear->prev;
        free(TmpCell);
        return value;
    }
}
int main()
{
    D = CreateDeque();
    int X;

    X = Pop();
    if(X == ERROR) printf("Pop Error %d\n",ERROR);
    else printf("Pop element = %d\n",X);

    X = Eject();
    if(X == ERROR) printf("Eject Error %d\n",ERROR);
    else printf("Eject element = %d\n",X);

    if(Push(15)) printf("Push success\n"); else printf("Push not success\n");
    if(Push(20)) printf("Push success\n"); else printf("Push not success\n");
    if(Push(12)) printf("Push success\n"); else printf("Push not success\n");
    if(Push(18)) printf("Push success\n"); else printf("Push not success\n");

    X = Pop();
    if(X == ERROR) printf("Pop Error %d\n",ERROR);
    else printf("Pop element = %d\n",X);

    if(Inject(16)) printf("Inject success\n"); else printf("Inject not success\n");
    if(Inject(25)) printf("Inject success\n"); else printf("Inject not success\n");

    X = Eject();
    if(X == ERROR) printf("Eject Error %d\n",ERROR);
    else printf("Eject element = %d\n",X);

    return 0;
}