#include<stdio.h>
/*struct 
{
    char *engine;
} car1, car2;
int main()
{
    car1.engine = "DDis 190 Engine";
    car2.engine = "1.2 L Kappa Dual VTVT";
    printf("%s\n",car1.engine);
    printf("%s\n",car2.engine);
    return 0;
}*/

/*struct employee
{
    char *name;
    int age;
    int salary;
};
int manager()
{
    struct employee manager;
    ////
}
int main()
{
    struct employee emp1;
    struct employee emp2;
    ////
}*/
/*typedef struct car  // old type
{
    char *engine;
    char *fueltype;
    int fueltankcap;
    int seatingcap;
    float citymileage;
}car;         // new type
int main()
{
    car c1;
    //////
}*/

/*struct car
{
    char engine[50];
    char fueltype[10];
    int fueltankcap;
    int seatingcap;
    float citymileage;
}car;
struct abc
{
    int x;
    int y;
    int z;
};
int main()
{
    struct car c1 = {"DDis 190 Engine", "Diesel", 37, 5, 19.74};
    struct car c2 = {"Kappa", "Petrol", 22, 8, 14.5};
    struct abc a = {.y = 20, .x = 10, .z = 30};
    printf("%d %d %d",a.x, a.y, a.z);
    return 0;
}*/

/*struct employee
{
    char name[50];
    int age;
    int salary;
};
int main()
{
    struct employee emp[2];
    int i;
    for ( i = 0; i < 2; i++)
    {
        printf("Enter the employee %d name: ",i+1);
        scanf("%s",&emp[i].name);
        printf("Enter the employee %d age: ", i+1);
        scanf("%d",&emp[i].age);
        printf("Enter the employee %d salarY: ", i+1);
        scanf("%d",&emp[i].salary);
    }
    printf("\n");
    for ( i = 0; i < 2; i++)
    {
        printf("\nEmployee %d details: \n",i+1);
        printf("Name: %s\n",emp[i].name);
        printf("Age: %d\n", emp[i].age);
        printf("Salary: %d\n", emp[i].salary);
    }
    return 0;
}*/

/*struct abc
{
    int x;
    int y;
};
int main()
{
    struct abc a = {0, 1};
    struct abc *ptr = &a;
    printf("%d %d", ptr->x, ptr->y); // ptr->x is equivalent to (*ptr).x
    return 0;
}*/

// structure padding. for not waste memory we can declare #progma(1)
/*struct abc
{
    char a; // 1 byte
    char b; // 1 byte
    int c; // 2 bytes
};
int main()
{
    struct abc var;
    printf("%d",sizeof(var));
    return 0;
}*/
#pragma pack(1)
struct store
{
    double price;
    union
    {
        struct
        {
            char *title;
            char *author;
            int num_pages;
        }book;
        struct
        {
            int color;
            int size;
            char *design;
        }shirt;
    }item;    
};
int main()
{
    struct store s;
    s.item.book.title = "The Alchemist";
    s.item.book.author = "Paulo Coelho";
    s.item.book.num_pages = 197;
    printf("%s\n", s.item.book.title);
    printf("%d\n",sizeof(s));
    return 0;
}



