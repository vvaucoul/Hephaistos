/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:39:03 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/22 01:44:30 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIST_H
#define _LIST_H

#include <libs/stddef/stddef.h>

typedef void __list_data_t;

typedef struct __list_node
{
    __list_data_t **data;     // Data
    uint32_t index;           // Index of the node
    struct __list_node *next; // Next node
} __list_node_t;

typedef struct s_list
{
    __list_node_t *root;   // Root node

    __list_node_t *first;  // First node
    __list_node_t *middle; // Middle node
    __list_node_t *last;   // Last node

    uint32_t size;         // Size of the list
} list_t;

extern list_t *list_create(void);
extern void list_add(list_t *list, __list_data_t *data);
// extern void list_remove(list_t *list, list_t *node);
extern void list_remove_index(list_t *list, uint32_t index);