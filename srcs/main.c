#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "block.h"

//
// void *base = NULL;
//
// void split_block(block_t old, size_t s)
// {
// 	block_t new;
// 	new = old->data + s;
// 	new->size = old->size - s - BLOCK_SIZE;
// 	new->next = old->next;
// 	new->free = 1;
// 	old->size = s;
// 	old->next = new;
// }
//
// block_t extend_heap(block_t last, size_t s)
// {
// 	block_t b = sbrk(0);
//
// 	if (sbrk(BLOCK_SIZE + s) == (void*) - 1)
// 		return (NULL);
// 	b->size = s;
// 	b->next = NULL;
// 	if (last)
// 		last->next = b;
// 	b->free = 0;
// 	return (b);
// }
//
// block_t find_block(block_t last, size_t size)
// {
// 	block_t b = last;
// 	while (b && !(b->free && b->size >= size)) {
// 		last = b;
// 		b = b->next;
// 	}
// 	return (b);
// }
//
// void *my_malloc(size_t size)
// {
// 	block_t b;
// 	block_t last;
// 	size_t s;
//
// 	s = align4(size);
// 	if (base) {
// 		last = base;
// 		b = find_block(last, s);
// 		if (b) {
// 			printf("%d\n", b->size);
// 			if ((b->size -s ) >= (BLOCK_SIZE + 4)) {
// 				split_block(b, s);
// 			}
// 		b->free = 0;
// 		}
// 		else {
// 			b = extend_heap(last, s);
// 			if (b == NULL)
// 				return (NULL);
// 		}
// 	}
// 	else {
// 		b = extend_heap(NULL, s);
// 	if (!b)
// 		return (NULL);
// 	base = b;
// 	}
// 	return (b->data);
//
// }

block_t *list = NULL;

void *extend_heap(size_t size)
{

	block_t *new = sbrk(0);
	void *ptr = sbrk(0);

	if (sbrk(sizeof(block_t)) == (void*) - 1)
		return (NULL);
	if (sbrk(size) == (void*) - 1)
			return (NULL);
	new->size = size;
	new->adresse[0] = (long long)ptr;
	new->next = NULL;
	if (list)
		list->next = new;
	else
	list = new;
	return (ptr);

}

void *malloc(size_t size)
{
	void *ptr = extend_heap(size);
	return (ptr);
}

void free(void *ptr)
{
	block_t *tmp = list;

	while (tmp) {
		if ((tmp->adresse[0]) == (long long)ptr) {
			break;
		}
		tmp = tmp->next;
	}
	if (tmp)
		tmp->is_occuped = 0;
}

void *realloc(void *ptr,size_t size)
{

}


// void main()
// {
//  	int *p = my_malloc(sizeof(int) * 10000);
// 	int *t = my_malloc(sizeof(int) * 10000);
//
// 	t[0] = 3;
// 	p[5] = 1;
// 	printf("%d\n", t[0]);
// 	printf("%d\n", p[5]);
//
// 	my_free(t);
// 	my_free(p);
//
// 	// my_malloc(sizeof(char) * 1);
// 	// for (int i = 0; i != 12; i++) {
// 	// 	p[i] = 100;
// 	//
// 	// }
// }
