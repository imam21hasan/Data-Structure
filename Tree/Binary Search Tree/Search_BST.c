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
node *search(node *root, int val)
{
    if (root == NULL || root->data == val)
    {
        return root;
    }
    if (root->data < val)
    {
        return search(root->right, val);
    }
    else
    {
        return search(root->left, val);
    }
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

    int n;
    printf("\nEnter your search item : ");
    scanf("%d", &n);

    node *rslt = search(root, n);

    if (rslt != NULL)
    {
        printf("%d is found in the tree.\n", n);
    }
    else
    {
        printf("%d is not found in the tree !!!\n", n);
    }

    return 0;
}