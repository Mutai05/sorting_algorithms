#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * Enumerates the suits of playing cards.
 */
typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

/**
 * Represents a playing card.
 * @value: The value of the card from "Ace" to "King".
 * @kind: The suit of the card.
 */
typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

/**
 * Represents a node in a deck of cards.
 * @card: Pointer to the card of the node.
 * @prev: Pointer to the previous node in the list.
 * @next: Pointer to the next node in the list.
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

/**
 * Sorts a deck of cards.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
