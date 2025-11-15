#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    if (top == NULL)
    {
        printf("STACK UNDERFLOW\n");
        exit(1);
    }
    struct node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int evaluatePostfix(char postfix[])
{
    int i;
    char ch;
    int val;
    int op1, op2;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch (ch)
            {
            case '+':
                val = op1 + op2;
                break;
            case '-':
                val = op1 - op2;
                break;
            case '*':
                val = op1 * op2;
                break;
            case '/':
                val = op1 / op2;
                break;
            case '^':
                val = pow(op1, op2);
                break;
            default:
                printf("INVALID OPERATOR\n");
                exit(1);
            }
            push(val);
        }
    }
    return pop();
}

int main()
{
    char postfix[100];
    int result;

    printf("ENTER POSTFIX EXPRESSION: ");
    scanf("%s", postfix);

    result = evaluatePostfix(postfix);
    printf("RESULT OF POSTFIX EXPRESSION = %d\n", result);

    return 0;
}
