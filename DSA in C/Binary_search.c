#include <stdio.h>

int binary_search (int arr[], int size, int element)
{
    int low, high, mid;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main ()
{
    int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444};
    int size = sizeof(arr)/sizeof(int);
    int element = 3;
    int search = binary_search(arr, size, element);
    printf("The element %d was found at index %d", element, search);  
 
    return 0;
}