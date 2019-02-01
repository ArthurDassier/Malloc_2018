/*
** EPITECH PROJECT, 2019
** alloc_tests.cpp
** File description:
** alloc_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "block.h"

Test(tests_calloc, calloc_return_not_null)
{
    cr_assert_not_null(my_calloc(2, 10));
}

Test(tests_calloc, calloc_return_good_size)
{
    char *test = my_calloc(2, 10);
    block_t *the_cast = NULL;

    test -= sizeof(block_t);
    the_cast = (block_t *)test;
    cr_assert_eq(the_cast->size, 20);
}

Test(tests_calloc, calloc_return_set_memory)
{
    char *test = my_calloc(2, 10);

    for(size_t i = 0; i < 20; ++i)
        cr_assert_eq(test[i], 0);
}

Test(tests_calloc, calloc_return_null)
{
    cr_assert_null(my_calloc(1000, 999999999999999999));
    cr_assert_null(my_calloc(-1, 999999999999999999));
    cr_assert_null(my_calloc(1000, -1));
}
