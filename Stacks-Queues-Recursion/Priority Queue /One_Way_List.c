#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    int prn;
    struct Node *next;
} *head = NULL;
typedef struct Node node;

void insert(int item, int p)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = item;
    new->prn = p;
    new->next = NULL;

    if (head == NULL || head->prn > p)
    {
        new->next = head;
        head = new;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL && temp->next->prn <= p)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
}
void delete()
{
    node *temp = head;
    if (head == NULL)
    {
        printf("The Priority Queue is already empty !!!\n");
        return;
    }
    int val = temp->data;
    head = head->next;
    free(temp);
    printf("Deleting highest priority item is : %d\n", val);
}
void print()
{
    node *temp = head;
    printf("The Priority Queue is : ");
    if (head == NULL)
    {
        printf("empty !!!\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    insert(10, 3);
    insert(20, 1);
    insert(30, 3);
    insert(40, 2);
    insert(50, 1);
    insert(60, 4);
    print();

    delete ();
    print();

    return 0;
}
