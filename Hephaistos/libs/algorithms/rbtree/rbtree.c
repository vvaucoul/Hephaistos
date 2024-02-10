/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:51:25 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/15 20:11:27 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.h"
#include <charon.h>

static void rb_insert_fixup(RBTree *tree, RBNode *node, RBNode *uncle);
static void rotate_left(RBTree *tree, RBNode *node);
static void rotate_right(RBTree *tree, RBNode *node);

RBTree *rb_tree_create(void) {
    RBTree *tree = (RBTree *)kmalloc(sizeof(RBTree));
    if (tree) {
        tree->root = NULL;
    }
    return tree;
}

static RBNode *new_rb_node(void *data, RBColor color, RBNode *parent) {
    RBNode *node = (RBNode *)kmalloc(sizeof(RBNode));
    if (node) {
        node->data = data;
        node->color = color;
        node->left = NULL;
        node->right = NULL;
        node->parent = parent;
    }
    return node;
}

void rb_tree_insert(RBTree *tree, void *data) {
    if (tree->root == NULL) {
        tree->root = new_rb_node(data, RB_BLACK, NULL);
    } else {
        RBNode *node = tree->root;
        RBNode *parent;
        while (1) {
            if (node->data == data) {
                return; // data already exists
            }

            parent = node;

            bool go_left = node->data > data;
            node = go_left ? node->left : node->right;

            if (node == NULL) {
                if (go_left) {
                    parent->left = new_rb_node(data, RB_RED, parent);
                } else {
                    parent->right = new_rb_node(data, RB_RED, parent);
                }

                rb_insert_fixup(tree, parent->left, parent->right);
                break;
            }
        }
    }
}

static void rb_insert_fixup(RBTree *tree, RBNode *node, RBNode *uncle) {
    while (node->parent && node->parent->color == RB_RED) {
        RBNode *grandparent = node->parent->parent;
        RBNode *uncle = (node->parent == grandparent->left)
                            ? grandparent->right
                            : grandparent->left;

        if (uncle && uncle->color == RB_RED) {
            node->parent->color = RB_BLACK;
            uncle->color = RB_BLACK;
            grandparent->color = RB_RED;
            node = grandparent;
        } else {
            if (node == node->parent->right && node->parent == grandparent->left) {
                rotate_left(tree, node->parent);
                node = node->left;
            } else if (node == node->parent->left && node->parent == grandparent->right) {
                rotate_right(tree, node->parent);
                node = node->right;
            }

            node->parent->color = RB_BLACK;
            grandparent->color = RB_RED;

            if (node == node->parent->left) {
                rotate_right(tree, grandparent);
            } else {
                rotate_left(tree, grandparent);
            }
        }
    }

    tree->root->color = RB_BLACK;
}

static void rotate_left(RBTree *tree, RBNode *node) {
    RBNode *right = node->right;
    if (right) {
        node->right = right->left;

        if (right->left) {
            right->left->parent = node;
        }

        right->parent = node->parent;

        if (node->parent) {
            if (node == node->parent->left) {
                node->parent->left = right;
            } else {
                node->parent->right = right;
            }
        } else {
            tree->root = right;
        }

        right->left = node;
        node->parent = right;
    }
}

static void rotate_right(RBTree *tree, RBNode *node) {
    RBNode *left = node->left;
    if (left) {
        node->left = left->right;

        if (left->right) {
            left->right->parent = node;
        }

        left->parent = node->parent;

        if (node->parent) {
            if (node == node->parent->left) {
                node->parent->left = left;
            } else {
                node->parent->right = left;
            }
        } else {
            tree->root = left;
        }

        left->right = node;
        node->parent = left;
    }
}

RBNode *rb_tree_search(RBTree *tree, void *data) {
    RBNode *node = tree->root;
    while (node) {
        if (node->data == data) {
            return node;
        }

        node = (node->data > data) ? node->left : node->right;
    }

    return NULL;
}

static void rb_tree_free_nodes(RBNode *node) {
    if (node) {
        rb_tree_free_nodes(node->left);
        rb_tree_free_nodes(node->right);
        kfree(node);
    }
}

void rb_tree_destroy(RBTree *tree) {
    rb_tree_free_nodes(tree->root);
    kfree(tree);
}