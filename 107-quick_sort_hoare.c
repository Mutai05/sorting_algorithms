#include <stdio.h>
#include "sort.h"

/**
 * hoare_partition - function to partition the array
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: index of the partition
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        if (i != j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            print_array(array, size);
        }
    }
}

/**
 * quicksort_hoare - sorts an array of integers in ascending order using Quick sort algorithm
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = hoare_partition(array, low, high, size);

        quicksort_hoare(array, low, pi, size);
        quicksort_hoare(array, pi + 1, high, size);
    }
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_hoare(array, 0, size - 1, size);
}
