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
void traverse_Post(node *root)
{
    node *ptr = root;
    node *lastVisit = NULL;
    while (ptr != NULL || !isEmpty())
    {
        if (ptr != NULL)
        {
            push(ptr);
            ptr = ptr->left;
        }
        else
        {
            node *tos = stack[top];
            if (tos->right != NULL && lastVisit != tos->right)
            {
                ptr = tos->right;
            }
            else
            {
                printf("%d  ", tos->data);
                lastVisit = pop();
            }
        }
    }
}
int main()
{
    printf("\nEnter the root : ");
    root = insert();

    printf("The Postorder list is : ");
    traverse_Post(root);

    return 0;
}