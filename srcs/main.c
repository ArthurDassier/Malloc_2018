/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "block.h"

block_t *base = NULL;
pthread_mutex_t mutex_stock = PTHREAD_MUTEX_INITIALIZER;

block_t *fusion(block_t *to_fusion)
{
    if (to_fusion->next == NULL)
        return (to_fusion);
    if (to_fusion->next->free == true) {
        to_fusion->size = sizeof(block_t) + to_fusion->next->size;
        to_fusion->next = to_fusion->next->next;
        if (to_fusion->next)
            to_fusion->next->prev = to_fusion;
    }
    return (to_fusion);
}
