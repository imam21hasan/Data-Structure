#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

void insert(node **head, int item)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = item;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}
void traverse(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
node *copyList(node *head)
{
    if (head == NULL)
    {
        printf("The list is already empty !!!\n");
        return NULL;
    }

    node *newHead = NULL;
    node *temp = head;
    while (temp != NULL)
    {
        insert(&newHead, temp->data);
        temp = temp->next;
    }
    return newHead;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    insert(&head1, 10);
    insert(&head1, 20);
    insert(&head1, 30);
    insert(&head1, 40);
    insert(&head1, 50);

    printf("The main list is : ");
    traverse(head1);

    head2 = copyList(head1);

    printf("\nThe coppied list is : ");
    traverse(head2);

    return 0;
}
