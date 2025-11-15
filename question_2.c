#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert();
void deleteNode();
void search();
void display();

int main()
{
    int choice;
    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Insert (Ascending Order)\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            deleteNode();
            break;
        case 3:
            search();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);
    return 0;
}

void insert()
{
    int value;
    struct node *newNode, *temp, *prev;
    newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value to insert: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;

    // Case 1: Empty list or insert at beginning
    if (head == NULL || value < head->data)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp != NULL && temp->data < value)
        {
            prev = temp;
            temp = temp->next;
        }
        newNode->next = temp;
        prev->next = newNode;
    }
    printf("Node inserted successfully.\n");
}

void deleteNode()
{
    int value;
    struct node *temp = head, *prev = NULL;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);
    // Delete head node
    if (head->data == value)
    {
        head = head->next;
        free(temp);
        printf("Node deleted successfully.\n");
        return;
    }
    // Search and delete
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Value not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted successfully.\n");
}
void search()
{
    int value, pos = 1;
    struct node *temp = head;
    printf("Enter value to search: ");
    scanf("%d", &value);

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Element found at position %d.\n", pos);
            return;
        }
        pos++;
        temp = temp->next;
    }
    printf("Element not found.\n");
}
void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List elements in ascending order: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
