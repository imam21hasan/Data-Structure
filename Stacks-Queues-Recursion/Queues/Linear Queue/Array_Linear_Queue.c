#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
int queue[SIZE];
int front = 0, rare = -1;

int isFull()
{
    if (rare == SIZE - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty()
{
    if (rare == -1)
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
    rare++;
    queue[rare] = item;
    printf("%d is enqueue successfully.\n", item);
}
void dequeue()
{
    if (isEmpty())
    {
        printf("The queue is empty !!!\n");
        return;
    }
    int val = queue[front];
    queue[front] = -1;
    front++;
    printf("Dequeue item is : %d\n", val);
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
    enqueue(10);
    enqueue(20);
  
    print();
  
    dequeue();
  
    enqueue(30);
  
    print();
  
    dequeue();
  
    print();
  
    enqueue(40);
  
    print();
  
    enqueue(50);
  
    print();

    return 0;
}
