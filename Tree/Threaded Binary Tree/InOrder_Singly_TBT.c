#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *rThread;
} *root = NULL;
typedef struct Node node;

node *createNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    new->rThread = NULL;
    return new;
}
node *insert()
{
    int x;
    scanf("%d", &x);
    node *newRoot = createNode(x);

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
void InorderSuccessors(node *root)
{
    static node *previous = NULL;

    if (root)
    {
        InorderSuccessors(root->left);

        if (previous)
        {
            previous->rThread = root;
        }
        previous = root;

        InorderSuccessors(root->right);
    }
}
node *leftmost(node *root)
{
    node *temp = root;
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    node *current = leftmost(root);
    while (current != NULL)
    {
        printf("%d ", current->data);

        if (current->rThread)
        {
            current = current->rThread;
        }
        else
        {
            current = current->right;
        }
    }
}

int main()
{

    printf("\nEnter root : ");
    root = insert();

    InorderSuccessors(root);

    printf("Inorder threaded binary tree is : ");
    inOrder(root);

    return 0;
}