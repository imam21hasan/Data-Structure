#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
} *head = NULL;
typedef struct Node node;

void insertEmptyList(int item)
{
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Overflow.");
        return;
    }
    new->pre = NULL;
    new->data = item;
    new->next = NULL;
    
    head = new;
}
int main()
{
    insertEmptyList(21);

    printf("The linked list is : %d", head->data);

    return 0;
}
