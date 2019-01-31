/*
** EPITECH PROJECT, 2019
** alloc_tests.cpp
** File description:
** alloc_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "block.h"

Test(tests_realloc, realloc_return_not_null)
{
    cr_assert_not_null(my_realloc(NULL, 10));
}

Test(tests_realloc, realloc_return_good_size)
{
    char *test = my_realloc(NULL, 1);
    block_t *the_cast = NULL;

    test -= sizeof(block_t);
    the_cast = (block_t *)test;
    cr_assert_eq(the_cast->size, 4);
}

Test(tests_realloc, realloc_return_null)
{
    cr_assert_null(my_realloc(NULL, 999999999999999999));
}
