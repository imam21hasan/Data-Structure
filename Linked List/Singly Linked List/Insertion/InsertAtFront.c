#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node node;

void traverse(node *a)
{
    node *temp=a;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}
node *insertAtFront(node *a,int item)
{
    node *temp=a;

    node *new=(node *)malloc(sizeof(node));
    if(new==NULL)
    {
        printf("Overflow.");
    }
    else
    {
        new->data=item;
        new->next=temp;
        temp=new;
    }
}
int main()
{
    node *a=NULL;
    a=(node *)malloc(sizeof(node));
    node *b=(node *)malloc(sizeof(node));
    
    a->data=20;
    a->next=b;
    b->data=30;
    b->next=NULL;

    printf("The main list is : ");
    traverse(a);

    a=insertAtFront(a,10);

    printf("\nThe insertion list is : ");
    traverse(a);

    return 0;
}
