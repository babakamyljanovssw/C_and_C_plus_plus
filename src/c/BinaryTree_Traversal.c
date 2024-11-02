/* Time complexity O(N)
   Space complexity O(h))
                   worst O(N)
            Best/Average O(logN)
*/

#include<stdio.h>
#include<stdlib.h>

struct TreeNode;
struct TreeNode* GetNewNode(char c);
void Level_Order(struct TreeNode* root);
void Pre_Order(struct TreeNode *root);
void In_Order(struct TreeNode *root);
void Post_Order(struct TreeNode *root);

struct TreeNode
{
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* GetNewNode(char c)
{
    struct TreeNode* NewNode = malloc(sizeof(struct TreeNode));
    if(NewNode == NULL)
    {
        printf("Out of space!\n");
        return NULL;
    }
    else
    {
        NewNode->data = c;
        NewNode->left=NewNode->right = NULL;
        return NewNode;
    }
}
void Level_Order(struct TreeNode* root)
{
    struct TreeNode* Q[100];
    int front = 0, rear = 0;
    if(root != NULL) Q[front] = root;
    while (front <= rear)
    {
        if(Q[front]->left != NULL) Q[++rear] = Q[front]->left;
        if(Q[front]->right != NULL) Q[++rear] = Q[front]->right;
        printf("%c ",Q[front]->data);
        front++;
    }
}
void Pre_Order(struct TreeNode *root)
{
    if(root == NULL) return;
    printf("%c ",root->data);
    Pre_Order(root->left);
    Pre_Order(root->right);
}
void In_Order(struct TreeNode *root)
{
    if(root == NULL) return;
    In_Order(root->left);
    printf("%c ",root->data);
    In_Order(root->right);
}
void Post_Order(struct TreeNode *root)
{
    if(root == NULL) return;
    Post_Order(root->left);
    Post_Order(root->right);
    printf("%c ",root->data);
}
int main()
{
    char c[] = {'F','D','J','B','E','G','K','I','H'};
    struct TreeNode* root;
    root = GetNewNode(c[0]);
    root->left = GetNewNode(c[1]);
    root->right = GetNewNode(c[2]);
    root->left->left = GetNewNode(c[3]);
    root->left->right = GetNewNode(c[4]);
    root->right->left = GetNewNode(c[5]);
    root->right->right = GetNewNode(c[6]);
    root->right->left->right = GetNewNode(c[7]);
    root->right->left->right->left = GetNewNode(c[8]);
    printf("Level order: ");
    Level_Order(root);
    printf("\nPre order: ");
    Pre_Order(root);
    printf("\nPost order: ");
    Post_Order(root);
    return 0;
}