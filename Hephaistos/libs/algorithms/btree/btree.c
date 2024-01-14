/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:07:04 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/14 01:21:28 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <charon.h>

/**
 * @brief Create a new BTree object
 *
 * @return BTree*
 */
BTree *btree_create(void) {
    BTree *btree = kmalloc(sizeof(BTree));

    if (btree == NULL) {
        return (NULL);
    }
    btree->root = NULL;
    return (btree);
}

/**
 * @brief Create a new BTreeNode object
 *
 * @param data
 * @return BTreeNode*
 */
BTreeNode *btree_create_node(void *data) {
    BTreeNode *node = kmalloc(sizeof(BTreeNode));

    if (node == NULL) {
        return NULL;
    }

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

/**
 * @brief Destroy a BTree object
 *
 * @param btree
 */
void btree_destroy(BTree *btree) {
      if (btree != NULL && btree->root != NULL) {
        btree_destroy_node(btree->root->left);
        btree_destroy_node(btree->root->right);
        kfree(btree->root);
        kfree(btree);
    }
}

/**
 * @brief Destroy a BTreeNode object
 *
 * @param node
 */
void btree_destroy_node(BTreeNode *node) {
    if (node != NULL) {
        btree_destroy_node(node->left);
        btree_destroy_node(node->right);
        kfree(node);
    }
}

/**
 * @brief Insert a new key in the BTree
 *
 * @param btree
 * @param key
 * @param data
 */
void btree_insert(BTree *btree, void *data) {
    BTreeNode *node = btree_create_node(data);
    BTreeNode *current;
    BTreeNode *parent;


    if (btree->root == NULL) {
        btree->root = node;
    } else {
        current = btree->root;

        while (1) {
            parent = current;

            if (data < parent->data) {
                current = current->left;

                if (current == NULL) {
                    parent->left = node;
                    return;
                }
            } else {
                current = current->right;

                if (current == NULL) {
                    parent->right = node;
                    return;
                }
            }
        }
    }
}