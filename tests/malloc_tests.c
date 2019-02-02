/*
** EPITECH PROJECT, 2019
** alloc_tests.cpp
** File description:
** alloc_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "block.h"

Test(test_malloc, malloc_return_not_null)
{
    cr_assert_not_null(my_malloc(1));
    cr_assert_not_null(my_malloc(10));
    cr_assert_not_null(my_malloc(100));
}

Test(test_malloc, malloc_return_good_size)
{
    char *test = my_malloc(1);
    block_t *the_cast = NULL;

    test -= sizeof(block_t);
    the_cast = (block_t *)test;
    cr_assert_eq(the_cast->size, 4);
}

Test(test_malloc, malloc_return_null)
{
    cr_assert_null(my_malloc(999999999999999999));
}
