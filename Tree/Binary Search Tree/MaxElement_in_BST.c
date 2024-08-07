#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
};
typedef struct Node node;

node *newNode(int item)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = item;
    new->left = new->right = NULL;

    return new;
}
node *maxEle(node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
int main()
{
    node *root = NULL;
    root = newNode(45);
    root->left = newNode(35);
    root->right = newNode(55);
    root->left->left = newNode(30);
    root->left->right = newNode(40);
    root->right->left = newNode(50);
    root->right->right = newNode(60);

    node *rslt = maxEle(root);
    printf("\nMaximum element from BST is : %d\n", rslt->data);

    return 0;
}