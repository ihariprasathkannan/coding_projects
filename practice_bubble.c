#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"

void bubble_sort(int *arr, int size){

	int i,j;
	int temp;

	for(i=0; i < size-1; i++) {
		for(j=0; j< size-i-1; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main() {
	int size;
	printf("Enter size for array you want to create: ");
	scanf("%d",&size);
	int *arr= createArray(size);
	printf("Before sorting:\n");
	printArray(arr, size);
	bubble_sort(arr, size);
	printf("After sorting: \n");
	printArray(arr, size);
	free(arr);
	getchar();
	getchar();
	return 0;
}

