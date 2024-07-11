#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;
typedef struct Node node;

void enqueue(int item)
{
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("The Queue is full !!!\n");
        return;
    }
    else
    {
        new->data = item;
        new->next = NULL;
        if (rear == NULL)
        {
            front = new;
            rear = new;
            rear->next = front;
        }
        else
        {
            rear->next = new;
            rear = new;
            rear->next = front;
        }
    }
    printf("%d enqueue successfully.\n", item);
}
void dequeue()
{
    node *temp = front;
    if (rear == NULL)
    {
        printf("The Queue is already empty !!!\n");
    }
    else if (front == rear)
    {
        int val = front->data;
        front = rear = NULL;
        free(temp);
        printf("The dequeue item is : %d\n", val);
    }
    else
    {
        int val = front->data;
        front = front->next;
        rear->next = front;
        free(temp);
        printf("The dequeue item is : %d\n", val);
    }
}
void peek()
{
    if (rear == NULL)
    {
        printf("There are no item in Queue !!!\n");
        return;
    }
    printf("The front item is : %d\n", front->data);
}
void print()
{
    node *temp = front;
    printf("The Queue is : ");
    if (rear == NULL)
    {
        printf("empty !!!\n");
        return;
    }
    do
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}
int main()
{
    print();
    enqueue(10);
    print();
    peek();

    dequeue();
    print();
    peek();

    enqueue(20);
    enqueue(30);
    print();

    return 0;
}
