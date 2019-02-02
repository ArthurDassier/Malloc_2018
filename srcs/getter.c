/*
** EPITECH PROJECT, 2019
** interface.c
** File description:
** interface.c
*/

#include "block.h"

void set_thread(int flag)
{
    static pthread_mutex_t mutex_stock = PTHREAD_MUTEX_INITIALIZER;

    if (flag == 0)
        pthread_mutex_lock(&mutex_stock);
    if (flag == 1)
        pthread_mutex_unlock(&mutex_stock);
}

void* get_last_break(const size_t flag, void *value)
{
    static void *last_block = NULL;

    if (flag == 1)
        last_block = value;
    return (last_block);
}
