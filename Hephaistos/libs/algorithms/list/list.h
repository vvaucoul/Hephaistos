/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:39:03 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/12/03 23:40:01 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIST_H
#define _LIST_H

#include <libs/stddef/stddef.h>
#include <libs/stdbool/stdbool.h>

typedef void __list_data_t;

typedef struct __list_node
{
    __list_data_t *data;      // Data
    uint32_t index;           // Index of the node
    struct __list_node *next; // Next node
    struct __list_node *prev; // Previous node
} __list_node_t;

typedef struct s_list
{
    __list_node_t *root; // Root node

    __list_node_t *first; // First node
    __list_node_t *last;  // Last node

    uint32_t size; // Size of the list
} list_t;

extern list_t *list_create(void);
extern void list_destroy(list_t *list);
extern void list_add_back(list_t *list, __list_data_t *data);
extern void list_add_front(list_t *list, __list_data_t *data);

extern void list_remove(list_t *list, __list_data_t *data);
extern void list_remove_index(list_t *list, uint32_t index);
extern void list_clear(list_t *list);

extern void list_insert(list_t *list, __list_data_t *data, uint32_t index);

extern __list_data_t *list_get(list_t *list, uint32_t index);
extern __list_data_t *list_get_front(list_t *list);
extern __list_data_t *list_get_last(list_t *list);

extern uint32_t list_size(list_t *list);
extern bool list_is_empty(list_t *list);

extern void list_iterate(list_t *list, void (*f)(void *));
extern void list_sort(list_t *list, int (*cmp)(const void *, const void *));

#endif /* !_LIST_H */