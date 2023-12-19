#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the linked list
 * @first: First node to be swapped
 * @second: Second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *first, listint_t *second)
{
    if (!first || !second)
        return;

    if (first->prev != NULL)
        first->prev->next = second;
    else
        *list = second;

    if (second->next != NULL)
        second->next->prev = first;

    first->next = second->next;
    second->prev = first->prev;
    first->prev = second;
    second->next = first;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      using the Cocktail Shaker sort algorithm
 * @list: Pointer to the head of a doubly linked list of integers
 *
 * Description: Prints the list after each swap.
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 0;
    listint_t *start = NULL;

    if (!list || !(*list) || !(*list)->next)
        return;

    do {
        swapped = 0;
        for (start = *list; start->next != NULL; start = start->next)
        {
            if (start->n > start->next->n)
            {
                swap_nodes(list, start, start->next);
                swapped = 1;
                print_list((const listint_t *)*list);
            }
        }
        if (!swapped)
            break;

        swapped = 0;
        for (; start->prev != NULL; start = start->prev)
        {
            if (start->n < start->prev->n)
            {
                swap_nodes(list, start->prev, start);
                swapped = 1;
                print_list((const listint_t *)*list);
            }
        }
    } while (swapped);
}
