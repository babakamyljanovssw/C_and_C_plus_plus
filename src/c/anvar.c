#include "anvar.h"
#include <stdlib.h>
#include "anvar2.h"

List L = NULL;

List MakeEmpty( List L )
{
    if( L != NULL )
        DeleteList( L );
    L =(PtrToNode)malloc( sizeof( struct Node));
    if( L == NULL )
        FatalError( "Out of memory!" );
    L->Next = NULL;
    return L;
}

int IsEmpty( List L )
{
    return L->Next == NULL;
}

int IsLast( Position P, List L )
{
    return P->Next == NULL;
}

Position Find( ElementType X, List L )
{
    Position P;
    P = L->Next;
    while( P != NULL && P->Element != X )
        P = P->Next;
    return P;
}

void Delete( ElementType X, List L )
{
    Position P, TmpCell;

    P = FindPrevious( X, L );

    if( !IsLast( P, L ) )
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free( TmpCell );
    }
}

Position FindPrevious( ElementType X, List L )
{
    Position P;
    P = L;
    while( P->Next != NULL && P->Next->Element != X )
        P = P->Next;

    return P;
}

void Insert( ElementType X, List L, Position P )
{
    Position TmpCell;
    TmpCell = (PtrToNode)malloc( sizeof( struct Node ) );
    if( TmpCell == NULL )
        FatalError( "Out of space!!!" );

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}


void DeleteList( List L )
{
    Position P, Tmp;
    P = L->Next;
    L->Next = NULL;
    while( P != NULL )
    {
        Tmp = P->Next;
        free( P );
        P = Tmp;
    }
}


Position Header( List L )
{
    return L;
}

Position First( List L )
{
    return L->Next;
}

Position Advance( Position P )
{
    return P->Next;
}

ElementType Retrieve( Position P )
{
    return P->Element;
}

Position GetLast(List L)
{
    Position t=L;
    while(!IsLast(t,L))
        t = t->Next;
    return t;
}

int Size(List L)
{
    int i=0;
    Position p=L->Next;
    while(!IsLast(p,L)){
        i++;
        p = p->Next;
    }
    return i;
}

void PrintList(List L)
{
    int i=1;
    Position p=L->Next;
    while(p){
        printf("%d th node:%d\n",i,p->Element);
        i++;
        p=p->Next;
    }
}

int main()
{
    char input[20];
    gets(input);
    int i = 0;

    while(input[i] != '0')
    {
        if(input[i] >= 0 && input[i] <= '9')
        {
            Insert((int)input[i], L, L);
        }
    }

    return 0;
}
