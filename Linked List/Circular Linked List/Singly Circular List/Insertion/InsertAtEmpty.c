#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head;
typedef struct Node node;
void insert(int item)
{
    node *new = (node *)malloc(sizeof(node));
    if(new==NULL)
    {
        printf("Overflow !!!\n");
        return;
    }
    new->data = item;

    if (head == NULL)
    {
        new->next = new;
        head = new;
    }
}
void traverse()
{
    node *temp = head;
    do
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
int main()
{
    insert(10);

    printf("The main linked list is : ");
    traverse();

    return 0;
}
