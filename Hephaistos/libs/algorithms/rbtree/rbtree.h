/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:51:11 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/15 20:08:22 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_H
#define RBTREE_H

typedef enum { RB_BLACK,
               RB_RED } RBColor;

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

extern RBTree *rb_tree_create(void);
extern void rb_tree_insert(RBTree *tree, void *data);
extern void rb_tree_delete(RBTree *tree, RBNode *node);
extern RBNode *rb_tree_search(RBTree *tree, void *data);
extern void rb_tree_destroy(RBTree *tree);

#endif /* !RBTREE_H */