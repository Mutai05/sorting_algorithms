#include <stdio.h>
#include "sort.h"

/**
 * bitonic_merge - merge in specific direction
 * @arr: array
 * @low: starting index
 * @count: elements count
 * @dir: direction (1 - ascending, 0 - descending)
 */
void bitonic_merge(int *arr, int low, int count, int dir)
{
    if (count > 1)
    {
        int k = count / 2;
        int i;

        for (i = low; i < low + k; ++i)
        {
            if ((arr[i] > arr[i + k]) == dir)
            {
                int temp = arr[i];
                arr[i] = arr[i + k];
                arr[i + k] = temp;
            }
        }

        bitonic_merge(arr, low, k, dir);
        bitonic_merge(arr, low + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - recursive call for bitonic sort
 * @arr: array
 * @low: starting index
 * @count: elements count
 * @dir: direction (1 - ascending, 0 - descending)
 */
void bitonic_sort_recursive(int *arr, int low, int count, int dir)
{
    if (count > 1)
    {
        int k = count / 2;

        printf("Merging [%d/%d] (%s):\n", count, (int)(count * 2), (dir == 1) ? "UP" : "DOWN");
        print_array(arr + low, count);

        bitonic_sort_recursive(arr, low, k, 1);
        bitonic_sort_recursive(arr, low + k, k, 0);

        bitonic_merge(arr, low, count, dir);

        printf("Result [%d/%d] (%s):\n", count, (int)(count * 2), (dir == 1) ? "UP" : "DOWN");
        print_array(arr + low, count);
    }
}

/**
 * bitonic_sort - sorts an array using bitonic sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    bitonic_sort_recursive(array, 0, (int)size, 1);
}
