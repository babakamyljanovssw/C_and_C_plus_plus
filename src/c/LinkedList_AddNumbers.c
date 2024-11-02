#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *next;
};
//insert at the beginning
void insert2(struct node** head,int X)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp != NULL)
    {
        temp->data = X;
        temp->next = *head;
        *head = temp;
        return;
    }
    else
    {
        printf("Out of space!\n");
        return;
    }
}
// insert at the end
void insert(struct node** head,int X)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = X;
    temp->next = NULL;
    if(temp == NULL)
    {
        printf("no space!\n");
        return;
    }
    else if (*head == NULL)
    {
        *head = temp;
        return;
    }
    struct node *p = *head;
    while(p->next != NULL) 
    p = p->next;

    if(p->next == NULL)
    p->next = temp;
    
}
struct node* Add_Two_Numbers(struct node *L1,struct node *L2)
{
    struct node *L3, *temp;
    char str1[100], str2[100], str3[100];
    int i,j,length1,length2,num1,num2,left;
    char c;
    L3 = NULL;
    // whether two given lists are empty return NULL
    if(L1 == NULL || L2 == NULL) return NULL;
    // whether list1 and list2 only have 1 node and it stores zero as values
    else if(L1->data == 0 && L1->next == NULL && L2->data == 0 && L2->next == NULL) return L1;
    // whether
    else if(L1->data != 0 && L2->data == 0 && L2->next == NULL) return L1;
    // whether
    else if(L1->data == 0 && L1->next == NULL && L2->data != 0) return L2;
    
    // creating string type for number1 to access each digit
    length1 = 0;
    temp = L1;
    while (temp != NULL)
    {
        c = temp->data + '0';
        str1[length1] = c;
        temp = temp->next;
        ++length1;
    }
    // creating string type for number2 to access each digit
    length2 = 0;
    temp = L2;
    while (temp != NULL)
    {
        c = temp->data + '0';
        str2[length2] = c;
        temp = temp->next;
        ++length2;
    }
    left = 0;
    if(length1 > length2)
    {
        i = length1 - 1;
        j = length2 - 1;
        while (i >= 0)
        {
            if(j >= 0)
            {
                num1 = str1[i] - '0';
                num2 = str2[j] - '0';
                num1 = left + num1 + num2;
                insert2(&L3,num1 % 10);
                left = num1 / 10;
                --i;
                --j;
            }
            else if(j <= 0)
            {
                num1 = str1[i] - '0' + left;
                insert2(&L3,num1 % 10);
                left = num1 / 10;
                --i;
            }
        }
        if(left != 0)
        insert2(&L3,left);
    }
    else
    {
        i = length2 - 1;
        j = length1 - 1;
        while (i >= 0)
        {
            if(j >= 0)
            {
                num1 = str2[i] - '0';
                num2 = str1[j] - '0';
                num1 = left + num1 + num2;
                insert2(&L3,num1 % 10);
                left = num1 / 10;
                --i;
                --j;
            }
            else if(j <= 0)
            {
                num1 = str2[i] - '0' + left;
                insert2(&L3,num1 % 10);
                left = num1 / 10;
                --i;
            }
        }
        if(left != 0)
        insert2(&L3,left);
    }
    return L3;
}

void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct node *L1 = NULL;
    struct node *L2 = NULL;
    struct node *L3 = NULL;
    int n1,n2,X;
    printf("\nnumber of nodes first list= ");
    scanf("%d",&n1);
    for(int i = 0; i < n1; i++)
    {
        scanf("%d",&X);
        insert(&L1,X);
    }
    printf("\nnumber of nodes first list= ");
    scanf("%d",&n1);
    for(int i = 0; i < n1; i++)
    {
        scanf("%d",&X);
        insert(&L2,X);
    }
    L3 = Add_Two_Numbers(L1,L2);
    printf("\nNew added linked list: ");
    print(L3);
    return 0;
}