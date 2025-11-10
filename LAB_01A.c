//Write a program to accept ‘n’ numbers into an array and then calculate the 
// sum of numbers present in odd positions and even positions respectively.
#include <stdio.h>

int main() {
    int n, i;
    int sumOddPositions = 0, sumEvenPositions = 0;
    
    printf("Enter the number of elements (n): ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for(i = 0; i < n; i++) {
        // Positions start from 1, so check (i+1)
        if ((i + 1) % 2 == 1) {
            sumOddPositions += arr[i];
        } else {
            sumEvenPositions += arr[i];
        }
    }
    
    printf("Sum of elements at odd positions: %d\n", sumOddPositions);
    printf("Sum of elements at even positions: %d\n", sumEvenPositions);
    
    return 0;
}
