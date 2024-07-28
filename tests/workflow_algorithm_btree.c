/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithm_btree.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:06:50 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 13:33:10 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/bst.h>

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <charon.h>

// Fonction de comparaison pour les entiers
static int compare_int(const void *a, const void *b) {
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;
    return (int_a - int_b);
}

// Fonction de parcours en ordre pour le BST
void inorder_traversal(BSTNode *node, void (*func)(void *)) {
    if (node == NULL) return;
    inorder_traversal(node->left, func);
    func(node->data);
    inorder_traversal(node->right, func);
}

static int index = 0;
static int expected_values[] = {2, 3, 4, 5, 6, 7, 8};

void check_value(void *data) {
    assert(*(int *)data == expected_values[index]);
    index++;
}

// Test de création du BST
void test_bst_create(void) {
    BST *bst = bst_create();
    assert(bst != NULL);
    assert(bst->root == NULL);
    bst_destroy(bst);
}

// Test de l'insertion dans le BST
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

// Test de la recherche dans le BST
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

// Test de suppression des noeuds dans le BST
void test_bst_remove(void) {
    BST *bst = bst_create();
    int values[] = {5, 3, 7, 2, 4, 6, 8};

    for (int i = 0; i < 7; i++) {
        bst_insert(bst, &values[i], compare_int);
    }

    int remove_val = 3;
    bst_remove(bst, &remove_val, compare_int);
    void *found = bst_search(bst, &remove_val, compare_int);
    assert(found == NULL);

    remove_val = 5;
    bst_remove(bst, &remove_val, compare_int);
    found = bst_search(bst, &remove_val, compare_int);
    assert(found == NULL);

    bst_destroy(bst);
}

// Test de parcours en ordre pour le BST
void test_bst_inorder_traversal(void) {
    BST *bst = bst_create();
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    index = 0;

    for (int i = 0; i < 7; i++) {
        bst_insert(bst, &values[i], compare_int);
    }

    inorder_traversal(bst->root, check_value);

    bst_destroy(bst);
}

// Fonction d'aide pour vérifier la hauteur du BST
int bst_height(BSTNode *node) {
    if (node == NULL) return 0;
    int left_height = bst_height(node->left);
    int right_height = bst_height(node->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

// Test de la hauteur du BST
void test_bst_height(void) {
    BST *bst = bst_create();
    int values[] = {5, 3, 7, 2, 4, 6, 8};

    for (int i = 0; i < 7; i++) {
        bst_insert(bst, &values[i], compare_int);
    }

    int height = bst_height(bst->root);
    assert(height == 3);

    bst_destroy(bst);
}

// Test des cas limites du BST
void test_bst_edge_cases(void) {
    BST *bst = bst_create();

    // Insertion de nombreux éléments
    for (int i = 0; i < 1000; i++) {
        int *value = (int *)kmalloc(sizeof(int));
        *value = i;
        bst_insert(bst, value, compare_int);
    }

    assert(bst_height(bst->root) <= 1000);

    // Recherche d'éléments non présents
    int not_present = 1001;
    assert(bst_search(bst, &not_present, compare_int) == NULL);

    // Suppression de tous les éléments
    for (int i = 0; i < 1000; i++) {
        bst_remove(bst, &i, compare_int);
        assert(bst_search(bst, &i, compare_int) == NULL);
    }

    assert(bst->root == NULL);

    bst_destroy(bst);
}

int workflow_hephaistos_a_bst(void) {
    test_bst_create();
    test_bst_insert();
    test_bst_search();
    test_bst_remove();
    test_bst_inorder_traversal();
    test_bst_height();
    // test_bst_edge_cases();
    return (0);
}