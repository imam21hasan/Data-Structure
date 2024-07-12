#include <stdio.h>
#define SIZE 10

struct Node
{
    int data;
    int prn;
};
typedef struct Node node;

node prioQueue[SIZE];
int front = -1;
int rear = -1;

void insert(int item, int priority)
{
    if (rear == SIZE - 1)
    {
        printf("The Priority Queue is already full !!!\n");
        return;
    }

    node new;
    new.data = item;
    new.prn = priority;

    if (rear == -1)
    {
        front = 0;
    }
    int i;
    for (i = rear; i >= front && prioQueue[i].prn > priority; i--)
    {
        prioQueue[i + 1] = prioQueue[i];
    }
    prioQueue[i + 1] = new;
    rear++;
}
void delete()
{
    if (rear == -1)
    {
        printf("The Priority Queue is already empty!!!\n");
        return;
    }
    if (front == rear)
    {
        rear = -1;
    }
    int val = prioQueue[front].data;
    front++;
    printf("Deleting highest priority item is : %d\n", val);
}
void peek()
{
    if (rear == -1)
    {
        printf("There are no item in Priority Queue !!!\n");
        return;
    }
    printf("The front item is : %d\n", prioQueue[front].data);
    printf("The rear item is : %d\n", prioQueue[rear].data);
}
void print()
{
    printf("The Priority Queue is : ");
    if (rear == -1)
    {
        printf("empty!!!\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", prioQueue[i].data);
    }
    printf("\n");
}

int main()
{
    insert(30, 3);
    insert(10, 1);
    insert(33, 3);
    insert(20, 2);
    insert(11, 1);
    insert(40, 4);
    print();
    peek();

    delete ();
    delete ();
    delete ();
    print();
    peek();

    insert(50, 1);
    print();
    peek();

    return 0;
}
