#include <stdio.h>
#define SIZE 4
int stack1[SIZE], stack2[SIZE];
int top1 = -1, top2 = -1, c = 0;

void push1(int x)
{
    top1++;
    stack1[top1] = x;
}
int pop1()
{
    int val = stack1[top1];
    top1--;
    return val;
}

void push2(int y)
{
    top2++;
    stack2[top2] = y;
}
int pop2()
{
    int val = stack2[top2];
    top2--;
    return val;
}

void enqueue(int item)
{
    if (top1 == SIZE - 1)
    {
        printf("The queue is already full !!!\n");
        return;
    }
    push1(item);
    c++;
    printf("%d enqueue successfully.\n", item);
}
void dequeue()
{
    int i, a, b, d;
    if (top1 == -1)
    {
        printf("The queue is already empty !!!\n");
    }
    else
    {
        for (i = 0; i < c; i++)
        {
            a = pop1();
            push2(a);
        }
        b = pop2();
        printf("The dequeue item is : %d\n", b);
        c--;
        for (i = 0; i < c; i++)
        {
            d = pop2();
            push1(d);
        }
    }
}
void print()
{
    printf("The Queue is : ");
    if (top1 == -1)
    {
        printf("empty !!!\n");
        return;
    }
    for (int i = 0; i <= top1; i++)
    {
        printf("%d  ", stack1[i]);
    }
    printf("\n");
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    print();

    dequeue();
    print();
    enqueue(60);
    print();

    return 0;
}
