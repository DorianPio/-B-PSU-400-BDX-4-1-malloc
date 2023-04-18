/*
** EPITECH PROJECT, 2021
** undefined
** File description:
** calloc
*/

#include "include/malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    int len = nmemb * size;
    void *result = malloc(len);

    if (!result)
        return NULL;
    memset(result, 0, len);
    return result;
}