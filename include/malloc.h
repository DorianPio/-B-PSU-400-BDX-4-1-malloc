/*
** EPITECH PROJECT, 2021
** bootstrap
** File description:
** malloc
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#ifndef MALLOC_H_
#define MALLOC_H_



struct s_malloc {
    size_t pos_mem;
    bool empty;
    struct s_malloc *next;
    struct s_malloc *prev;
};

typedef struct s_malloc t_malloc;


#define ERROR (void *)-1
#define SIZE_ARRAY sizeof(size_t)
#define SIZE_NODE sizeof(t_malloc)
size_t paging_malloc(size_t size);
#define CAST(ptr, size) (t_malloc *)((char *)ptr + SIZE_NODE + size)
#define MINUS_CAST(ptr) (t_malloc*)((char *)ptr - SIZE_NODE)


#endif /* !MALLOC_H_ */

#ifndef GLOBAL_H_
#define GLOBAL_H_

extern size_t page_size;
extern t_malloc *data_block;
extern t_malloc *data_block_actu;

#endif /* !GLOBAL_H_ */
