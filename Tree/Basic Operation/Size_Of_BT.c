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
int size(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftSize = size(root->left);
        int rightSize = size(root->right);
        
        return leftSize + rightSize + 1;
    }
}
int main()
{
    printf("\nEnter the root : ");
    root = insert();

    printf("\nSize of the tree is : %d", size(root));

    return 0;
}
