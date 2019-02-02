/*
** EPITECH PROJECT, 2019
** free_block_tests.cpp
** File description:
** alloc_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "block.h"

Test(tests_find_free_block, find_free_block_return_not_null)
{
    block_t new;

    new.free = true;
    new.size = 4;
    cr_assert_not_null(find_free_block(&new, 4));
}

Test(tests_find_free_block, find_free_block_return_null_when_size_too_big)
{
    block_t new;

    new.free = true;
    new.size = 4;
    new.next = NULL;
    cr_assert_null(find_free_block(&new, 8));
}

Test(tests_find_free_block, find_free_block_return_null_when_free_is_false)
{
    block_t new;

    new.free = false;
    new.size = 8;
    new.next = NULL;
    cr_assert_null(find_free_block(&new, 8));
}
