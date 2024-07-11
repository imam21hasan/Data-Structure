#include <stdio.h>
#define SIZE 4
int deque[SIZE];
int front = -1, rear = -1, totalItem = 0;

void insertFront(int item)
{
    if (totalItem == SIZE)
    {
        printf("The deque is already full !!!\n");
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        deque[front] = item;
        totalItem++;
    }
    else if (front == 0)
    {
        front = SIZE - 1;
        deque[front] = item;
        totalItem++;
    }
    else
    {
        front--;
        deque[front] = item;
        totalItem++;
    }
}
void insertRear(int item)
{
    if (totalItem == SIZE)
    {
        printf("The deque is already full !!!\n");
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        deque[rear] = item;
        totalItem++;
    }
    else if (rear == SIZE - 1)
    {
        rear = 0;
        deque[rear] = item;
        totalItem++;
    }
    else
    {
        rear++;
        deque[rear] = item;
        totalItem++;
    }
}

void deleteFront()
{
    if (totalItem == 0)
    {
        printf("The deque is already empty !!!\n");
    }
    else if (front == rear)
    {
        int val = deque[front];
        deque[front] = -1;
        front = rear = -1;
        totalItem--;
        printf("The deleted item is : %d\n", val);
    }
    else if (front == SIZE - 1)
    {
        int val = deque[front];
        deque[front] = -1;
        front = 0;
        totalItem--;
        printf("The deleted item is : %d\n", val);
    }
    else
    {
        int val = deque[front];
        deque[front] = -1;
        front++;
        totalItem--;
        printf("The deleted item is : %d\n", val);
    }
}
void deleteRear()
{
    if (totalItem == 0)
    {
        printf("The deque is already empty !!!\n");
    }
    else if (front == rear)
    {
        int val = deque[rear];
        deque[rear] = -1;
        front = rear = -1;
        totalItem--;
        printf("The deleted item is : %d\n", val);
    }
    else if (rear == 0)
    {
        int val = deque[rear];
        deque[rear] = -1;
        rear = SIZE - 1;
        totalItem--;
        printf("The deleted item is : %d\n", val);
    }
    else
    {
        int val = deque[rear];
        deque[rear] = -1;
        rear--;
        totalItem--;
        printf("The deleted item is : %d\n", val);
    }
}

void peekFront()
{
    if (totalItem == 0)
    {
        printf("There are no item in deque !!!\n");
        return;
    }
    printf("The front item is : %d\n", deque[front]);
}
void peekRear()
{
    if (totalItem == 0)
    {
        printf("There are no item in deque !!!\n");
        return;
    }
    printf("The rear item is : %d\n", deque[rear]);
}

void print()
{
    printf("The Deque is : ");
    if (totalItem == 0)
    {
        printf("empty !!!\n");
        return;
    }
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d  ", deque[i]);
    }
    printf("\n");
}
int main()
{
    insertFront(10);
    insertFront(20);
    insertFront(30);

    print();
    peekFront();
    peekRear();

    insertRear(40);
    print();
    peekFront();
    peekRear();
    insertRear(50);

    deleteFront();
    deleteFront();

    print();
    peekFront();
    peekRear();

    deleteRear();
    insertRear(60);
    insertRear(70);

    print();
    peekFront();
    peekRear();

    return 0;
}
