// PROGRAM TO IMPLEMENT CIRCULAR QUEUE USING ARRAY
// WRITTEN BY:  MANISH KUMAR
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % MAX == front)
    {
        printf("QUEUE OVERFLOW (FULL)\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("INSERTED -> %d\n", value);
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("QUEUE UNDERFLOW (EMPTY)\n");
    }
    else
    {
        printf("DELETED -> %d\n", queue[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
        printf("QUEUE ELEMENTS: ");
        i = front;
        while (1)
        {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % MAX;
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
