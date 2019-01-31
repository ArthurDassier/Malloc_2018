/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "block.h"
extern block_t *base;
extern pthread_mutex_t mutex_stock;

void my_free(void *ptr)
{
    if (ptr == NULL)
        return;
    block_t* to_free = compare_ptr(ptr);
    if (to_free != NULL) {
        pthread_mutex_lock(&mutex_stock);

        to_free->free = true;
        if (to_free->prev != NULL && to_free->prev->free == true)
            to_free = fusion(to_free->prev);
        pthread_mutex_unlock(&mutex_stock);
    }
}

void *my_realloc(void *ptr, size_t size)
{
    block_t *old = NULL;
    void    *new_ptr = NULL;

    if (ptr == NULL)
        return (my_malloc(size));
    if (size == 0)
        free_and_return_null(ptr);
    new_ptr = my_malloc(size);
    if (new_ptr == NULL)
        return (free_and_return_null(ptr));
    old = compare_ptr(ptr);
    if (old == NULL)
        return (NULL);
    new_ptr = memcpy(new_ptr, old->adresse, size);
    my_free(ptr);
    return (new_ptr);
}

void *my_calloc(size_t const nb, size_t const size)
{
    char *new = my_malloc(size * nb);

    if (size == 0 || nb == 0 || new == NULL)
        return (NULL);
    for (size_t i = 0; i < nb * size; ++i)
        new[i] = 0;
    return (new);
}

void *my_malloc(size_t size)
{
    block_t *new_block = NULL;
    size = align4(size);

    if (size > MAX_MALLOC)
        return (NULL);
    pthread_mutex_lock(&mutex_stock);
    if (base == NULL) {
        base = start_mem(size);
        if (base == NULL)
            return (NULL);
        return (unlock_thread_and_return_ptr(base->adresse));
    }
    new_block = find_free_block(base, size);
    if (new_block == NULL)
        new_block = create_new_block(base, size);
    if (new_block == NULL)
        return (unlock_thread_and_return_ptr(NULL));
    pthread_mutex_unlock(&mutex_stock);
    return (new_block->adresse);
}
