#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merge two subarrays of arr[]
 * @array: The array to be sorted
 * @left: Starting index of the left subarray
 * @middle: Middle index of the array
 * @right: Ending index of the right subarray
 * @tmp_array: Temporary array to store the merged subarrays
 **/
void merge(int *array, int left, int middle, int right, int *tmp_array)
{
    int i, j, k;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + left, middle - left);

    printf("[right]: ");
    print_array(array + middle, right - middle);

    i = left;
    j = middle;
    k = 0;

    while (i < middle && j < right)
    {
        if (array[i] <= array[j])
            tmp_array[k++] = array[i++];
        else
            tmp_array[k++] = array[j++];
    }

    while (i < middle)
        tmp_array[k++] = array[i++];
    while (j < right)
        tmp_array[k++] = array[j++];

    for (i = left, k = 0; i < right; i++, k++)
        array[i] = tmp_array[k];

    printf("[Done]: ");
    print_array(array + left, right - left);
}

/**
 * merge_sort - Merge sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 * Description: Implements the merge sort algorithm recursively
 **/
void merge_sort(int *array, size_t size)
{
    size_t m;
    int *tmp_array;

    if (size <= 1 || array == NULL)
        return;

    m = size / 2;

    merge_sort(array, m);
    merge_sort(array + m, size - m);

    tmp_array = malloc(size * sizeof(int));
    if (tmp_array == NULL)
        return;

    merge(array, 0, m, size, tmp_array);

    free(tmp_array);
}

