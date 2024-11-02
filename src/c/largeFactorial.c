#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 300000 // max size of array
int multiply(int k,int result[], int result_size);

void factorial(int n)
{
    int result[MAX_SIZE]; // array to store large number
    // initialzing first element of array and size as 1
    result[0] = 1; 
    int result_size = 1;

    for (int k = 2; k <= n; k++)
    {
        result_size = multiply(k,result,result_size);
    }

    printf("Factorial of %d is: ",n);
    printf("Number of digits: %d\n",result_size);
    // printing array in reverse order. because number stored in reverse order
    for (int i = result_size - 1; i >= 0; i--)
    {
        printf("%d",result[i]);
    }
}
int multiply(int k,int result[], int result_size)
{
    int carry = 0;
    for (int i = 0; i < result_size; i++)
    {
        // multiplying k with ith digit and adding carry
        int product = result[i] * k + carry;
        // store last digit
        result[i] = product % 10;
        //put rest in carr
        carry = product / 10;
    }
    // if carry is not 0 then add it to the array and divide 10 until it gets 0
    while (carry)
    {
        result[result_size] = carry % 10;
        carry = carry / 10;
        result_size++;
    }
    return result_size;
}
int main()
{
    int n;
    printf("number = ");
    scanf("%d",&n);

    clock_t t = clock();
    factorial(n);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f\n",time_taken);
    
    system("pause");
    return 0;
}