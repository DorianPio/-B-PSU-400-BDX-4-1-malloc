/*
** EPITECH PROJECT, 2021
** new_malloc
** File description:
** utils
*/

#include "include/malloc.h"

size_t paging_malloc(size_t size)
{
    return ((size - 1) / 8 * 8 + 8);
}