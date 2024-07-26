/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:51:11 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/22 11:24:54 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_H
#define RBTREE_H

typedef enum { RB_BLACK, RB_RED } RBColor;

typedef struct RBNode {
    void *data;
    RBColor color;
    struct RBNode *left;
    struct RBNode *right;
    struct RBNode *parent;
} RBNode;

typedef struct RBTree {
    RBNode *root; // root node
} RBTree;

RBTree *rb_tree_create(void);
void rb_tree_insert(RBTree *tree, void *data, int (*cmp)(const void *, const void *));
void rb_tree_delete(RBTree *tree, void *data, int (*cmp)(const void *, const void *));
RBNode *rb_tree_search(RBTree *tree, void *data, int (*cmp)(const void *, const void *));
void rb_tree_destroy(RBTree *tree);

#endif /* !RBTREE_H */