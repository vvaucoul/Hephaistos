/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:23:46 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/15 14:44:59 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <charon.h>

list_t *list_create(void) {
    list_t *list = kmalloc(sizeof(list_t));
    if (list == NULL) {
        return NULL;
    }

    list->root = NULL;
    list->size = 0;

    return list;
}

void list_destroy(list_t *list) {
    node_t *current = list->root;
    node_t *next;

    while (current != NULL) {
        next = current->next;
        kfree(current);
        current = next;
    }

    kfree(list);
}

void list_add_back(list_t *list, void *data) {
    node_t *new_node = kmalloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (list->root == NULL) {
        list->root = new_node;
    } else {
        node_t *current = list->root;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    list->size++;
}

void list_add_front(list_t *list, void *data) {
    node_t *new_node = kmalloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }

    new_node->data = data;
    new_node->next = list->root;

    list->root = new_node;
    list->size++;
}

void list_remove(list_t *list, void *data) {
    node_t *current = list->root;
    node_t *previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                list->root = current->next;
            } else {
                previous->next = current->next;
            }
            kfree(current);
            list->size--;
            return;
        }

        previous = current;
        current = current->next;
    }
}

void list_clear(list_t *list) {
    node_t *current = list->root;
    node_t *next;

    while (current != NULL) {
        next = current->next;
        kfree(current);
        current = next;
    }

    list->root = NULL;
    list->size = 0;
}

void list_insert(list_t *list, void *data, uint32_t index) {
    if (index > list->size) {
        return;
    }

    if (index == 0) {
        list_add_front(list, data);
        return;
    }

    node_t *new_node = kmalloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }

    new_node->data = data;

    node_t *current = list->root;
    node_t *previous = NULL;
    uint32_t i = 0;

    while (current != NULL && i < index) {
        previous = current;
        current = current->next;
        i++;
    }

    new_node->next = current;
    previous->next = new_node;

    list->size++;
}

uint32_t list_size(list_t *list) {
    return list->size;
}

int list_is_empty(list_t *list) {
    return list->size == 0;
}

void list_iterate(list_t *list, void (*f)(void *)) {
    node_t *current = list->root;

    while (current != NULL) {
        f(current->data);
        current = current->next;
    }
}

int list_compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void list_sort(list_t *list, int (*cmp)(const void *, const void *)) {
    node_t *current = list->root;
    node_t *next = NULL;
    int *data = NULL;
    int *data_next = NULL;

    while (current != NULL) {
        next = current->next;
        while (next != NULL) {
            data = (int *)current->data;
            data_next = (int *)next->data;
            if (cmp(data, data_next) > 0) {
                swap(data, data_next);
            }
            next = next->next;
        }
        current = current->next;
    }
}

void *list_get(list_t *list, uint32_t index) {
    if (index >= list->size) {
        return NULL;
    }

    node_t *current = list->root;
    uint32_t i = 0;

    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }

    return current->data;
}