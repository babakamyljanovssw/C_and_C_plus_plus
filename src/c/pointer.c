/* Pointers - variables that store address of other variables */

#include<stdio.h>

void increment(int *p)
{
     *p = (*p)  + 1;
}
int main()
{
    int a;
    a = 10;
    increment(&a);
    printf("%d\n", a);
    /*int num = 22;          // integer
    int *n;        // pointer to integer. value at address pointed by p
    char c;       // character
    char *po;    // pointer to character
    double d;   // double
    double *p1;// pointer to double

    n = &num;  // address of value 
    printf("%d\n", n);
    printf("%d\n", &num);
    printf("%d\n", &n);
    printf("%d\n", *n); // dereferencing
    *n = 8;
    printf("%d\n", num);*/
   
    /*int a = 1025;
    int *p;
    p = &a;
printf("\n");
    printf("size of integer is %d bytes\n", sizeof(int));
    printf("Address = %d, value = %d\n", p, *p);
    printf("Address = %d, value = %d\n", p+1, *(p+1));
    
    //here as address it prints the new address by increasing 4 bytes because it is the integer datatype
    //as value it prints the garbage because we didn't store any integer that address. 
    
    printf("\n");
    char *p2;
    p2 = (char*)p; // typecasting, stores p to p2 
    printf("size of char is %d bytes\n", sizeof(char));
    printf("Address = %d, value= %d\n", p2, *p2);
    // 1025 = 00000000 00000000 00000100 00000001 
    //here the last particular byte 00000001 in binary is 1. So it will print out 1 as value
    //because when we dereferencing *p2  computer says it is pointer to character so it takes 1 byte instead of 4 bytes
    //so it takes the last particular 1 byte of address
    printf("Address = %d, value = %d\n", p2+1, *(p2+1));
    // here as address it prints the new address by increasing 1 bytes because it char datatype pointer. 
    //And it takes this particular 00000100 byte.
    //and this one in binary is equal to 4. then it prints 4 as value 
    
printf("\n");
    // void pointer - Generic pointer 
    void *p3;
    p3 = p; // typecasting. here dont need to use explicit typecasting (void*)
    printf("Address = %d\n", p3); // Here we can only print the address. We cannot use dereferencing
    //printf("Address = %d\n", p3+1); this one also gives compilation error
    */
   
   // pointer to pointer

   /*int x = 5;
   int *p = &x;
   *p = 6;
   int **q = &p;
   int ***r = &q;

   printf("%d\n", *p);

   printf("%d\n", *q);
   printf("%d\n", **q);

   printf("%d\n", **r);
   printf("%d\n", ***r);

   ***r = 10;
   printf("%d\n", x);
   **q = *p + 2;
   printf("%d\n", x);*/
   return 0;
}