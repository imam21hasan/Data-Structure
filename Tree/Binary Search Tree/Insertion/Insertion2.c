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
node *insert(node *root, int item)
{
    node *temp = newNode(item);

    if (root == NULL)
    {
        return temp;
    }
    if (root->data == item)
    {
        return root;
    }
    if (root->data < item)
    {
        root->right = insert(root->right, item);
    }
    else
    {
        root->left = insert(root->left, item);
    }

    return root;
}
void inOrderTrav(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTrav(root->left);
    printf("%d  ", root->data);
    inOrderTrav(root->right);
}
int main()
{
    node *root = NULL;
    int arr[] = {45, 87,52, 61, 30, 90, 18, 73, 25, 54};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }

    printf("The inorder list of BST is : ");
    inOrderTrav(root);

    return 0;
}