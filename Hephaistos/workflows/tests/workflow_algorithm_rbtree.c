/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithm_rbtree.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:20:42 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/15 20:29:55 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <hephaistos.h>

void test_create_tree() {
    RBTree *tree = rb_tree_create();
    rb_tree_destroy(tree);
}

void test_insert_node() {
    RBTree *tree = rb_tree_create();

    int data1 = 10;
    int data2 = 20;

    rb_tree_insert(tree, &data1);
    rb_tree_insert(tree, &data2);

    assert_msg(tree->root->data == &data1, "Tree root data should be data1");
    assert_msg(tree->root->left->data == &data2, "Tree root left data should be data2");
}

void test_search_node() {
    RBTree *tree = rb_tree_create();

    int data1 = 10;
    int data2 = 20;

    rb_tree_insert(tree, &data1);
    rb_tree_insert(tree, &data2);

    RBNode *node1 = rb_tree_search(tree, &data1);
    RBNode *node2 = rb_tree_search(tree, &data2);

    assert_msg(node1 != NULL, "Node1 should not be NULL");
    assert_msg(node2 != NULL, "Node2 should not be NULL");
    assert_msg(node1->data == &data1, "Node1 data should be data1");
    assert_msg(node2->data == &data2, "Node2 data should be data2");
}

void test_delete_node() {
    RBTree *tree = rb_tree_create();

    int data1 = 10;
    int data2 = 20;

    rb_tree_insert(tree, &data1);
    rb_tree_insert(tree, &data2);
    assert_msg(tree->root->data == &data1, "Tree root data should be data1");
    rb_tree_destroy(tree);
}

void test_destroy_tree() {
    RBTree *tree = rb_tree_create();

    int data1 = 10;
    int data2 = 20;

    rb_tree_insert(tree, &data1);
    rb_tree_insert(tree, &data2);
    assert_msg(tree->root->data == &data1, "Tree root data should be data1");
    assert_msg(tree->root->left->data == &data2, "Tree root left data should be data2");
    rb_tree_destroy(tree);
}

int workflow_hephaistos_a_rbtree() {
    test_create_tree();
    test_insert_node();
    test_search_node();
    test_delete_node();
    test_destroy_tree();
    return (0);
}