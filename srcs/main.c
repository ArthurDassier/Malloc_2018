#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "block.h"
#include <string.h>

block_t *find_block(block_t **last, size_t size);

block_t *base = NULL;

void *extend_heap(block_t *last, size_t allign)
{
    block_t *new = sbrk(0);

    if (sbrk(sizeof(block_t) + allign) == (void *) - 1)
        return (NULL);
    new->size = allign;
    new->next = NULL;
    // new->prev = last;
    new->free = 0;
    if (last)
            last->next = new;
    return (new);

}

//void *calloc(size_t nmemb, size_t size)
//{
//    void *ptr = malloc(nmemb);
//
//    if (memset(ptr, 0, size) == NULL)
//        return (NULL);
//}

void split_block(block_t *b, size_t s)
{
    block_t *new;

    new = b->data + s;
    new->size = b->size - s - sizeof(block_t);
    new->next = b->next;
    // new->prev = b;
    new->free = 1;
    b->size = s;
    b->next = new;
    // if (new->next)
    //     new->next->prev = new;
}

void *my_malloc(size_t size)
{
    block_t *last;
    block_t *b;
    size_t s = align4(size);

    if (base) {
        last = base;
        b = find_block(&last, s);
        if (b) {
            if ((b->size -s ) >= (sizeof(block_t) + 8))
                split_block(b, s);
            b->free = 0;
        }
        else {
            b = extend_heap(last, s);
            if (b == NULL)
                return (NULL);
        }
    }
    else {
        b = extend_heap(NULL, size);
        if (b == NULL)
            return (NULL);
        base = b;
    }
    return (base->data);
}

block_t *find_block(block_t **last, size_t size)
{
    block_t *tmp = base;

    while (tmp && !(tmp->free && tmp->size >= size)) {
        *last = tmp;
        tmp = tmp->next;
    }
    return (tmp);

}

void free(void *ptr)
{
    // block_t *tmp = list;
    //
    // while (tmp) {
    //     if ((tmp->adresse[0]) == (long long)ptr) {
    //         break;
    //     }
    //     tmp = tmp->next;
    // }
    // if (tmp)
    //     tmp->is_occuped = 0;
}

void *realloc(void *ptr,size_t size)
{

}

// void show_mem_alloc()
// {
//     block_t *tmp = base;
//
//     if (tmp) {
//         printf("break : %p\n", tmp->data);
//         tmp = tmp->next;
//     }
//     while (tmp != NULL) {
//         printf("%d : %d bytes\n", , tmp->size);
//         tmp = tmp->next;
//     }
// }
//
// int main()
// {
//
//     int *p = my_malloc(sizeof(int) * 1);
//    int *a = my_malloc(sizeof(int) * 240);
//    int *c = my_malloc(sizeof(int) * 240);
//
//    for (int i = 0; i != 12; i++) {
//        p[i] = 100 + i;
//    }
//    for (int i = 0; i != 12; i++) {
//        printf("%d\n", p[i]);
//    }
//    // show_mem_alloc();
// }
