/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "block.h"
extern block_t *base;
void *last_break = NULL;

block_t *split_block(block_t *to_split, size_t size)
{
    block_t *new = NULL;
    void *new_ptr = to_split->adresse + size + sizeof(block_t);

    new = to_split->adresse + size;
    new->adresse = new_ptr;
    new->prev = to_split;
    new->next = to_split->next;
    to_split->next = new;
    new->size = to_split->size - size;
    to_split->size = to_split->size - new->size - sizeof(block_t);
    return (to_split);
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

block_t *find_free_block(block_t *base, size_t const size)
{
    while (base) {
        if (base->free == true && base->size >= size) {
            break;
        }
        base = base->next;
    }
    if (base)
        base->free = false;
    return (base);
}

block_t *get_end()
{
    block_t *tmp = base;

    for (; tmp->next; tmp = tmp->next);
        return (tmp);
    // if (base->prev == NULL)
    //     return (base);
    // return (base->prev);
}

void *create_new_block(size_t const size)
{
    block_t *end = get_end();
    void *new_ptr;

    if (last_break != sbrk(0)) {
        new_ptr = sbrk(0);
        if (sbrk(((sizeof(block_t) + size) / getpagesize() + 1) * getpagesize()) == (void *) -1)
            return (NULL);
        last_break = sbrk(0);
        end->next = new_ptr;
        end->next->free = false;
        end->next->size = size;
        end->next->next = NULL;
        end->next->prev = end;
        end->next->adresse = sizeof(block_t) + new_ptr + end->size;
        return (end->next);
    }
    if (end->adresse + end->size + sizeof(block_t) + size >= sbrk(0)) {
        if (sbrk(((sizeof(block_t) + size) / getpagesize() + 1) * getpagesize()) == (void *) -1)
            return (NULL);
        last_break = sbrk(0);
    }
    end->next = end->adresse + end->size;
    end->next->free = false;
    end->next->size = size;
    end->next->next = NULL;
    end->next->prev = end;
    end->next->adresse = sizeof(block_t) + end->adresse + end->size;
    return (end->next);
}

block_t *start_mem(size_t const size)
{
    block_t *new_mem;
    void *new_ptr = sbrk(((sizeof(block_t) + size) / getpagesize() + 1) * getpagesize());

    if (new_ptr == (void *) -1)
        return (NULL);
    last_break = sbrk(0);
    new_mem = new_ptr;
    new_mem->size = size;
    new_mem->free = false;
    new_mem->next = NULL;
    new_mem->prev = NULL;
    new_mem->adresse = sizeof(block_t) + new_ptr;
    return (new_mem);
}
