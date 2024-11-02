#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
int Is_BST(struct Node *root);

struct Node* GetNewNode(int X)
{
    struct Node *TmpCell = (struct Node*)malloc(sizeof(struct Node));
    if(TmpCell == NULL)
    {
        printf("Out of space!\n");
        return NULL;
    }
    else
    {
        TmpCell->data = X;
        TmpCell->left = NULL;
        TmpCell->right = NULL;
        return TmpCell;
    }
}
int Is_BST(struct Node *root)
{
    if(root->left == NULL || root->right == NULL) return 0;
    if(root->left->data > root->data || root->right->data < root->data) return -1;
    Is_BST(root->left);
    Is_BST(root->right);
}
int isbst(struct Node *root)
{
    if(root->left == NULL || root->right == NULL) return 0;
    isbst(root->left);
    if (root->left->data > root->data || root->right->data < root->data) return -1;
    isbst(root->right);
}
int main()
{
    struct Node *root;
    root = GetNewNode(7);
    root->left = GetNewNode(9);
    root->right = GetNewNode(5);
    root->left->left = GetNewNode(1);
    root->left->right = GetNewNode(6);
    //if(Is_BST(root) == -1) printf("Not binary search tree!\n");
    //else printf("binary search tree!\n");

    if(isbst(root) == -1) printf("Not binary search tree!\n");
    else printf("binary search tree!\n");
    return 0;
}