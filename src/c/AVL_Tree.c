#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct AVL;
struct AVL* Insert(int X,struct AVL *root);
int Height(struct AVL *root);
int max(int a,int b);
struct AVL* LeftRotate(struct AVL *root);
struct AVL* LeftRightRotate(struct AVL *root);
struct AVL* RightRotate(struct AVL *root);
struct AVL* RightLeftRotate(struct AVL *root);
void Level_Order(struct AVL *root);

struct AVL
{
    int data;
    int height;
    struct AVL *left;
    struct AVL *right; 
};
int Height(struct AVL* root)
{
    if(root == NULL) return -1;
    else return root->height;
}
int max(int a,int b)
{
    if(a > b) return a;
    else return b;
}
struct AVL* Insert(int X,struct AVL *root)
{
    struct AVL* temp;
    if (root == NULL)
    {
        temp = malloc(sizeof(struct AVL));
        if (temp == NULL)
        {
            printf("Out of space!\n");
            return NULL;
        }
        temp->data = X;
        temp->height = 0;
        temp->left = temp->right = NULL;
        return temp;
    }
    else if (X < root->data)
    {
        root->left = Insert(X,root->left);
        if( abs( Height(root->left) - Height(root->right) ) > 1 )
        {
            if( X < root->left->data )
            root = LeftRotate(root); // single left rotation
            else
            root = LeftRightRotate(root); // double left rotation ( first do single right, then single left)
        }
    }
    else if (X > root->data)
    {
        root->right = Insert(X,root->right);
        if( abs( Height(root->left) - Height(root->right) ) > 1 )
        {
            if (X > root->right->data)
            root = RightRotate(root); // single right rotation
            else
            root = RightLeftRotate(root); // double right rotation ( first do single left, the single right )
        }
    }
    root->height = max(Height(root->left),Height(root->right)) + 1;
    return root;
}
struct AVL* LeftRotate(struct AVL *root)
{
    struct AVL *temp;
    temp = root->left;
    root->left = temp->right;
    temp->right = root;
    temp->height = max(Height(temp->left),Height(temp->right))+1;
    root->height = max(Height(root->left),Height(root->right))+1;
    return temp;
}
struct AVL* LeftRightRotate(struct AVL *root)
{
    root->left = RightRotate(root->left);
    return LeftRotate(root);
}
struct AVL* RightRotate(struct AVL *root)
{
    struct AVL *temp;
    temp = root->right;
    root->right = temp->left;
    temp->left = root;
    temp->height = max(Height(temp->left),Height(temp->right))+1;
    root->height = max(Height(root->left),Height(root->right))+1;
    return temp;
}
struct AVL* RightLeftRotate(struct AVL *root)
{
    root->right = LeftRotate(root->right);
    return RightRotate(root);
}
void Level_Order(struct AVL *root)
{
    int front = 0, rear = 0;
    struct AVL* Q[100];
    if(root != NULL) Q[front] = root;
    while (front <= rear)
    {
        if(Q[front]->left != NULL) Q[++rear] = Q[front]->left;
        if(Q[front]->right != NULL) Q[++rear] = Q[front]->right;
        printf("%d ",Q[front]->data);
        front++;
    }
}
int main()
{
    struct AVL *root = NULL;
    int N,X;
    printf("Enter the number of nodes that you want to insert to AVL tree\n");
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&X);
        root = Insert(X,root);
    }
    printf("Level order is: ");
    Level_Order(root);
    system("pause");
    return 0;
}