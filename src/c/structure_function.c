#include<stdio.h>
#include<stdlib.h>
// structure members as argument of function
/*struct student
{
    char name[50];
    int age;
    int roll_no;
    float marks;
};
void print(char name[], int age, int roll_no, float marks)
{
    printf("%s %d %d %.2f", name, age, roll_no, marks);
}
int main()
{
    struct student s1 = {"Tomas",20,30,83.2};
    print(s1.name,s1.age,s1.roll_no,s1.marks);
}*/

// call by reference, instead of passing the copies of the structure members, we can pass their addresses
/*struct charset
{
    char s;
    int i;
};
void keyValue(char* s, int* i)
{
    scanf("%c %d",s,i);
}
int main()
{
    int j;
    struct charset cs;
    keyValue(&cs.s, &cs.i);
    printf("%c %d", cs.s, cs.i);
    return 0;
}*/

// structure variable as an argument of function. 
/*struct point
{
    int x;
    int y;
};
void print(struct point p)
{
    printf("%d %d\n",p.x,p.y);
}
int main()
{
    struct point p1 = {12,36};
    struct point p2 = {23,15};
    print(p1); // call by value
    print(p2);
    return 0;
}*/

// passing pointers to structures as arguments,this way is very good when structure has many arguments
/*struct point
{
    int x;
    int y;
};
void print(struct point *ptr)
{
    printf("%d %d\n",ptr->x,ptr->y);
}
int main()
{
    struct point p1 = {12,45};
    struct point p2 = {25,56};
    print(&p1);
    print(&p2);
    return 0;
}*/

// returning a structure variable from the function
/*struct point
{
    int x;
    int y;
};
struct point edit(struct point p)
{
    (p.x)++;
    p.y = p.y + 5;
    return p;
};
void print(struct point p)
{
    printf("%d %d\n",p.x,p.y);
}
int main()
{
    struct point p1 = {12,25};
    struct point p2 = {45,56};
    p1 = edit(p1);
    p2 = edit(p2);
    print(p1);
    print(p2);
    return 0;
}*/

// returning a pointer to a structure from the function
/*struct point
{
    int x;
    int y;
};
struct point* fun(int a, int b)
{
    struct point *ptr = (struct point*)malloc(sizeof(struct point));
    ptr->x = a;
    ptr->y = b + 5;
    return ptr;
}
void print(struct point *ptr)
{
    printf("%d %d\n",ptr->x,ptr->y);
}
int main()
{
    struct point *ptr1, *ptr2;
    ptr1 = fun(2,3);
    ptr2 = fun (4,5);
    print(ptr1);
    print(ptr2);
    free(ptr1);
    free(ptr2);
    return 0;
}*/

// passing array of structures as argument
/*struct point
{
    int x;
    int y;
};
void print(struct point arr[])
{
    int i;
    for ( i = 0; i < 2; i++)
    {
        printf("%d %d\n", arr[i].x,arr[i].y);
    }
}
int main()
{
    struct point arr[2] = {{2,3},{4,5}};
    print(arr);
    return 0;
}*/

// self referential structures: are those structures in which one or more pointers points to the structure of the same type
// self referential structures are useful in linked list data structure
struct code
{
    int i;
    char c;
    struct code *ptr;
};
int main()
{
    struct code var1;
    struct code var2;

    var1.i = 65;
    var1.c = 'A';
    var1.ptr = NULL;

    var2.i = 66;
    var2.c = 'B';
    var2.ptr = NULL;

    var1.ptr = &var2;
    printf("%d %c\n",var1.ptr->i, var1.ptr->c);

    return 0;
}



