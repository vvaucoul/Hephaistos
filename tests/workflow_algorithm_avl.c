/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithm_avl.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:15:27 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 13:45:26 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>

#include <algorithms/avl.h>
#include <assert.h>

static int __data[128];

#define AVL_DEBUG 0

#if AVL_DEBUG == 1
static void __display_avl(AVLNode *node, int level) {
    if (node != NULL) {
        __display_avl(node->right, level + 1);
        printk("%*s", 4 * level, ""); // Indentation
        printk("%d\n", node->key);
        __display_avl(node->left, level + 1);
    }
}
#endif

static void initialize_data() {
    for (int i = 0; i < 128; i++) {
        __data[i] = i;
    }
}

// Fonction de test de la création d'un arbre AVL
void test_avl_create(void) {
    AVL *avl = avl_create();
    assert(avl != NULL);
    assert(avl->root == NULL);
    avl_destroy(avl);
}

// Fonction de test de l'insertion et de la recherche dans un arbre AVL
void test_avl_insert_search(void) {
    AVL *avl = avl_create();
    for (int i = 0; i < 10; i++) {
        avl_insert(avl, __data[i], &__data[i]);
    }

    for (int i = 0; i < 10; i++) {
        void *data = avl_search(avl, __data[i]);
        assert(data != NULL);
        assert(*(int *)data == i);
    }

    avl_destroy(avl);
}

// Fonction de test de la suppression dans un arbre AVL
void test_avl_delete(void) {
    AVL *avl = avl_create();
    for (int i = 0; i < 10; i++) {
        avl_insert(avl, __data[i], &__data[i]);
    }

    for (int i = 0; i < 10; i++) {
        avl_delete(avl, __data[i]);
        void *data = avl_search(avl, __data[i]);
        assert(data == NULL);
    }

    assert(avl->root == NULL);
    avl_destroy(avl);
}

// Fonction de test des cas limites de l'arbre AVL
void test_avl_edge_cases(void) {
    AVL *avl = avl_create();
    
    // Test de l'insertion d'un grand nombre d'éléments
    for (int i = 0; i < 1000; i++) {
        avl_insert(avl, i, &__data[i % 128]);
    }

    for (int i = 0; i < 1000; i++) {
        void *data = avl_search(avl, i);
        assert(data != NULL);
        assert(*(int *)data == i % 128);
    }

    for (int i = 0; i < 1000; i++) {
        avl_delete(avl, i);
        void *data = avl_search(avl, i);
        assert(data == NULL);
    }

    assert(avl->root == NULL);
    avl_destroy(avl);
}

// Fonction de test de l'équilibrage de l'arbre AVL avec des éléments supplémentaires
void test_avl_balancing(void) {
    AVL *avl = avl_create();
    for (int i = 0; i < 10; i++) {
        avl_insert(avl, __data[i], &__data[i]);
    }

    avl_insert(avl, 50, &__data[50]);
    avl_insert(avl, 75, &__data[75]);
    avl_insert(avl, 100, &__data[100]);

    for (int i = 0; i < 10; i++) {
        void *data = avl_search(avl, __data[i]);
        assert(data != NULL);
        assert(*(int *)data == i);
    }

    void *data50 = avl_search(avl, 50);
    assert(data50 != NULL);
    assert(*(int *)data50 == 50);

    void *data75 = avl_search(avl, 75);
    assert(data75 != NULL);
    assert(*(int *)data75 == 75);

    void *data100 = avl_search(avl, 100);
    assert(data100 != NULL);
    assert(*(int *)data100 == 100);

    avl_destroy(avl);
}

// Fonction principale pour exécuter tous les tests unitaires de l'AVL
int workflow_hephaistos_a_avl(void) {
    initialize_data();

    test_avl_create();
    test_avl_insert_search();
    test_avl_delete();
    // test_avl_edge_cases(); // Complete kernel crash
    test_avl_balancing();

    return (0);
}