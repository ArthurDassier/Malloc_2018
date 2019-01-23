/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "block.h"

block_t *base = NULL;

void show_alloc_mem()
{
    block_t *tmp = base;
    printf("break : %p\n", sbrk(0));

    while (tmp) {
        printf("%p - %p : %d bytes\n", tmp->adresse,
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

void *malloc(size_t size)
{
    block_t *new_block = NULL;

    if (base == NULL) {
        base = start_mem(size);
        if (base == NULL)
            return (NULL);
        return (base->adresse);
    }
    new_block = find_free_block(base, size);
    if (new_block == NULL)
        new_block = create_new_block(base, size);
    if (new_block == NULL)
        return (NULL);
    return (new_block->adresse);

}

block_t* compare_ptr(void *ptr)
{
    block_t *tmp = base;

    if (tmp == NULL)
        return (NULL);
    while (tmp) {
        if (tmp->adresse == ptr)
            return (tmp);
        tmp = tmp->next;
    }
    return (tmp);
}

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

void free(void *ptr)
{
    if (ptr == NULL) {
        //INDIQUER UNE ERREUR
        return;
    }
    block_t* to_free = compare_ptr(ptr);

    if (to_free != NULL) {
        to_free->free = true;
        if (to_free->prev != NULL && to_free->prev->free == true)
            to_free = fusion(to_free->prev);
    }
}

void *realloc(void *ptr, size_t size)
{
    block_t *old = NULL;
    void    *new_ptr = NULL;

    if (ptr == NULL)
        return (NULL);
    new_ptr = malloc(size);
    if (new_ptr == NULL) {
        free(ptr);
        return (NULL);
    }
    // pas besoin d'un nouveau header
    old = compare_ptr(ptr);
    if (old == NULL)
        return (NULL);
    // copie de la memoire plutot que du header
    // si tu veux je te fais un schema demain
    new_ptr = memcpy(new_ptr, old->adresse, old->size);
    free(ptr);
    return (new_ptr);
}

// void *calloc(int const nb, size_t const size)
// {
//     char *new = my_malloc(nb * size);
//
//     if (new == NULL)
//         return (NULL);
//     for (size_t i = 0; i < size; ++i)
//         new[i] = 0;
//     return (new);
// }

// int main()
// {
//     char *toto = my_calloc(2, sizeof(char) * 3);
//
//     toto[0] = 'S';
//     toto[1] = 'a';
//     toto[2] = '\0';
//
//     printf("%s\n", toto);
//     toto = my_realloc(toto, 4);
//     toto[2] = 'b';
//     toto[3] = '\0';
//     printf("%s\n", toto);
//     // test de free
//     char *toto1 = my_malloc(sizeof(char) * 3);
//
//     char *toto2 = my_malloc(sizeof(char) * 5);
//     show_alloc_mem();
// }
