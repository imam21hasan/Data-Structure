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
node *concatenation(node *head1, node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    node *temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}
int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    insert(&head1, 10);
    insert(&head1, 20);
    insert(&head1, 30);

    insert(&head2, 40);
    insert(&head2, 50);
    insert(&head2, 60);

    printf("The first list is : ");
    traverse(head1);

    printf("\nThe second list is : ");
    traverse(head2);

    node *concatHead = concatenation(head1, head2);

    printf("\nThe concatenation list is : ");
    traverse(concatHead);

    return 0;
}