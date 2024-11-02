#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct Node;
struct TreeNode;
struct Tree_Stack;
struct Stack* CreatStack();
bool IsEmpty(struct Stack* S);
void Push(struct Stack* S,char c);
char Top(struct Stack* S);
void Pop(struct Stack* S);
void Expression_To_BT(char c[],int length);
bool HasLowerPriority(char op1,char op2);
int GetWeightOperator(char op);
struct TreeNode* GetNewNode(char c);
struct Tree_Stack* CreateTreeStack();
void Push_Node(struct Tree_Stack* S,struct TreeNode* root);
struct TreeNode* Top_Tree(struct Tree_Stack* S);
bool IsEmpty_Tree(struct Tree_Stack* S);
void Pop_Tree(struct Tree_Stack* S);

double Evaluate(struct TreeNode* root);
struct TreeNode* root = NULL;

struct Stack
{
    char data;
    struct Stack* next;
};
struct TreeNode
{
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct Tree_Stack
{
    struct TreeNode* T;
    struct Tree_Stack* next;
};

struct Stack* CreateStack()
{
    struct Stack* S;
    S = malloc(sizeof(struct Stack));
    if (S == NULL)
    {
        printf("Out of stack!\n");
        return NULL;
    }
    S->next = NULL;
    return S;
}
void Push(struct Stack* S,char c)
{
    struct Stack* TmpCell = (struct Stack*)malloc(sizeof(struct Stack));
    if (TmpCell == NULL)
    {
        printf("Out of space\n");
        return;
    }
    else
    {
        TmpCell->data = c;
        TmpCell->next = S->next;
        S->next = TmpCell;
        return;
    }
}
char Top(struct Stack* S)
{
    if (IsEmpty(S))
    {
        printf("Empty Stack!\n");
    }
    else
    {
        return S->next->data;
    }
    
}
void Pop(struct Stack* S)
{
    struct Stack* TmpCell = S->next;
    if (IsEmpty(S))
    {
        printf("Empty Stack!\n");
        return;
    }
    else
    {
        S->next = TmpCell->next;
        free(TmpCell);
        return;
    }
}
struct TreeNode* GetNewNode(char c)
{
    struct TreeNode* TmpCell = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (TmpCell == NULL)
    {
        printf("Out of space!\n");
        return NULL;
    }
    else
    {
        TmpCell->data = c;
        TmpCell->left = TmpCell->right = NULL;
        return TmpCell;
    }
}
struct Tree_Stack* CreateTreeStack()
{
    struct Tree_Stack* S = malloc(sizeof(struct Tree_Stack));
    if (S == NULL)
    {
        printf("Out of space!\n");
        return NULL;
    }
    else
    {
        S->next = NULL;
        return S;
    }
}
void Push_Node(struct Tree_Stack* S,struct TreeNode* root)
{
    struct Tree_Stack* TmpCell = (struct Tree_Stack*)malloc(sizeof(struct Tree_Stack));
    if (TmpCell == NULL)
    {
        printf("Out of space!\n");
        return;
    }
    else
    {
        TmpCell->T = root;
        TmpCell->next = S->next;
        S->next = TmpCell;
        return;
    }
}
struct TreeNode* Top_Tree(struct Tree_Stack* S)
{
    if (IsEmpty_Tree(S))
    {
        printf("Out of space!\n");
        return NULL;
    }
    else
    {
        return S->next->T;
    }
}
void Pop_Tree(struct Tree_Stack* S)
{
    struct Tree_Stack* TmpCell = S->next;
    if (IsEmpty_Tree(S))
    {
        printf("Empty Stack!\n");
        return;
    }
    else
    {
        S->next = TmpCell->next;
        free(TmpCell);
        return;
    }
}
bool IsEmpty_Tree(struct Tree_Stack* S)
{
    return S->next == NULL;
}
int GetWeightOperator(char op)
{
    int weight = -1;
    switch (op)
    {
    case '+':
        weight = 1;
        break;
    case '-':
        weight = 1;
        break;
    case '*':
        weight = 2;
        break;
    case '/':
        weight = 2;
        break;
    default:
        break;
    }
    return weight;
}
bool HasLowerPriority(char op1,char op2)
{
    int weight1 = GetWeightOperator(op1);
    int weight2 = GetWeightOperator(op2);
    if(weight1 == weight2) return 0;
    if(weight1 > weight2) return 0;
    return 1;
}
bool IsEmpty(struct Stack* S)
{
    return S->next == NULL;
}
bool IsOperand(char c)
{
    if (c >= '0' && c <= '9') return true;
    else return false;
}
bool IsOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/') return true;
    else return false;
}
/*  Time complexity to build expression binary tree is O(N) + O(M), but here we will choose O(N) because M<N*/
void Expression_To_BT(char c[],int length)
{
    int i;
    struct Stack* Operator_stack = CreateStack();
    struct Tree_Stack *S = CreateTreeStack();
    struct TreeNode *T1,*T2;
    // time complexity is the length of expression O(N)
    for ( i = 0; i < length-1; i++)
    {
        if(c[i] == ' ' || c[i] == ',') continue; // if there is coma or space ignore it
        else if(IsOperand(c[i])) // if it is integer make a node with left and right are child NULL and push it into stack
        {
            root = GetNewNode(c[i]);
            Push_Node(S,root);
        }
        else if (IsOperator(c[i])) // if it is operations(+,-,*,/) then make this root node with left child and right child N 
        {
            while ( (!IsEmpty(Operator_stack)) && (Top(Operator_stack) != '(') && (!HasLowerPriority(Top(Operator_stack),c[i])) )
            {
                root = GetNewNode(Top(Operator_stack)); Pop(Operator_stack);
                T1 = Top_Tree(S); Pop_Tree(S); // right
                T2 = Top_Tree(S); Pop_Tree(S); // left
                root->left = T2;
                root->right = T1;
                Push_Node(S,root);
            }
            Push(Operator_stack,c[i]);
        }
        else if (c[i] == '(')
        {
            Push(Operator_stack,c[i]);
        }
        else if (c[i] == ')')
        {
            while (!IsEmpty(Operator_stack) && Top(Operator_stack) != '(')
            {
                root = GetNewNode(Top(Operator_stack)); Pop(Operator_stack);
                T1 = Top_Tree(S); Pop_Tree(S);
                T2 = Top_Tree(S); Pop_Tree(S);
                root->left = T2;
                root->right = T1;
                Push_Node(S,root);
            }
            Pop(Operator_stack);
        }
    }
    // time complexity is O(M)
    while(!IsEmpty(Operator_stack))
    {
        root = GetNewNode(Top(Operator_stack)); Pop(Operator_stack);
        T1 = Top_Tree(S); Pop_Tree(S);
        T2 = Top_Tree(S); Pop_Tree(S);
        root->left = T2;
        root->right = T1;
        Push_Node(S,root);
    }
}
// Time complexity for evaluate the expression tree is O(N). N is the number of nodes in the tree.
double Evaluate(struct TreeNode* root)
{
    double left,right;
    if(root == NULL) return 0;

    if(!root->left && !root->right) return ( (int)(root->data) - 48 );

    left = Evaluate(root->left);
    right = Evaluate(root->right);

    if (root->data == '+') return left + right;
    if (root->data == '-') return left - right;
    if (root->data == '*') return left * right;
    if (root->data == '/') return left / right;
}
int main()
{
    char c[50];
    printf("Enter expression:\n");
    fgets(c,sizeof(c),stdin);
    Expression_To_BT(c,strlen(c));
    printf("%.2f\n",Evaluate(root));
    system("pause");
    return 0;
}