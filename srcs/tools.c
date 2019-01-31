/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "block.h"

extern block_t *base;
extern pthread_mutex_t mutex_stock;

block_t* compare_ptr(void *ptr)
{
    block_t *tmp = base;

    if (tmp == NULL)
        return (NULL);
    while (tmp) {
        if (tmp->adresse == ptr) {
            return (tmp);
        }
        tmp = tmp->next;
    }
    return (tmp);
}

void *free_and_return_null(void *ptr)
{
    my_free(ptr);
    return (NULL);
}

void *unlock_thread_and_return_ptr(void *ptr)
{
    pthread_mutex_unlock(&mutex_stock);
    return (ptr);
}
