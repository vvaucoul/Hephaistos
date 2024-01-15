/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithm_btree.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:06:50 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/15 16:31:22 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <hephaistos.h>

// Test function for btree_create
void test_btree_create() {
    BTree *btree = btree_create();
    assert_msg(btree != NULL, "BTree should not be NULL");
    btree_destroy(btree);
}

// Test function for btree_create_node
void test_btree_create_node() {
    BTreeNode *node = btree_create_node("test");
    assert_msg(node != NULL, "BTreeNode should not be NULL");
    btree_destroy_node(node);
}

// Test function for btree_insert
void test_btree_insert() {
    BTree *btree = btree_create();
    btree_insert(btree, "key1");
    btree_insert(btree, "key2");
    btree_insert(btree, "key3");
    BTreeNode *node = btree->root;
    assert_msg(node != NULL, "BTree root node should not be NULL");
    assert_msg(strcmp(node->data, "key1") == 0, "BTree root node data should be key1");
    btree_destroy(btree);
}

// Test function for btree_destroy
void test_btree_destroy() {
    BTree *btree = btree_create();
    btree_insert(btree, "key1");
    btree_insert(btree, "key2");
    btree_insert(btree, "key3");
    btree_destroy(btree);
}

// Test function for btree_destroy_node
void test_btree_destroy_node() {
    BTreeNode *node = btree_create_node("test");
    btree_destroy_node(node);
}

// And here is the updated workflow_hephaistos_a_btree function that includes all the test functions:
int workflow_hephaistos_a_btree(void) {
    test_btree_create();
    test_btree_create_node();
    test_btree_insert();
    test_btree_destroy();
    test_btree_destroy_node();
    return (0);
}