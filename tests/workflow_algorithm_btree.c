/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithm_btree.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:06:50 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 10:56:01 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/bst.h>

#include <assert.h>
#include <stddef.h>

static int compare_int(const void *a, const void *b) {
	int int_a = *(const int *)a;
	int int_b = *(const int *)b;
	return (int_a - int_b);
}

void test_bst_create(void) {
	BST *bst = bst_create();
	assert(bst != NULL);
	assert(bst->root == NULL);
	bst_destroy(bst);
}

void test_bst_insert(void) {
	BST *bst = bst_create();
	int values[] = {5, 3, 7, 2, 4, 6, 8};

	for (int i = 0; i < 7; i++) {
		bst_insert(bst, &values[i], compare_int);
	}

	assert(*(int *)bst->root->data == 5);
	assert(*(int *)bst->root->left->data == 3);
	assert(*(int *)bst->root->right->data == 7);
	assert(*(int *)bst->root->left->left->data == 2);
	assert(*(int *)bst->root->left->right->data == 4);
	assert(*(int *)bst->root->right->left->data == 6);
	assert(*(int *)bst->root->right->right->data == 8);

	bst_destroy(bst);
}

void test_bst_search(void) {
	BST *bst = bst_create();
	int values[] = {5, 3, 7, 2, 4, 6, 8};

	for (int i = 0; i < 7; i++) {
		bst_insert(bst, &values[i], compare_int);
	}

	int search_val = 6;
	void *found = bst_search(bst, &search_val, compare_int);
	assert(found != NULL);
	assert(*(int *)found == 6);

	search_val = 10;
	found = bst_search(bst, &search_val, compare_int);
	assert(found == NULL);

	bst_destroy(bst);
}

int workflow_hephaistos_a_bst(void) {

	test_bst_create();
	test_bst_insert();
	test_bst_search();
	return (0);
}