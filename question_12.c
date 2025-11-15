// PROGRAM TO SORT AN ARRAY USING INSERTION SORT
// WRITTEN BY:  MANISH  KUMAR
#include <stdio.h>

int main()
{
    int arr[100], n, i, j, key;

    printf("ENTER NUMBER OF ELEMENTS: ");
    scanf("%d", &n);

    printf("ENTER %d ELEMENTS:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Insertion Sort
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("SORTED ARRAY IN ASCENDING ORDER:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}