#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
int queue[SIZE];
int front = 0, rear = -1, totalItem = 0;

void enqueue(int item)
{
    if (totalItem == SIZE)
    {
        printf("The Queue is already full !!!\n");
        return;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = item;
    totalItem++;
    printf("%d enqueue successfully.\n", item);
}
void dequeue()
{
    if (totalItem == 0)
    {
        printf("The Queue is already empty !!!\n");
        return;
    }
    int val = queue[front];
    queue[front] = -1;
    front = (front + 1) % SIZE;
    totalItem--;
    printf("The dequeue item is : %d\n", val);
}
void peek()
{
    if (totalItem == 0)
    {
        printf("There are no item in Queue.\n");
        return;
    }
    printf("The front item is : %d\n", queue[front]);
}
void print()
{
    printf("The Queue is : ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d  ", queue[i]);
    }
    printf("\n");
}
int main()
{
    print();
    enqueue(10);
    enqueue(20);
    print();
    peek();
    enqueue(30);
    dequeue();
    print();
    peek();

    enqueue(40);
    enqueue(50);
    print();
    enqueue(60);
    dequeue();
    print();
    peek();
    dequeue();
    dequeue();
    print();

    enqueue(70);
    enqueue(80);
    print();
    dequeue();
    print();

    return 0;
}
