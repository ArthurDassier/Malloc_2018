/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "block.h"
extern block_t *base;

// block_t *base = NULL;

void show_alloc_mem()
{
    block_t *tmp = base;
    printf("break : %p\n", sbrk(0));

    while (tmp) {
        printf("%p - %p : %lu bytes\n", tmp->adresse,
        tmp->adresse + tmp->size, tmp->size);
        tmp = tmp->next;
    }
}

block_t * find_free_block(block_t *base, size_t const size)
{
    while (base && !(base->free && base->size >= size))
        base = base->next;
    if (base)
        base->free = false;
    return (base);
}

void *create_new_block(block_t *base, size_t const size)
{
    void *new_ptr = sbrk(sizeof(block_t) + size);

    if (new_ptr == (void *) -1)
        return (NULL);
    while (base->next)
        base = base->next;
    base->next = new_ptr;
    base->next->free = false;
    base->next->size = size;
    base->next->next = NULL;
    base->next->prev = base;
    base->next->adresse = sizeof(block_t) + new_ptr;
}

block_t *start_mem(size_t const size)
{
    block_t * new_mem;
    void *new_ptr = sbrk(sizeof(block_t) + size);

    if (new_ptr == (void *) -1)
        return (NULL);
    new_mem = new_ptr;
    new_mem->size = size;
    new_mem->free = false;
    new_mem->next = NULL;
    new_mem->prev = NULL;
    new_mem->adresse = sizeof(block_t) + new_ptr;
    return (new_mem);
}
