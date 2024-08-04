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
    node *cur = root;
    node *par = NULL;
    while (cur != NULL)
    {
        par = cur;
        if (cur->data < item)
        {
            cur = cur->right;
        }
        else if (cur->data > item)
        {
            cur = cur->left;
        }
        else
        {
            return root;
        }
    }
    if (par->data < item)
    {
        par->right = temp;
    }
    else
    {
        par->left = temp;
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
    root = insert(root, 45);
    root = insert(root, 29);
    root = insert(root, 38);
    root = insert(root, 8);
    root = insert(root, 59);
    root = insert(root, 73);
    root = insert(root, 12);
    root = insert(root, 47);

    printf("The inorder list of BST is : ");
    inOrderTrav(root);

    return 0;
}
