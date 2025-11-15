// PROGRAM TO IMPLEMENT QUEUE USING LINKED LIST
// WRITTEN BY: MANISH KUMAR

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("MEMORY ALLOCATION FAILED\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("INSERTED -> %d\n", value);
}

void dequeue()
{
    if (front == NULL)
    {
        printf("QUEUE UNDERFLOW (EMPTY)\n");
    }
    else
    {
        struct node *temp = front;
        printf("DELETED -> %d\n", front->data);
        front = front->next;
        free(temp);
        if (front == NULL)
            rear = NULL;
    }
}

void display()
{
    struct node *temp = front;
    if (temp == NULL)
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
        printf("QUEUE ELEMENTS: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
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
