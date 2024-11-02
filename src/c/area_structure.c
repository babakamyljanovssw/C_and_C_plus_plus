#include<stdio.h>
struct point
{
    int x;
    int y;
};
struct rectangle
{
    struct point upper_left;
    struct point lower_right;
};
int area(struct rectangle r)
{
    int length, breadth;
    length = r.lower_right.x-r.upper_left.x;
    breadth = r.upper_left.y - r.lower_right.y;
    return length * breadth;
}
int main()
{
    struct rectangle r;
    printf("Enter the upper left coordinates of te rectangle: \n");
    scanf("%d %d",&x, &r.upper_left.y);
    printf("Enter the lower right coordinates of the rectangle: \n");
    scanf("%d %d", &r.lower_right.x, &r.lower_right.y);
    printf("The are of the rectangle = %d\n",area(r));
    return 0;
}