// PROGRAM TO SORT AN ARRAY USING BUBBLE SORT
// WRITTEN BY:  MANISH  KUMAR

#include <stdio.h>

int main()
{
    int arr[100], n, i, j, temp;

    printf("ENTER NUMBER OF ELEMENTS: ");
    scanf("%d", &n);

    printf("ENTER %d ELEMENTS:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("SORTED ARRAY IN ASCENDING ORDER:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
