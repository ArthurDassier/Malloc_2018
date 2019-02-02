/*
** EPITECH PROJECT, 2019
** interface.c
** File description:
** interface.c
*/

#include "block.h"

void get_last_block()
{
    
}

void free(void *ptr)
{
    return (my_free(ptr));
}

void *malloc(size_t size)
{
    return (my_malloc(size));
}

void *realloc(void *ptr, size_t size)
{
    return (my_realloc(ptr, size));
}

void *calloc(size_t const nb, size_t const size)
{
    return (my_calloc(nb, size));
}
