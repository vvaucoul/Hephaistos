/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:23:46 by vvaucoul          #+#    #+#             */
/*   Updated: 2023/02/15 17:47:53 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <charon.h>

static void __list_add_back(list_t *list, __list_node_t *node)
{
    if (!list)
        return;
    else
    {
        __list_node_t *tmp = list->root;

        if (!tmp)
        {
            list->root = node;
            list->first = node;
            list->last = node;
            list->size++;
            return;
        }

        while (tmp->next)
            tmp = tmp->next;

        tmp->next = node;
        list->last = node;
        list->size++;
    }
}

static void __list_add_front(list_t *list, __list_node_t *node)
{
    if (!list)
        return;
    else
    {
        if (!list->root)
        {
            list->root = node;
            list->first = node;
            list->last = node;
            list->size++;
            return;
        }
        else
        {
            node->next = list->root;
            list->root = node;
            list->first = node;
            list->size++;
        }
    }
}

static void __list_insert(list_t *list, __list_node_t *node, uint32_t index)
{
    __list_node_t *tmp = list->root;

    if (!list->root)
    {
        list->root = node;
        list->first = node;
        list->last = node;
        list->size = 1;
        return;
    }
    else if (index == 0)
    {
        __list_add_front(list, node);
        return;
    }
    else if (index == list->size)
    {
        __list_add_back(list, node);
        return;
    }
    else
    {
        uint32_t i = 0;
        while (tmp)
        {
            if (i == index)
            {
                node->next = tmp->next;
                tmp->next = node;
                list->size++;
                return;
            }
            tmp = tmp->next;
            i++;
        }
    }
}

static void __list_remove_index(list_t *list, uint32_t index)
{
    __list_node_t *node = list->root;
    uint32_t i = 0;

    if (list)
        return;
    while (node)
    {
        if (i == index)
        {
            if (node->prev)
                node->prev->next = node->next;
            if (node->next)
                node->next->prev = node->prev;
            if (node == list->first)
                list->first = node->next;
            if (node == list->last)
                list->last = node->prev;
            kfree(node);
            return;
        }
        node = node->next;
        ++i;
    }
}

static void __list_remove(list_t *list, __list_data_t *data)
{
    if (list)
        return;
    __list_node_t *node = list->root;
    while (node)
    {
        if (node->data == data)
        {
            return;
        }
        node = node->next;
    }
}

static __list_node_t *__list_create_node(__list_data_t *data)
{
    __list_node_t *node = kmalloc(sizeof(__list_node_t));

    if (!node)
        return (NULL);
    else
    {
        node->data = data;
        node->next = NULL;
        node->index = 0;
        node->prev = NULL;
    }
    return (node);
}

static void __list_iterate(list_t *list, void (*f)(void *))
{
    __list_node_t *node = list->root;

    while (node)
    {
        f(node->data);
        node = node->next;
    }
}

static void __list_destroy(list_t *list)
{
    __list_node_t *node = list->root;
    __list_node_t *tmp = NULL;

    while (node)
    {
        tmp = node;
        node = node->next;
        kfree(tmp);
    }
    kfree(list);
    list = NULL;
}

static list_t *__list_create(void)
{
    list_t *list = kmalloc(sizeof(list_t));

    if (!list)
        return (NULL);
    else
    {
        list->root = NULL;
        list->size = 0;
    }
    return (list);
}

/*******************************************************************************
 *                             INTERFACE FUNCTIONS                             *
 ******************************************************************************/

list_t *list_create(void)
{
    return (__list_create());
}

void list_destroy(list_t *list)
{
    __list_destroy(list);
}

void list_add_back(list_t *list, __list_data_t *data)
{
    __list_node_t *node = __list_create_node(data);

    if (!node)
        return;
    __list_add_back(list, node);
    list->size++;
}

void list_add_front(list_t *list, __list_data_t *data)
{
    __list_node_t *node = __list_create_node(data);

    if (!node)
        return;
    __list_add_front(list, node);
    list->size++;
}

void list_remove(list_t *list, __list_data_t *data)
{
    __list_remove(list, data);
}

void list_remove_index(list_t *list, uint32_t index)
{
    __list_remove_index(list, index);
}

void list_clear(list_t *list)
{
    __list_node_t *node = list->root;
    __list_node_t *tmp = NULL;

    while (node)
    {
        tmp = node;
        node = node->next;
        kfree(tmp);
    }
    list->root = NULL;
    list->size = 0;
}

void list_insert(list_t *list, __list_data_t *data, uint32_t index)
{
    __list_node_t *node = __list_create_node(data);

    if (!node)
        return;
    __list_insert(list, node, index);
}

__list_data_t *list_get(list_t *list, uint32_t index)
{
    __list_node_t *node = list->root;

    uint32_t i = 0;
    while (node)
    {
        if (i == index)
            return (node->data);
        node = node->next;
        i++;
    }
    return (NULL);
}

__list_data_t *list_get_front(list_t *list)
{
    return (list->first->data);
}

__list_data_t *list_get_last(list_t *list)
{
    return (list->last->data);
}

uint32_t list_size(list_t *list)
{
    return (list->size);
}

bool list_is_empty(list_t *list)
{
    return (list->size == 0);
}

void list_iterate(list_t *list, void (*f)(void *))
{
    __list_iterate(list, f);
}

void list_sort(list_t *list, int (*cmp)(const void *, const void *))
{
    if (!list)
        return;
    __list_node_t *node = list->root;

    while (node)
    {
        __list_node_t *tmp = node->next;
        while (tmp)
        {
            if (cmp(node->data, tmp->data) > 0)
            {
                __list_data_t *data = node->data;
                node->data = tmp->data;
                tmp->data = data;
            }
            tmp = tmp->next;
        }
        node = node->next;
    }
}
