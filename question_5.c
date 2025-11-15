// PROGRAM TO IMPLEMENT LINEAR QUEUE USING ARRAY
// WRITTEN BY:  MANISH KUMAR

#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("QUEUE OVERFLOW\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("INSERTED -> %d\n", value);
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("QUEUE UNDERFLOW\n");
    }
    else
    {
        printf("DELETED -> %d\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if (front == -1 || front > rear)
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
        printf("QUEUE ELEMENTS: ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. ENQUEUE (INSERT)\n");
        printf("2. DEQUEUE (DELETE)\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("ENTER VALUE TO INSERT: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("EXITING PROGRAM.\n");
            break;
        default:
            printf("INVALID CHOICE! TRY AGAIN.\n");
        }
    } while (choice != 4);

    return 0;
}
