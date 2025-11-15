#include <stdio.h>

#define MAX 100
void insert(int arr[], int *n);
void deleteElement(int arr[], int *n);
void search(int arr[], int n);
void display(int arr[], int n);

int main()
{
    int arr[MAX], n = 0, choice;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert(arr, &n);
            break;
        case 2:
            deleteElement(arr, &n);
            break;
        case 3:
            search(arr, n);
            break;
        case 4:
            display(arr, n);
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

void insert(int arr[], int *n)
{
    int pos, value, i;
    if (*n == MAX)
    {
        printf("Array is full!\n");
        return;
    }
    printf("Enter position (0 to %d): ", *n);
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &value);

    for (i = *n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    (*n)++;
}

void deleteElement(int arr[], int *n)
{
    int pos, i;
    if (*n == 0)
    {
        printf("Array is empty!\n");
        return;
    }
    printf("Enter position to delete (0 to %d): ", *n - 1);
    scanf("%d", &pos);

    for (i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}

void search(int arr[], int n)
{
    int value, i, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &value);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            printf("Element found at position %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Element not found!\n");
}

void display(int arr[], int n)
{
    int i;
    if (n == 0)
    {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements are: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
