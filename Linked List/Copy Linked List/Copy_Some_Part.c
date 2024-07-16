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
node *copyList(node *head, int n)
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
        if (temp->data == n)
        {
            break;
        }
        temp = temp->next;
    }
    return newHead;
}

int main()
{
    node *head1 = NULL;
    
    for (int i = 10; i <= 100; i = i + 10)
    {
        insert(&head1, i);
    }

    printf("The main list is : ");
    traverse(head1);

    int target;
    printf("\nHow much do you want to copy : ");
    scanf("%d", &target);

    node *head2 = copyList(head1, target);

    printf("The coppied list is : ");
    traverse(head2);

    return 0;
}