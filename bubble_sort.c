#include <stdio.h>
#include <stdlib.h>

/* Notes:
 * Bubble sort will focus on larger numbers, and tries to corner the larger number towards the end for every complete iteration of J
 * For example in below case at the end of first complete iteration of j, i.e, j=0 ... 6; Largest number 64 will be cornered to the
 * right end of the array, similarly it will do for n-1 iterations of j. Big O notation will be O(n^2).
 * */

void printArray(int arr[], int size);

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
	    printf("\ni:%d, j:%d j_limit:%d\n", i, j, n-i-1);
            // Compare adjacent elements
	    printf("i:%d Comparing element at j:%d[%d] with j+1:%d[%d] \n", i, j, arr[j], j+1, arr[j+1]);
            if (arr[j] > arr[j+1]) {
                // Swap if the element found is greater
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
		printArray(arr, n);
            }
        }
	printArray(arr, n);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Unsorted array: \n");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}
