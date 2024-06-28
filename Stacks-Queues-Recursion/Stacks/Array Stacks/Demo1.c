#include <stdio.h>

#define SIZE 4
int stack[SIZE];
int top = 0;

void push(int x)
{
    if (top >= SIZE)
    {
        printf("Stack is full !!!\n");
        return;
    }
    else
    {
        stack[top] = x;
        top++;
        printf("Successfully added item : %d \n", x);
    }
}

int pop()
{
    if(top==0)
    {
        printf("Stack is empty!!!\n");
        return 0;
    }
    else
    {
        top--;
        return stack[top];
    }
}

int peek()
{
    if(top==0)
    {
        printf("In stack has no item!!!\n");
        return 0;
    }
    else
    {
        return stack[top];
    }
}

int main()
{
    push(10);
    push(15);
    push(45);
    push(99);
    printf("Pop item is : %d \n", pop());
    push(78);
    push(789);
    printf("Pop item is : %d \n", pop());
    push(14);
    printf("Top of stack : %d \n", peek());
    printf("Pop item is : %d \n", pop());
    printf("Top of stack : %d \n", peek());
    push(58);
    printf("Pop item is : %d \n", pop());


    return 0;
}
