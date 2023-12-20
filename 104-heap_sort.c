#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two elements in an array
 * @a: First element
 * @b: Second element
 **/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * heapify - Heapifies the array
 * @array: The array to be sorted
 * @size: Size of the heap
 * @i: Index of the root of the heap
 **/
void heapify(int *array, size_t size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        swap(&array[i], &array[largest]);
        print_array(array, size);
        heapify(array, size, largest);
    }
}

/**
 * heap_sort - Heap sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 **/
void heap_sort(int *array, size_t size) {
    int i;

    for (i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    for (i = size - 1; i > 0; i--) {
        swap(&array[0], &array[i]);
        print_array(array, size);
        heapify(array, i, 0);
    }
}
