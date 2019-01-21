#ifndef BLOCK_H
#define BLOCK_H
#include <stdbool.h>
// typedef struct s_block *block_t;
// #define BLOCK_SIZE 12
//
// #define align4(x) (((((x) -1) >>2) <<2)+4)// ATTENTION
// struct s_block {
// 	size_t size;
// 	block_t next;
// 	int free;
// 	char data[1];
// };


typedef struct s_block block_t;

struct s_block {
	size_t size;
	block_t *next;
	bool is_occuped;
	long long adresse[1];
};

#endif
