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
    char *test_size = my_realloc(NULL, 1);
    block_t *the_cast = NULL;

    test_size -= sizeof(block_t);
    the_cast = (block_t *)test_size;
    cr_assert_eq(the_cast->size, 4);
}

Test(tests_realloc, realloc_return_more_size)
{
    char *test_size = my_realloc(NULL, 1);
    block_t *the_cast = NULL;

    test_size = my_realloc(test_size, 8);
    test_size -= sizeof(block_t);
    the_cast = (block_t *)test_size;
    cr_assert_eq(the_cast->size, 8);
}

Test(tests_realloc, realloc_return_good_less_size)
{
    char *test_size = my_realloc(NULL, 8);
    block_t *the_cast = NULL;

    test_size = my_realloc(test_size, 1);
    test_size -= sizeof(block_t);
    the_cast = (block_t *)test_size;
    cr_assert_eq(the_cast->size, 4);
}

Test(tests_realloc, realloc_return_null)
{
    cr_assert_null(my_realloc(NULL, 999999999999999999));
}
