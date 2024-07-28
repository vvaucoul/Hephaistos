/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:39:03 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 11:10:34 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

#include <stdint.h>

typedef struct node {
	void *data;
	struct node *next;
} node_t;

typedef struct s_list {
	node_t *root; // Pointer to the first node
	node_t *tail; // Pointer to the last node

	uint32_t size;		// Number of elements in the list
	uint32_t capacity;	// Allocated capacity (optional)
	uint32_t ref_count; // Reference counter (optional)
	void *context;		// Context/metadata pointer (optional)
} list_t;

list_t *list_create(void);
void list_destroy(list_t *list);

void list_add_back(list_t *list, void *data);
void list_add_front(list_t *list, void *data);

void list_remove(list_t *list, void *data);
void list_clear(list_t *list);

void list_insert(list_t *list, void *data, uint32_t index);

uint32_t list_size(const list_t *list);
int list_is_empty(const list_t *list);

void list_iterate(const list_t *list, void (*f)(void *));
void list_sort(list_t *list, int (*cmp)(const void *, const void *));

void *list_get(const list_t *list, uint32_t index);

#endif /* !LIST_H */