#ifndef BLOCK_H
#define BLOCK_H
#include <stdbool.h>
// typedef struct s_block *block_t;
// #define BLOCK_SIZE 20
//
#define align4(x) (((((x) -1) >>2) <<2)+8)// ATTENTION
// struct s_block {
// 	size_t size;
// 	block_t next;
// 	int free;
// 	char data[1];
// };

void *malloc(size_t size);


typedef struct s_block block_t;

struct s_block {
    size_t size;
    block_t *next;
    // block_t *prev;
    int free;
    char data[1];
};

#endif
