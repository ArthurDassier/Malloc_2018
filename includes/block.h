/*
** EPITECH PROJECT, 2019
** block.h
** File description:
** block
*/

#ifndef BLOCK_H_
#define BLOCK_H_

#define MAX_MALLOC 9223372036854775807
#define align4(x) (((((x) -1) >>2) <<2)+4)

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>

typedef struct s_block block_t;

/* TOOLS */

block_t* compare_ptr(void *ptr);
block_t *fusion(block_t *to_fusion);
void *free_and_return_null(void *ptr);
void *unlock_thread_and_return_ptr(void *ptr);

void *my_realloc(void *ptr, size_t size);
void my_free(void *ptr);
void *my_calloc(size_t const nb, size_t const size);
void *my_malloc(size_t size);

/* ALGO */

void show_alloc_mem();
block_t *find_free_block(block_t *base, size_t const size);
void *create_new_block(block_t *base, size_t const size);
block_t *start_mem(size_t const size);
block_t *split_block(block_t *to_split, size_t size);

struct s_block
{
    size_t  size;
    block_t *next;
    block_t *prev;
    bool     free;
    void    *adresse;
};

#endif /* !BLOCK_H_ */
