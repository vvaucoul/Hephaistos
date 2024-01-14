/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bplustree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:24:47 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/14 01:26:19 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplustree.h"

t_bplustree *bplustree_create(void) {
}

void bplustree_destroy(t_bplustree *bplustree) {
}

void bplustree_add_back(t_bplustree *bplustree, void *data) {
}

void bplustree_add_front(t_bplustree *bplustree, void *data) {
}

void bplustree_remove(t_bplustree *bplustree, void *data) {
}

void bplustree_remove_index(t_bplustree *bplustree, uint32_t index) {
}

void bplustree_clear(t_bplustree *bplustree) {
}

void bplustree_insert(t_bplustree *bplustree, void *data, uint32_t index) {
}

void *bplustree_get(t_bplustree *bplustree, uint32_t index) {
}

void *bplustree_get_front(t_bplustree *bplustree) {
}

void *bplustree_get_last(t_bplustree *bplustree) {
}

uint32_t bplustree_size(t_bplustree *bplustree) {
}

int bplustree_is_empty(t_bplustree *bplustree) {
}

void bplustree_iterate(t_bplustree *bplustree, void (*f)(void *)) {
}

void bplustree_sort(t_bplustree *bplustree, int (*cmp)(const void *, const void *)) {
}

void bplustree_print(t_bplustree *bplustree) {
}
