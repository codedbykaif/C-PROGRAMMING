
#include <stdio.h>

int main()
{
    int arr[100], n, i, j, min, temp;

    printf("ENTER NUMBER OF ELEMENTS: ");
    scanf("%d", &n);

    printf("ENTER %d ELEMENTS:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Selection Sort
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
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
