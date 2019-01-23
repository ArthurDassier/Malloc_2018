/*
** EPITECH PROJECT, 2019
** block.h
** File description:
** block
*/

#ifndef BLOCK_H_
#define BLOCK_H_

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct s_block block_t;

struct s_block
{
    size_t  size;
    block_t *next;
    block_t *prev;
    int     free;
    void    *adresse;
};

#endif /* !BLOCK_H_ */
