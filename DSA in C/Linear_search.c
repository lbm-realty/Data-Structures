#include <stdio.h>

int linear_search (int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;    
}

int main ()
{
    int arr[] = {1, 3, 78, 91, 4, 52, 6, 9};
    int size = sizeof(arr)/sizeof(int);
    int element = 88;
    int search = linear_search(arr, size, element);
    printf("The element %d was found at index %d", element, search);

    return 0;
}
