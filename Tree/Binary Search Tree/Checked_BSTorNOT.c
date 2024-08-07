#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *left, *right;
};
typedef struct Node node;
node *newNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->left = new->right = NULL;
    return new;
}
int isBSTUtil(node *node, int min, int max)
{
    if (node == NULL)
        return 1;
    if (node->data < min || node->data > max)
        return 0;

    return isBSTUtil(node->left, min, node->data - 1) &&
           isBSTUtil(node->right, node->data + 1, max);
}
int isBST(node *node)
{
    return isBSTUtil(node, INT_MIN, INT_MAX);
}
int main()
{
    node *root = NULL;
    root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);

    if (isBST(root))
        printf("The tree is a BST\n");
    else
        printf("The tree is not a BST\n");

    return 0;
}