#include <stdio.h>

// Function to merge two sorted subarrays
void merge(int arr[], int left[], int right[], int leftSize, int rightSize) {
    int i = 0, j = 0, k = 0;

    // Merge elements from left[] and right[] back into arr[]
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // Copy the remaining elements of left[], if any
    while (i < leftSize)
        arr[k++] = left[i++];

    // Copy the remaining elements of right[], if any
    while (j < rightSize)
        arr[k++] = right[j++];
}

// Function to perform merge sort
void mergeSort(int arr[], int size) {
    if (size < 2)
        return;  // Base case: array is already sorted

    int mid = size / 2;
    int left[mid], right[size - mid];

    // Divide the array into two subarrays
    for (int i = 0; i < mid; i++)
        left[i] = arr[i];
    for (int i = mid; i < size; i++)
        right[i - mid] = arr[i];

    // Recursively sort the subarrays
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Merge the sorted subarrays
    merge(arr, left, right, mid, size - mid);
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, size);

    mergeSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
