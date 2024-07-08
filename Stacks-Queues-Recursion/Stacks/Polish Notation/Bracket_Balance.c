#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
char stack[SIZE];
int top = -1;

int isEmpty();
int isFull();
void push(char);
char pop();
int check_balance(char *);
int match_char(char, char);

int main()
{
    char expr[SIZE];
    int balance;
    printf("\nEnter the algebraic expression : ");
    gets(expr);

    balance = check_balance(expr);
    if (balance == 1)
    {
        printf("The expression is valid.");
    }
    else
    {
        printf("The expression is not valid !!!");
    }

    return 0;
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull()
{
    if (top == SIZE - 1)
    {
        return 1;
    }
    return 0;
}
void push(char c)
{
    if (isFull())
    {
        printf("\nStack is full !!!\n");
        return;
    }
    top++;
    stack[top] = c;
}
char pop()
{
    char c;
    if (isEmpty())
    {
        printf("\nStack is empty !!!\n");
        return 0;
    }
    c = stack[top];
    top--;
    return c;
}
int check_balance(char *s)
{
    char temp;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (isEmpty())
            {
                printf("\nRight bracket are more than left.\n");
                return 0;
            }
            else
            {
                temp = pop();
                if (!match_char(temp, s[i]))
                {
                    printf("\nMismatch bracket.\n");
                    return 0;
                }
            }
        }
    }
    if (isEmpty())
    {
        printf("\nBracket are well balance.\n");
        return 1;
    }
    else
    {
        printf("\nLeft bracket are more than the right.\n");
        return 0;
    }
}
int match_char(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;
    else if (a == '{' && b == '}')
        return 1;
    else if (a == '[' && b == ']')
        return 1;
    else
        return 0;
}