// the reasons we use instead #define 1.Enums can be declared in the local scope. Enum names are automatically initialized by the compiler
// fact1 two or  more names can have same value
// fact2 we can assign values in any order. All unassigned names will get value as value of previous name +1
// fact3 only integral values are allowed.
// fact4 All enum constant must be unique in their scope
#include<stdio.h>
enum Bool {False, True};
int main()
{
    enum Bool var;
    var = True;
    printf("%d\n",var);

    enum point {x = 0, y = 0, z = 0};
    printf("%d %d %d\n",x,y,z);
    return 0;
}