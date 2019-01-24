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

// 
// int main()
// {
// //     char *toto = my_calloc(1, sizeof(char) * 3);
// //     toto[0] = 'S';
// //     toto[1] = 'a';
// //     toto[2] = '\0';
// //
// //     printf("%s\n", toto);
//     int *toto = my_malloc(-2);
//     if (toto == NULL)
//         printf("NULL");
//     // toto[100] = 12;
//     // show_alloc_mem();
// }
