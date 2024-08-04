#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
} *root = NULL;
typedef struct Node node;

node *newNode(int item)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = item;
    new->left = NULL;
    new->right = NULL;

    return new;
}
node *insert()
{
    int x;
    scanf("%d", &x);
    node *newRoot = newNode(x);

    if (x == -1)
    {
        return 0;
    }

    printf("Enter left child of %d : ", x);
    newRoot->left = insert();

    printf("Enter right child of %d : ", x);
    newRoot->right = insert();

    return newRoot;
}
int internalNodes(struct Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return 0;
    }
    int leftIn = internalNodes(root->left);
    int rightIn = internalNodes(root->right);

    return leftIn + rightIn + 1;
}
int main()
{
    printf("\nEnter the root : ");
    root = insert();

    int inNode = internalNodes(root);
    printf("\nNumber of internal nodes are : %d", inNode);

    return 0;
}