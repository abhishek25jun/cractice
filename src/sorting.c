#include <stdio.h>
#include "include.h"

void swap(int *array, int i, int j) 
{
	int tmp;
	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

void printarray(int arr[], int n)
{
	int index;
	for(index = 0; index < n; index++) {
		printf("%d\n", arr[index]);
	}
}
/**
 * This is the brute force technique of sorting
 * complexity: o(n2)
 * */
void bubblesort(int *arr, int n)
{
	int i, j;

	printf("input array is:\n");
	printarray(arr, n);
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < (n); j++) {
			if (arr[i] < arr[j]) {
				swap(arr, i, j);
			}
		}
	}
	printf("sorted array is:\n");
	printarray(arr, n);
}

/**
 * Selection sort is a simple sorting algorithm.
 * This sorting algorithm is an in-place comparison-based algorithm in which 
 * the list is divided into two parts, the sorted part at the left end and the 
 * unsorted part at the right end. Initially, the sorted part is empty and the 
 * unsorted part is the entire list.
 * The smallest element is selected from the unsorted array and swapped with 
 * the leftmost element, and that element becomes a part of the sorted array.
 * This process continues moving unsorted array boundary by one element to the right.
 * This algorithm is not suitable for large data sets as its average and worst case 
 * complexities are of Ο(n2), where n is the number of items.
 * complexity: O(n2)
 **/
void selectionsort(int *arr, int n)
{
	int i;
	int index;
	int min;

	printf("input array is:\n");
	printarray(arr, n);
	
	for(index = 0; index < n; index++) {
		min = index;
		for(i = index+1; i < n; i++) {
			if (arr[i] < arr[index]) {
				min = i;
			}
		}
		if (min != index) {
			swap(arr, min, index);
		}

	}
	
	printf("sorted array is:\n");
	printarray(arr, n);
}

/**
 * sorting takes place by inserting a particular element at the appropriate position,
 * that’s why the name- insertion sorting. In the First iteration, second element A[1] 
 * is compared with the first element A[0]. In the second iteration third element is 
 * compared with first and second element. In general, in every iteration an element is 
 * compared with all the elements before it. While comparing if it is found that the 
 * element can be inserted at a suitable position, then space is created for it by shifting 
 * the other elements one position up and inserts the desired element at the suitable 
 * position. This procedure is repeated for all the elements in the list.
 * complexity: O(n2)
 * */

void insertionsort(int arr[], int n)
{
	int i;
	int j;
	int key;

	printf("input array:\n");
	printarray(arr, n);

	for (i = 1; i < n; i++) {
		key = arr[i];
		for (j = i - 1; ((j >= 0) && (arr[j] > key)); j--) {
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;
	}
	
	printf("sorted array:\n");
	printarray(arr, n);
}
