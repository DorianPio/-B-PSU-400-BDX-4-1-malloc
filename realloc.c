/*
** EPITECH PROJECT, 2021
** undefined
** File description:
** realloc
*/

#include "include/malloc.h"

void *error_return(void *ptr1, void *ptr2)
{
    if (ptr1)
        free(ptr1);
    if (ptr2)
        free(ptr2);
    return NULL;
}

void *realloc(void *ptr, size_t size)
{
    t_malloc *node = NULL;
    void *result = malloc(size);

    if (!ptr)
        return result;
    if (size == 0) {
        return error_return(ptr, result);
    }
    node = (t_malloc*)((char*)ptr - SIZE_NODE);
    if (node->empty) {
        return error_return(result, NULL);
    }
    if (node->pos_mem >= paging_malloc(size)) {
        free(result);
        return ptr;
    }
    if (result != NULL)
        memcpy(result, (char *)node + SIZE_NODE, node->pos_mem);
    free(ptr);
    return result;
}