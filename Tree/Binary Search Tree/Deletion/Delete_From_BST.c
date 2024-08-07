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
node *findMin(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
node *delete(node *root, int item)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->data < item)
    {
        root->right = delete (root->right, item);
    }
    else if (root->data > item)
    {
        root->left = delete (root->left, item);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
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
    root = newNode(45);
    root->left = newNode(35);
    root->right = newNode(55);
    root->left->left = newNode(30);
    root->left->right = newNode(40);
    root->right->right = newNode(60);

    printf("The main tree is : ");
    inOrderTrav(root);

    int n;
    printf("\nEnter your deleted item : ");
    scanf("%d", &n);

    root = delete (root, n);

    printf("After deleted %d the tree is : ", n);
    inOrderTrav(root);

    return 0;
}
