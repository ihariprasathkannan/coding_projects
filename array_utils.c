#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to create an array of specified size with user input
int* createArray(int size) {
    int *arr = (int*) malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    return arr;
}
