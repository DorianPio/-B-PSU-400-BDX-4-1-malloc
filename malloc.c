/*
** EPITECH PROJECT, 2021
** new_malloc
** File description:
** malloc
*/

#include "include/malloc.h"

t_malloc *data_block = NULL;
t_malloc *data_block_actu = NULL;
size_t page_size = 0;

t_malloc *alloc_block(t_malloc *ptr, size_t size)
{
    t_malloc *new_node = NULL;

    if ((int)(ptr->pos_mem - (size + SIZE_NODE)) >= 8) {
        new_node = CAST(ptr, size);
        new_node->prev = ptr;
        new_node->next = ptr->next;
        new_node->pos_mem = ptr->pos_mem - (size + SIZE_NODE);
        new_node->empty = true;
        if (ptr->next)
            ptr->next->prev = new_node;
        ptr->next = new_node;
        ptr->pos_mem = size;
        if (data_block_actu == ptr)
            data_block_actu = new_node;
    }
    ptr->empty = false;
    return ptr;
}

void init_chain(t_malloc *result, size_t size)
{
    result->pos_mem = size;
    result->empty = false;
    result->prev = data_block_actu;
    result->next = NULL;
    if (data_block_actu) {
        data_block_actu->next = result;
    }
    data_block_actu = result;
}

void *init_adress(size_t size)
{
    t_malloc *result = NULL;
    t_malloc *tmp = data_block;
    size_t value = (SIZE_NODE + size - 1) / page_size * page_size + page_size;

    for (; !result && tmp; tmp = tmp->next) {
        if (tmp->pos_mem >= size && tmp->empty)
            result = alloc_block(tmp, size);
    }
    if (!result) {
        result = sbrk(value);
        if (result == ERROR)
            return NULL;
        init_chain(result, size);
        result->pos_mem = value - SIZE_NODE;
        result = alloc_block(result, size);
    }
    if (data_block == NULL)
        data_block = result;
    return result;
}

void *malloc(size_t size)
{
    t_malloc *ptr = NULL;

    if (page_size == 0) {
        page_size = getpagesize();
    }
    size = paging_malloc(size);
    ptr = init_adress(size);
    return ((char *)ptr + SIZE_NODE);
}