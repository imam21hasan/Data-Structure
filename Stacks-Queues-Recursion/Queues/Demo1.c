#include <stdio.h>
#define SIZE 5

int myqueue[SIZE];
int front = 0, rear = -1, totalItem = 0;

int isFull()
{
    if (totalItem == SIZE)
    {
        return 1;
    }
    return 0;
}
int isEmpty()
{
    if (totalItem == 0)
    {
        return 1;
    }
    return 0;
}
void enqueue(int item)
{
    if (isFull())
    {
        printf("The queue is full !!!\n");
        return;
    }
    rear = (rear + 1) % SIZE;
    myqueue[rear] = item;
    totalItem++;
}
int dequeue()
{
    if (isEmpty())
    {
        printf("The queue is empty !!!\n");
        return -1;
    }
    int val = myqueue[front];
    myqueue[front] = -1;
    front = (front + 1) % SIZE;
    totalItem--;
    printf("Dequeue is : %d\n",val);
}
void printQueue()
{
    int i;
    printf("Queue is : ");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", myqueue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printQueue();

    enqueue(50);

    printQueue();

    enqueue(60);

    dequeue();

    printQueue();

    enqueue(70);

    printQueue();

    dequeue();

    printQueue();

    dequeue();

    printQueue();

    enqueue(80);

    printQueue();

    return 0;
}
