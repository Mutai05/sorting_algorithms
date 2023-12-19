#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using Counting sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size) {
    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    int max = array[0];
    for (size_t i = 1; i < size; ++i) {
        if (array[i] > max)
            max = array[i];
    }

    /* Create counting array and initialize with 0 */
    int *count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    for (int i = 0; i <= max; ++i)
        count[i] = 0;

    /* Count occurrences of each element */
    for (size_t i = 0; i < size; ++i)
        count[array[i]]++;

    /* Print the counting array */
    printf("0");
    for (int i = 1; i <= max; ++i)
        printf(", %d", count[i]);
    printf("\n");

    /* Update array with sorted values from counting array */
    int j = 0;
    for (int i = 0; i <= max; ++i) {
        while (count[i] > 0) {
            array[j++] = i;
            count[i]--;
        }
    }

    free(count);
}
