#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
} *head = NULL;
typedef struct Node node;
void insert(int item)
{
    node *new = (node *)malloc(sizeof(node));
    new->pre = NULL;
    new->data = item;
    new->next = NULL;

    new->next = head;
    if (head != NULL)
    {
        head->pre = new;
    }
    head = new;
}
void traverse()
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
void insertAtPosition(int pos, int item)
{
    node *temp = head;
    node *new = (node *)malloc(sizeof(node));
    new->pre = NULL;
    new->data = item;
    new->next = NULL;

    if (pos == 1)
    {
        new->next = head;
        head->pre = new;
        head = new;
        return;
    }
    int i = 1;
    while (i < pos - 1)
    {
        if (temp == NULL || temp->next == NULL)
        {
            printf("Item position not found in the linked list !!!\n");
            return;
        }
        temp = temp->next;
        i++;
    }
    new->next = temp->next;
    new->pre = temp;
    temp->next = new;
    temp->next->pre = new;
}
int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    printf("The main linked list is : ");
    traverse();
    int n;
    printf("\nEnter the position : ");
    scanf("%d", &n);

    insertAtPosition(n, 88);
    printf("After inserted %dth position the list is : ",n);
    traverse();

    return 0;
}