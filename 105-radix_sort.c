#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * count_sort - Sorts the array by counting the significant digit
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: The significant digit to count sort by
 **/
void count_sort(int *array, size_t size, int exp) {
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};
    int i;

    if (!output)
        return;

    for (i = 0; i < (int)size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    print_array(array, size);
    free(output);
}

/**
 * radix_sort - LSD Radix Sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 **/
void radix_sort(int *array, size_t size) {
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10)
        count_sort(array, size, exp);
}
