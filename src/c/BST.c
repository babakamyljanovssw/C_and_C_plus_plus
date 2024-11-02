#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct BstNode;
struct BstNode* GetNewNode(int X);
//struct BstNode* Insert(int X,struct BstNode* root); // recursive insert
struct BstNode* Insert_nonrec(int X,struct BstNode* root);   // nonrecursive insert
struct BstNode* Search(int X,struct BstNode* root);            // return true if tree stores given X value
struct BstNode* Delete(int X,struct BstNode* root);
struct BstNode* FindMin(struct BstNode* root);
struct BstNode* FindMax(struct BstNode* root);
int FindHeight(struct BstNode* root);
void Level_Order(struct BstNode* root);
int max(int a,int b);
struct BstNode* Getsuccessor(int X,struct BstNode* root);
struct BstNode
{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};
struct BstNode* GetNewNode(int X)
{
    struct BstNode* NewNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    if (NewNode == NULL)
    {
        printf("Out of space!\n");
        return NULL;
    }
    else
    {
        NewNode->data = X;
        NewNode->left = NewNode->right = NULL;
        return NewNode;
    }
}
// Recursive implementation of Insert for Binary Search Tree
/*struct BstNode* Insert(int X,struct BstNode* root)
{
    if (root == NULL) // empty tree
    {
        root = GetNewNode(X);
        return root;
    }
    else if (X < root->data)
    {
        root->left = Insert(X,root->left);
    }
    else if (X > root->data)
    {
        root->right = Insert(X,root->right);
    }
    return root;
}*/
// Nonrecursive implementation of Insert for Binary Search Tree
struct BstNode* Insert_nonrec(int X,struct BstNode* root)
{
    struct BstNode* TmpCell = root;
    if (TmpCell == NULL)
    {
        TmpCell = GetNewNode(X);
        return TmpCell;
    }
    while(TmpCell != NULL)
    {
        if(X < TmpCell->data)
        {
            if(TmpCell->left == NULL)
            {
                TmpCell->left = GetNewNode(X);
                TmpCell = NULL;
            }
            else TmpCell = TmpCell->left;
        }
        else if(X > TmpCell->data)
        {
           if(TmpCell->right == NULL)
           {
               TmpCell->right = GetNewNode(X);
               TmpCell = NULL;
           }
           else TmpCell = TmpCell->right;
        }
    }
    return root;
}
// recursively find min of tree. to find it go left as long as there is a left child
struct BstNode* FindMin(struct BstNode* root)
{
    if(root == NULL) return NULL;
    if(root->left == NULL) return root;
    return FindMin(root->left);
}
// non recursively find max of tree. to find it go right as long as there is a right child
struct BstNode* FindMax(struct BstNode* root)
{
    if(root == NULL) return NULL;
    while (root->right != NULL) root = root->right;
    return root;
}
// return address of node if it will web find otherwise NULL. Time Complexity O(h)- h is the height of tree
struct BstNode* Search(int X,struct BstNode* root)
{
    if(root == NULL) return NULL;
    if(root->data == X) return root;
    else if(X < root->data) return Search(X,root->left);
    else if(X > root->data) return Search(X,root->right);
}
int max(int a,int b)
{
    if(a > b) return a;
    else if(a < b) return b;
    else return a;
}
int FindHeight(struct BstNode* root)
{
    /*
    if(root == NULL) return -1;
    return max(FindHeight(root->left),FindHeight(root->right)) +1;
    */
   if(root == NULL) return -1;
   else
   {
       int LHeight = FindHeight(root->left);
       int RHeight = FindHeight(root->right);
       if(LHeight > RHeight) return LHeight + 1;
       else return RHeight + 1;
   }
}
struct BstNode* Delete(int X,struct BstNode* root)
{
    if(root == NULL) return NULL;
    else if(X < root->data) root->left = Delete(X,root->left);
    else if(X > root->data) root->right = Delete(X,root->right);
    else // when we found it
    {
        // case 1: No child
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // case 2: One child
        else if (root->left == NULL)
        {
            struct BstNode *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct BstNode *temp = root;
            root = root->left;
            free(temp);
        }
        // case 3: Two child
        else
        {
            struct BstNode *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(temp->data,root->right);
        }
    }
    return root;
}
void Level_Order(struct BstNode* root)
{
    struct BstNode* Q[100];
    int front = 0, rear = 0;
    if(root != NULL) Q[front] = root;
    while (front <= rear)
    {
        if(Q[front]->left != NULL) Q[++rear] = Q[front]->left;
        if(Q[front]->right != NULL) Q[++rear] = Q[front]->right;
        printf("%d ",Q[front]->data);
        front++;
    }
}
// Find in order successor of given node
struct BstNode* Getsuccessor(int X,struct BstNode* root)
{
    // search the node and get it's address
    struct BstNode *current = Search(X,root);
    if(current == NULL) return NULL;
    // Case 1: Node has right sub tree
    if(current->right != NULL)
    {
        return FindMin(current->right);
    }
    // case 2: No right subtree
    else
    {
        struct BstNode* successor = NULL;
        struct BstNode* ancestor = root;
        while (ancestor != current)
        {
            if(current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else ancestor = ancestor->right;
        }
        return successor;
    }
    
}
int main()
{
    struct BstNode* root = NULL; // Creating an empty tree

    root = Insert_nonrec(12,root);
    root = Insert_nonrec(5,root);
    root = Insert_nonrec(15,root);
    root = Insert_nonrec(3,root);
    root = Insert_nonrec(7,root);
    root = Insert_nonrec(13,root);
    root = Insert_nonrec(17,root);
    root = Insert_nonrec(1,root);
    root = Insert_nonrec(9,root);

    //struct BstNode *successor = Getsuccessor(13,root);
    //if(successor != NULL) printf("in order successor of 13 is %d\n",successor->data);

    //printf("\nBefore deletion 15 level order is: ");
    //Level_Order(root);

    //root = Delete(15,root);

    //printf("\nAfter deletion 15 level order is: ");
    //Level_Order(root);

    //if(Search(0,root) != NULL) printf("Found\n");
    //else printf("Not Found\n\n");

    //printf("Min of Tree = %d\n",*(FindMin(root)));
    //printf("Max of Tree = %d\n",*(FindMax(root)));
    printf("Height of Tree = %d\n",FindHeight(root));

    return 0;
}