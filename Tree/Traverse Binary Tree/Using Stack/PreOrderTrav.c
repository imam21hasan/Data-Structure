#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
} *root = NULL;

typedef struct Node node;
node *stack[100];
int top = -1;

int isEmpty()
{
    return top == -1;
}
void push(node *root)
{
    stack[++top] = root;
}
node *pop()
{
    return stack[top--];
}
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
void traverse_Pre(node *root)
{
    node *ptr = root;
    while (ptr != NULL || !isEmpty())
    {
        printf("%d  ", ptr->data);

        if (ptr->right != NULL)
        {
            push(ptr->right);
        }

        if (ptr->left != NULL)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = pop();
        }
    }
}
int main()
{
    printf("\nEnter the root : ");
    root = insert();

    printf("The Preorder list is : ");
    traverse_Pre(root);

    return 0;
}
