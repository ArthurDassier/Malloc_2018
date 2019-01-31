/*
** EPITECH PROJECT, 2019
** alloc_tests.cpp
** File description:
** alloc_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "block.h"

Test(tests_start_mem, start_mem_return_not_null)
{
    cr_assert_not_null(start_mem(2));
}

Test(tests_start_mem, start_mem_return_good_size)
{
    block_t *test = start_mem(2);

    cr_assert_eq(test->size, 2);
}

Test(tests_start_mem, start_mem_return_null)
{
    block_t *test = start_mem(0);

    cr_assert_null(test->size);
}
