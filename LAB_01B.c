//Write a program to implement a Binary Search algorithm. Write a search function which takes a SearchList as its first parameter and a Comparable as its second. If either parameter is null, or if the SearchList is empty, you should return NULL.
 //implement the following algorithm: 
// Examine the value in the middle of the current array and print it. 
 //If the midpoint value is the value that we are looking for, return true 
 //If the value that we are looking for is greater than the midpoint value, adjust the current array to start at the midpoint and print the index.
 //if the value that we are looking for is less than the midpoint value, adjust the current array to end at the midpoint  and print the index.
//Continue until you find the value, or until the start reaches the end, 
 
#include <stdio.h>

int binarySearch(int arr[], int size, int searchValue) {
    if (arr == NULL || size == 0) {
        return 0; // Return 0 (false) if array is NULL or empty
    }

    int start = 0;
    int end = size;

    while (start < end) {
        int mid = (start + end) / 2;
        printf("Examining value at index %d: %d\n", mid, arr[mid]);

        if (arr[mid] == searchValue) {
            return 1; // Found the value, return 1 (true)
        } else if (searchValue > arr[mid]) {
            start = mid + 1;
            printf("Adjust start to %d\n", start);
        } else {
            end = mid;
            printf("Adjust end to %d\n", end);
        }
    }

    return 0; // Value not found, return 0 (false)
}

int main() {
    int n, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array is empty.\n");
        return 0;
    }

    int arr[n];

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to search: ");
    scanf("%d", &value);

    if (binarySearch(arr, n, value)) {
        printf("Value %d found in the array.\n", value);
    } else {
        printf("Value %d not found in the array.\n", value);
    }

    return 0;
}
