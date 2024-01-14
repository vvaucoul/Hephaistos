/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:40:45 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/14 01:23:27 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
#define BTREE_H

#include <libs/stddef/stddef.h>

typedef struct s_btree_node {
    void *data;
    struct s_btree_node *left;
    struct s_btree_node *right;
} BTreeNode;

typedef struct s_btree {
    BTreeNode *root;
} BTree;

extern BTree *btree_create(void);
extern BTreeNode *btree_create_node(void *data);

extern void btree_insert(BTree *btree, void *data);

extern void btree_destroy(BTree *btree);
extern void btree_destroy_node(BTreeNode *node);

#endif /* !BTREE_H */