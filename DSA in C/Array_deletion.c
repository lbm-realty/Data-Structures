#include <stdio.h>

void show_array (int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delete_value (int arr[], int size, int capacity, int value, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main ()
{
    int arr[100] = {1, 3, 2, 18, 8};
    int capacity = 100, size = 5;
    show_array(arr, size);
    delete_value(arr, size, capacity, 2, 2);
    size -= 1;
    show_array(arr, size);

    return 0;
}