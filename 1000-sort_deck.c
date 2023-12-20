#include <stdlib.h>
#include <stdio.h>
#include "deck.h"

/* Custom string comparison function */
int custom_strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }

    if (*s1 != *s2)
        return (*s1 - *s2);
    return (0);
}

/* Get the numerical value of a card */
char get_card_value(deck_node_t *card) {
    const char *values[] = {"Ace", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    int i;
    for (i = 0; i < 14; i++) {
        if (custom_strcmp(card->card->value, values[i]) == 0)
            return (char)i;
    }
    return 13;
}

/* Sort a deck of cards based on their kind (spades to diamonds) */
void sort_deck_kind(deck_node_t **deck) {
    deck_node_t *iter, *insert, *tmp;

    for (iter = (*deck)->next; iter != NULL; iter = tmp) {
        tmp = iter->next;
        insert = iter->prev;
        while (insert != NULL && insert->card->kind > iter->card->kind) {
            insert->next = iter->next;
            if (iter->next != NULL)
                iter->next->prev = insert;
            iter->prev = insert->prev;
            iter->next = insert;
            if (insert->prev != NULL)
                insert->prev->next = iter;
            else
                *deck = iter;
            insert->prev = iter;
            insert = iter->prev;
        }
    }
}

/* Sort a deck of cards from ace to king (within the same kind) */
void sort_deck_value(deck_node_t **deck) {
    deck_node_t *iter, *insert, *tmp;

    for (iter = (*deck)->next; iter != NULL; iter = tmp) {
        tmp = iter->next;
        insert = iter->prev;
        while (insert != NULL &&
               insert->card->kind == iter->card->kind &&
               get_card_value(insert) > get_card_value(iter)) {
            insert->next = iter->next;
            if (iter->next != NULL)
                iter->next->prev = insert;
            iter->prev = insert->prev;
            iter->next = insert;
            if (insert->prev != NULL)
                insert->prev->next = iter;
            else
                *deck = iter;
            insert->prev = iter;
            insert = iter->prev;
        }
    }
}

/* Sort a deck of cards from ace to king and from spades to diamonds */
void sort_deck(deck_node_t **deck) {
    if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
        return;

    sort_deck_kind(deck);
    sort_deck_value(deck);
}

/* Utility function to print the deck of cards */
void print_deck(const deck_node_t *deck) {
    size_t i = 0;
    char kinds[4] = {'S', 'H', 'C', 'D'};

    while (deck) {
        if (i)
            printf(", ");
        printf("{%s, %c}", deck->card->value, kinds[deck->card->kind]);
        if (i == 12)
            printf("\n");
        i = (i + 1) % 13;
        deck = deck->next;
    }
}

/* Initializes the deck with provided cards */
deck_node_t *init_deck(const card_t cards[52]) {
    deck_node_t *deck;
    deck_node_t *node;
    size_t i;

    i = 52;
    deck = NULL;
    while (i--) {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        node->card = &cards[i];
        node->next = deck;
        node->prev = NULL;
        if (deck)
            deck->prev = node;
        deck = node;
    }
    return (deck);
}

/* Main function */
int main(void) {
    card_t cards[52] = {
        {"Jack", CLUB}, {"4", HEART}, {"3", HEART}, {"3", DIAMOND}, {"Queen", HEART}, {"5", HEART}, {"5", SPADE}, {"10", HEART}, {"6", HEART}, {"5", DIAMOND}, {"6", SPADE}, {"9", HEART}, {"7", DIAMOND}, {"Jack", SPADE}, {"Ace", DIAMOND}, {"9", CLUB}, {"Jack", DIAMOND}, {"7", SPADE}, {"King", DIAMOND}, {"10", CLUB}, {"King", SPADE}, {"8", CLUB}, {"9", SPADE}, {"6", CLUB}, {"Ace", CLUB}, {"3", SPADE}, {"8", SPADE}, {"9", DIAMOND}, {"2", HEART}, {"4", DIAMOND}, {"6", DIAMOND}, {"3", CLUB}, {"Queen", CLUB}, {"10", SPADE}, {"8", DIAMOND}, {"8", HEART}, {"Ace", SPADE}, {"Jack", HEART}, {"2", CLUB}, {"4", SPADE}, {"2", SPADE}, {"2", DIAMOND}, {"King", CLUB}, {"Queen", SPADE}, {"Queen", DIAMOND}, {"7", CLUB}, {"7", HEART}, {"5", CLUB}, {"10", DIAMOND}, {"4", CLUB}, {"King", HEART}, {"Ace", HEART},
    };

    deck_node_t *deck = init_deck(cards);
    if (!deck) {
        fprintf(stderr, "Error initializing the deck.\n");
        return EXIT_FAILURE;
    }

    printf("Original deck:\n");
    print_deck(deck);
    printf("\n\n");

    sort_deck(&deck);

    printf("Sorted deck:\n");
    print_deck(deck);

    return EXIT_SUCCESS;
}
