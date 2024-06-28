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
    new->next = NULL;
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
    printf("NULL");
}
void deleteAtPosition(int pos)
{
    node *temp = head;
    node *temp2 = NULL;
    if (pos == 1)
    {
        head = head->next;
        head->pre = NULL;
        free(temp);
    }
    while (pos!=1)
    {
        temp = temp->next;
        pos--;
    }
    if (temp->next == NULL)
    {
        temp2=temp->pre;

        temp2->next=NULL;
        free(temp);
    }
    else
    {
        temp2 = temp->pre;
        
        temp2->next = temp->next;
        temp->next->pre = temp2;
        free(temp);
    }
}
int main()
{
    insert(40);
    insert(30);
    insert(20);
    insert(10);

    printf("The main linked list is : ");
    traverse();

    int n;
    printf("\nEnter the deletion node position : ");
    scanf("%d", &n);

    deleteAtPosition(n);

    printf("After delete %dth node the list is : ", n);
    traverse();

    return 0;
}