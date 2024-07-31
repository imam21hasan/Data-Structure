#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
    int lThread, rThread;
} *root = NULL;
typedef struct Node node;

node *newNode(int item)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = item;
    new->left = new->right = NULL;
    new->lThread = new->rThread = 1;

    return new;
}
node *insert(int item)
{
    node *newRoot = newNode(item);
    if (root == NULL)
        return newRoot;

    node *parent = NULL;
    node *cur = root;
    while (cur != NULL)
    {
        parent = cur;
        if (item < cur->data)
        {
            if (!cur->lThread)
                cur = cur->left;
            else
                break;
        }
        else
        {
            if (!cur->rThread)
                cur = cur->right;
            else
                break;
        }
    }
    if (item < parent->data)
    {
        newRoot->left = parent->left;
        newRoot->right = parent;
        parent->lThread = 0;
        parent->left = newRoot;
    }
    else
    {
        newRoot->left = parent;
        newRoot->right = parent->right;
        parent->rThread = 0;
        parent->right = newRoot;
    }
    return root;
}
node *lefmost(node *roo)
{
    if (roo == NULL)
        return NULL;
    while (!roo->lThread)
        roo = roo->left;
    return roo;
}
void inOrder(node *root)
{
    if (root == NULL)
        return;
    node *cur = lefmost(root);
    while (cur != NULL)
    {
        printf("%d  ", cur->data);

        if (cur->rThread)
            cur = cur->right;
        else
        {
            cur = lefmost(cur->right);
        }
    }
}
int main()
{
    root = insert(20);
    root = insert(10);
    root = insert(30);
    root = insert(5);
    root = insert(15);
    root = insert(25);
    root = insert(35);
    root = insert(45);

    printf("Inorder Tree is : ");
    inOrder(root);

    return 0;
}
