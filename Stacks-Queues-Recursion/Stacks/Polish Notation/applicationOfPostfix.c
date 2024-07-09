#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int item)
{
    if (top == SIZE - 1)
    {
        printf("Stack is full !!!");
        return;
    }
    top++;
    stack[top] = item;
}
int pop()
{
    if (top == -1)
    {
        printf("Stack is empty !!!");
        return 0;
    }
    int val = stack[top];
    top--;
    return val;
}

void appliOfPost(char s[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            push(s[i] - '0');
        }
        else
        {
            int a = pop();
            int b = pop();

            switch (s[i])
            {
            case '+':
                push(b + a);
                break;
            case '-':
                push(b - a);
                break;
            case '*':
                push(b * a);
                break;
            case '/':
                push(b / a);
                break;
            case '^':
                push(pow(b, a));
                break;
            default:
                printf("Invalid operator : %c\n", s[i]);
                return;
            }
        }
    }

    printf("\nThe result is : %d", pop());
}
int main()
{
    char exp[100];
    printf("\nEnter a postfix expression : ");
    gets(exp);

    appliOfPost(exp);

    return 0;
}