/*
** EPITECH PROJECT, 2021
** undefined
** File description:
** free
*/

#include "include/malloc.h"

void prev_node_is_marging(t_malloc *block)
{
    t_malloc *tmp = NULL;

    if (block->prev && block->prev->empty) {
        tmp = block->prev;
        tmp->next = block->next;
        tmp->pos_mem += block->pos_mem + SIZE_NODE;
        if (block->next != NULL) {
            block->next->prev = tmp;
        }
        if (data_block_actu == block)
            data_block_actu = tmp;
    }
}

void next_node_is_marging(t_malloc *block)
{
    t_malloc *tmp = NULL;

    if (block->next && block->next->empty) {
        tmp = block->next;
        block->next = tmp->next;
        block->pos_mem += tmp->pos_mem + SIZE_NODE;
        if (block->next) {
            block->next->prev = block;
        }
        if (data_block_actu == tmp)
            data_block_actu = block;
    }
}

void free(void *ptr)
{
    t_malloc *node_merge = NULL;
    t_malloc *tmp = NULL;

    if (!ptr || !data_block)
        return;
    node_merge = MINUS_CAST(ptr);
    if (node_merge->empty)
        return;
    node_merge->empty = true;
    next_node_is_marging(node_merge);
    prev_node_is_marging(node_merge);
    if (data_block_actu->empty) {
        if (data_block_actu == data_block)
            data_block = NULL;
        tmp = data_block_actu;
        data_block_actu = data_block_actu->prev;
        if (data_block_actu)
            data_block_actu->next = NULL;
        sbrk(-(tmp->pos_mem + SIZE_NODE));
    }
}