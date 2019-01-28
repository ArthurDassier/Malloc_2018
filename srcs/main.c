/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "block.h"

block_t *base = NULL;

block_t* compare_ptr(void *ptr)
{
    block_t *tmp = base;

    // printf("%p\n", ptr);
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
    // while (tmp) {
    //
    // }
    // while (tmp->prev) {
    //
    // }
}


// int main()
// {
//     char *array = my_malloc(100);
//     char *array2 = my_malloc(14);
//     char *array3 = my_malloc(35);
//     char *array4 = my_malloc(1);
//
//     // my_free(array);
//     // char *tab = my_malloc(1);
//     // show_alloc_mem();
//     // array = my_realloc(array,2);
//     show_alloc_mem();
// }
