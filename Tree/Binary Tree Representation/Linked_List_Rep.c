#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} *root = NULL;
typedef struct Node node;

node *newNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;

    return new;
}
void inorderTrav(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTrav(root->left);
    printf("%d ", root->data);
    inorderTrav(root->right);
}

int main()
{
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Inorder traversal of the tree : ");
    inorderTrav(root);

    return 0;
}
