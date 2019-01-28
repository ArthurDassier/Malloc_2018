/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "block.h"
extern block_t *base;
static pthread_mutex_t mutex_stock = PTHREAD_MUTEX_INITIALIZER;

void free(void *ptr)
{
    if (ptr == NULL) {
        //INDIQUER UNE ERREUR
        return;
    }
    block_t* to_free = compare_ptr(ptr);
    if (to_free != NULL) {
        pthread_mutex_lock(&mutex_stock);

        to_free->free = true;
        if (to_free->prev != NULL && to_free->prev->free == true)
            to_free = fusion(to_free->prev);
        pthread_mutex_unlock(&mutex_stock);
    }
}

void *realloc(void *ptr, size_t size)
{
    block_t *old = NULL;
    void    *new_ptr = NULL;

    if (ptr == NULL) {
        new_ptr = malloc(size);
        return (new_ptr);
    }
    if (size == 0) {
        free(ptr);
        return (NULL);
    }
    new_ptr = malloc(size);
    if (new_ptr == NULL) {
        free(ptr);
        return (NULL);
    }
    old = compare_ptr(ptr);
    if (old == NULL) {
        return (NULL);
    }
    if (old->size > size)
        new_ptr = memcpy(new_ptr, old->adresse, size);
    else
        new_ptr = memcpy(new_ptr, old->adresse, size);
    free(ptr);
    return (new_ptr);
}

void *calloc(size_t const nb, size_t const size)
{
    char *new = malloc(size * nb);

    if (size == 0 || nb == 0 || new == NULL)
        return (NULL);
    for (size_t i = 0; i < nb * size; ++i)
        new[i] = 0;
    return (new);
}

void *malloc(size_t size)
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
        pthread_mutex_unlock(&mutex_stock);
        return (base->adresse);
    }
    new_block = find_free_block(base, size);
    if (new_block == NULL) {
        new_block = create_new_block(base, size);
    }
    if (new_block == NULL) {
        pthread_mutex_unlock(&mutex_stock);
        return (NULL);
    }
    pthread_mutex_unlock(&mutex_stock);
    return (new_block->adresse);

}