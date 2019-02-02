/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "block.h"

extern block_t *base;
extern pthread_mutex_t mutex_stock;

block_t *get_end()
{
    block_t *tmp = base;

    if (base->prev)
        return (base->prev);
    for (; tmp->next; tmp = tmp->next);
    return (tmp);
}

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

void show_alloc_mem(void)
{
    block_t *tmp = base;
    printf("break : %p\n", sbrk(0));

    while (tmp) {
        printf("%p - %p : %lu bytes\n", tmp->adresse,
        tmp->adresse + tmp->size, tmp->size);
        tmp = tmp->next;
    }
}

void *free_and_return_null(void *ptr)
{
    my_free(ptr);
    return (NULL);
}

void *unlock_thread_and_return_ptr(void *ptr)
{
    set_thread(1);
    return (ptr);
}
