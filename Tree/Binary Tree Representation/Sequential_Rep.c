#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
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
node *insertLevelOrder(node *root, int data[], int i, int n)
{
    if (i < n)
    {
        node *temp = newNode(data[i]);
        root = temp;

        root->left = insertLevelOrder(root->left, data, 2 * i + 1, n);

        root->right = insertLevelOrder(root->right, data, 2 * i + 2, n);
    }
    return root;
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
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(data) / sizeof(data[0]);

    root = insertLevelOrder(root, data, 0, n);

    printf("Inorder traversal of the tree : ");
    inorderTrav(root);

    return 0;
}