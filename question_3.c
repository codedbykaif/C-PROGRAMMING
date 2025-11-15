#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    if (top == MAX - 1)
        printf("STACK OVERFLOW\n");
    else
        stack[++top] = c;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

int main()
{
    char infix[MAX], postfix[MAX];
    char ch, x;
    int i = 0, j = 0;

    printf("ENTER INFIX EXPRESSION: ");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0')
    {
        if (isalnum(ch))
            postfix[j++] = ch;
        else if (ch == '(')
            push(ch);
        else if (ch == ')')
        {
            while ((x = pop()) != '(')
                postfix[j++] = x;
        }
        else
        {
            while (precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("POSTFIX EXPRESSION: %s\n", postfix);
    return 0;
}
