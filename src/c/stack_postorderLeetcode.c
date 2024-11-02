#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct Stack
{
    struct TreeNode *node;
    struct Stack *next;
};
struct TreeNode* GetNewNode(int X);
int* postorderTraversal(struct TreeNode* root, int* returnSize);
struct Stack* CreateStack();
void Push(struct TreeNode *root,struct Stack *S);
struct TreeNode* Top(struct Stack *S);
int IsEmpty(struct Stack *S);
void Pop(struct Stack *S);
void Free_Stack(struct Stack* S);


struct Stack* CreateStack()
{
    struct Stack *S = malloc(sizeof(struct Stack));
    if(S != NULL)
    {
        S->next = NULL;
        return S;
    }
    else
    {
        printf("No space!\n");
        return NULL;
    }
}
void Push(struct TreeNode *root,struct Stack *S)
{
    struct Stack *temp = (struct Stack*)malloc(sizeof(struct Stack));
    if(temp != NULL)
    {
        temp->node = root;
        temp->next = S->next;
        S->next = temp;
    }
    else
    {
        printf("No space!\n");
        return;
    }
}
void Pop(struct Stack *S)
{
    if(IsEmpty(S))
    {
        printf("Empty Stack!\n");
        return;
    }
    else
    {
        struct Stack *temp;
        temp = S->next;
        S->next = temp->next;
        free(temp);
    }
}
struct TreeNode* Top(struct Stack *S)
{
    if( !IsEmpty(S) ) return S->next->node;
    else return NULL;
}
int IsEmpty(struct Stack *S)
{
    return S->next == NULL;
}
void Free_Stack(struct Stack* S)
{
    while (!IsEmpty(S))
    {
        Pop(S);
    }
    free(S);
}

struct TreeNode* GetNewNode(int X)
{
    struct TreeNode* NewNode = malloc(sizeof(struct TreeNode));
    if(NewNode == NULL)
    {
        printf("Out of space!\n");
        return NULL;
    }
    else
    {
        NewNode->val = X;
        NewNode->left=NewNode->right = NULL;
        return NewNode;
    }
}
int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    struct Stack *S = CreateStack();
    struct TreeNode *temp = root;
    int i = 0;
    if(temp == NULL) return returnSize;
    while (temp != NULL)
    {
        if(temp->left != NULL)
        {
            Push(temp,S);
            temp = temp->left;
        }
        else if(temp->right != NULL)
        {
            Push(temp,S);
            temp = temp->right;
        }
        else
        {
            if(IsEmpty(S))
            {
                returnSize[i++] = temp->val;
                temp = NULL;
            }
            else
            {
                returnSize[i++] = temp->val;
                temp = Top(S);
                Pop(S);
                if(temp->left != NULL && temp->left->val == returnSize[i-1])
                temp->left = NULL;
                else if(temp->right != NULL && temp->right->val == returnSize[i-1])
                temp->right = NULL;
            }
        }
    }
    return returnSize;
}
int main()
{
    struct TreeNode* root;
    root = GetNewNode(1);
    root->left = GetNewNode(2);
    root->right = GetNewNode(3);
    root->left->left = GetNewNode(4);
    root->left->right = GetNewNode(5);
    root->right->left = GetNewNode(6);
    root->right->right = GetNewNode(7);
    root->right->left->right = GetNewNode(8);
    root->right->left->right->left = GetNewNode(9);
    printf("\nPost order: ");
    int *arr = (int*)malloc(sizeof(int)*100);
    arr = postorderTraversal(root,arr);
    for(int i = 0; i < 9; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}