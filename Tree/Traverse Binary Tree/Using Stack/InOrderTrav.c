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
node *insert()
{
    node *new = (node *)malloc(sizeof(node));
    int x;
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    new->data = x;
    printf("Enter left child of %d : ", x);
    new->left = insert();

    printf("Enter right child of %d : ", x);
    new->right = insert();

    return new;
}
void traverse_In(node *root)
{
    node *ptr = root;
    while (ptr != NULL || !isEmpty())
    {
        while (ptr != NULL)
        {
            push(ptr);
            ptr = ptr->left;
        }
        ptr = pop();

        printf("%d  ", ptr->data);

        ptr = ptr->right;
    }
}
int main()
{
    printf("\nEnter the root : ");
    root = insert();

    printf("The Inorder list is : ");
    traverse_In(root);

    return 0;
}