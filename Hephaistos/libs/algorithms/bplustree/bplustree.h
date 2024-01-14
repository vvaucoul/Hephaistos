/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bplustree.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:23:46 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/14 01:26:13 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include <libs/stddef/stddef.h>

typedef struct s_bplustree_node {
    void *data;
    uint32_t index;
    struct s_bplustree_node *next;
    struct s_bplustree_node *prev;
} t_bplustree_node;

typedef struct s_bplustree {
    t_bplustree_node *root;
    t_bplustree_node *first;
    t_bplustree_node *last;
    uint32_t size;
} t_bplustree;

extern t_bplustree *bplustree_create(void);
extern void bplustree_destroy(t_bplustree *bplustree);
extern void bplustree_add_back(t_bplustree *bplustree, void *data);
extern void bplustree_add_front(t_bplustree *bplustree, void *data);

extern void bplustree_remove(t_bplustree *bplustree, void *data);
extern void bplustree_remove_index(t_bplustree *bplustree, uint32_t index);
extern void bplustree_clear(t_bplustree *bplustree);

extern void bplustree_insert(t_bplustree *bplustree, void *data, uint32_t index);

extern void *bplustree_get(t_bplustree *bplustree, uint32_t index);
extern void *bplustree_get_front(t_bplustree *bplustree);
extern void *bplustree_get_last(t_bplustree *bplustree);

extern uint32_t bplustree_size(t_bplustree *bplustree);
extern int bplustree_is_empty(t_bplustree *bplustree);

extern void bplustree_iterate(t_bplustree *bplustree, void (*f)(void *));
extern void bplustree_sort(t_bplustree *bplustree, int (*cmp)(const void *, const void *));
extern void bplustree_print(t_bplustree *bplustree);

#endif /* BPLUSTREE_H */