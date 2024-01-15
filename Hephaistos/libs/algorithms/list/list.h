/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:39:03 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/15 13:24:55 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

#include <libs/stddef/stddef.h>

typedef struct node {
    void *data;
    struct node *next;
} node_t;

typedef struct s_list {
    node_t *root;
    uint32_t size;
} list_t;

extern list_t *list_create(void);
extern void list_destroy(list_t *list);

extern void list_add_back(list_t *list, void *data);
extern void list_add_front(list_t *list, void *data);

extern void list_remove(list_t *list, void *data);
extern void list_clear(list_t *list);

extern void list_insert(list_t *list, void *data, uint32_t index);

extern uint32_t list_size(list_t *list);
extern int list_is_empty(list_t *list);

extern void list_iterate(list_t *list, void (*f)(void *));
extern void list_sort(list_t *list, int (*cmp)(const void *, const void *));

extern void *list_get(list_t *list, uint32_t index);

#endif /* !LIST_H */