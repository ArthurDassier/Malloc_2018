/*
** EPITECH PROJECT, 2019
** block.h
** File description:
** block
*/

#ifndef BLOCK_H_
#define BLOCK_H_


#define MAX_MALLOC 9223372036854775807

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct s_block block_t;

/* TOOLS */

block_t* compare_ptr(void *ptr);
block_t *fusion(block_t *to_fusion);



void *my_realloc(void *ptr, size_t size);
void my_free(void *ptr);
void *my_calloc(size_t const nb, size_t const size);
void *my_malloc(size_t size);

/* ALGO */

void show_alloc_mem();
block_t * find_free_block(block_t *base, size_t const size);
void *create_new_block(block_t *base, size_t const size);
block_t *start_mem(size_t const size);


// extern block_t *base;

struct s_block
{
    size_t  size;
    block_t *next;
    block_t *prev;
    int     free;
    void    *adresse;
};

#endif /* !BLOCK_H_ */
