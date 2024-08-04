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
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (leftHeight > rightHeight)
        {
            return (leftHeight + 1);
        }
        else
        {
            return (rightHeight + 1);
        }
    }
}
int main()
{
    printf("\nEnter the root : ");
    root = insert();

    printf("\nHeight of the tree is : %d", height(root));

    return 0;
}