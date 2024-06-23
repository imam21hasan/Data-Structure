#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;
node *search(node *head,int item)
{
    node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==item)
        {
            return temp;
            break;
        }
        else
        {
            temp=temp->next;
        }
    }
    return NULL;
}
void traverse(node *a)
{
    node *temp = a;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    node *a = (node *)malloc(sizeof(node));
    node *b = (node *)malloc(sizeof(node));
    node *c = (node *)malloc(sizeof(node));

    a->data = 5;
    a->next = b;

    b->data = 10;
    b->next = c;

    c->data = 15;
    c->next = NULL;

    printf("The list is : ");
    traverse(a);

    int x;
    printf("\nEnter your search item : ");
    scanf("%d",&x);

    node *result=search(a,x);
    if(result!=NULL)
    {
        printf("%d is found at the linked list.",x);
    }
    else
    {
        printf("%d is not found at the linked list.",x);
    }

    return 0;
}
