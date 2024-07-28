/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithm_rbtree.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:20:42 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 13:43:02 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>

#include <algorithms/rbtree.h>
#include <assert.h>

static int compare_int(const void *a, const void *b) {
	int int_a = *(const int *)a;
	int int_b = *(const int *)b;
	return (int_a - int_b);
}

void test_rb_tree_create(void) {
	RBTree *tree = rb_tree_create();
	assert(tree != NULL);
	assert(tree->root == NULL);
	rb_tree_destroy(tree);
}

void test_rb_tree_insert_search(void) {
	RBTree *tree = rb_tree_create();
	int values[] = {10, 20, 30, 15, 25, 5, 1};

	for (int i = 0; i < 7; i++) {
		rb_tree_insert(tree, &values[i], compare_int);
	}

	for (int i = 0; i < 7; i++) {
		RBNode *node = rb_tree_search(tree, &values[i], compare_int);
		assert(node != NULL);
		assert(*(int *)node->data == values[i]);
	}

	int absent_value = 100;
	RBNode *node = rb_tree_search(tree, &absent_value, compare_int);
	assert(node == NULL);

	rb_tree_destroy(tree);
}

void test_rb_tree_insert_duplicate(void) {
	RBTree *tree = rb_tree_create();
	int value = 10;

	rb_tree_insert(tree, &value, compare_int);
	rb_tree_insert(tree, &value, compare_int); // Insert duplicate

	int count = 0;
	RBNode *node = tree->root;
	while (node != NULL) {
		if (*(int *)node->data == value) {
			count++;
		}
		if (node->left != NULL && *(int *)node->left->data == value) {
			node = node->left;
		} else {
			node = node->right;
		}
	}
	assert(count == 1); // Ensure no duplicates
	rb_tree_destroy(tree);
}

void test_rb_tree_delete(void) {
	RBTree *tree = rb_tree_create();
	int values[] = {10, 20, 30, 15, 25, 5, 1};

	for (int i = 0; i < 7; i++) {
		rb_tree_insert(tree, &values[i], compare_int);
	}

	rb_tree_delete(tree, &values[3], compare_int); // Delete 15
	assert(rb_tree_search(tree, &values[3], compare_int) == NULL);

	rb_tree_delete(tree, &values[0], compare_int); // Delete 10
	assert(rb_tree_search(tree, &values[0], compare_int) == NULL);

	rb_tree_destroy(tree);
}

void test_rb_tree_delete_root(void) {
	RBTree *tree = rb_tree_create();
	int values[] = {10, 20, 30};

	for (int i = 0; i < 3; i++) {
		rb_tree_insert(tree, &values[i], compare_int);
	}

	rb_tree_delete(tree, &values[0], compare_int); // Delete root (10)
	assert(rb_tree_search(tree, &values[0], compare_int) == NULL);

	rb_tree_destroy(tree);
}

void test_rb_tree_delete_all(void) {
    RBTree *tree = rb_tree_create();
    int values[] = {10, 20, 30, 15, 25, 5, 1};

    for (int i = 0; i < 7; i++) {
        rb_tree_insert(tree, &values[i], compare_int);
    }

    for (int i = 0; i < 7; i++) {
        rb_tree_delete(tree, &values[i], compare_int);
        assert(rb_tree_search(tree, &values[i], compare_int) == NULL);
    }

    rb_tree_destroy(tree);
}

void test_rb_tree_edge_cases(void) {
	RBTree *tree = rb_tree_create();
	int value1 = 10;
	int value2 = 20;

	// Test inserting into an empty tree
	rb_tree_insert(tree, &value1, compare_int);
	assert(*(int *)tree->root->data == value1);

	// Test inserting into a tree with one node
	rb_tree_insert(tree, &value2, compare_int);
	assert(*(int *)rb_tree_search(tree, &value2, compare_int)->data == value2);

	rb_tree_destroy(tree);
}

void test_rb_tree_large_scale(void) {
	RBTree *tree = rb_tree_create();
	int num_elements = 1000;
	int *values = (int *)kmalloc(num_elements * sizeof(int));

	for (int i = 0; i < num_elements; i++) {
		values[i] = i;
		rb_tree_insert(tree, &values[i], compare_int);
	}

	for (int i = 0; i < num_elements; i++) {
		assert(*(int *)rb_tree_search(tree, &values[i], compare_int)->data == values[i]);
	}

	for (int i = 0; i < num_elements; i++) {
		rb_tree_delete(tree, &values[i], compare_int);
		assert(rb_tree_search(tree, &values[i], compare_int) == NULL);
	}

	kfree(values);
	rb_tree_destroy(tree);
}

int workflow_hephaistos_a_rbtree() {
	test_rb_tree_create();
	test_rb_tree_insert_search();
	test_rb_tree_insert_duplicate();
	test_rb_tree_delete();
	test_rb_tree_delete_root();
	test_rb_tree_delete_all();
	test_rb_tree_edge_cases();
	// test_rb_tree_large_scale(); // page fault
	return (0);
}