#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

char stack[SIZE];
int top = -1;
char postfix[SIZE];
int posIndex = 0;

void push_stack(char c)
{
    top++;
    stack[top] = c;
}
char pop()
{
    char val = stack[top];
    top--;
    return val;
}
void push_Postfix(char c)
{
    postfix[posIndex] = c;
    posIndex++;
}

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

char associativity(char c)
{
    if (c == '^')
        return 'R';
    return 'L';
}

void infix_2_Postfix(char s[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            push_Postfix(c);
        }
        else if (c == '(')
        {
            push_stack(c);
        }
        else if (c == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                char val = pop();
                push_Postfix(val);
            }
            top--;
        }
        else
        {
            while (top >= 0 && (prec(s[i]) <= prec(stack[top]) &&
                                associativity(s[i]) == 'L'))
            {
                char val = pop();
                push_Postfix(val);
            }
            push_stack(c);
        }
    }

    while (top >= 0)
    {
        char val = pop();
        push_Postfix(val);
    }

    postfix[posIndex] = '\0';
    printf("\nThe postfix expression is : ");
    printf("%s\n", postfix);
}

int main()
{
    char exp[100];
    printf("\nEnter the infix expression : ");
    gets(exp);

    infix_2_Postfix(exp);

    return 0;
}