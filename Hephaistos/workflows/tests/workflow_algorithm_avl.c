/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithm_avl.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:15:27 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/22 12:22:51 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <hephaistos.h>

static int __data[128];

static void __display_avl(AVLNode *node, int level) {
    if (node != NULL) {
        __display_avl(node->right, level + 1);
        printk("%*s", 4 * level, ""); // Indentation
        printk("%d\n", node->key);
        __display_avl(node->left, level + 1);
    }
}

static void initialize_data() {
    for (int i = 0; i < 128; i++) {
        __data[i] = i;
    }
}

int workflow_hephaistos_a_avl(void) {

    initialize_data();

    AVL *avl = avl_create();
    assert_msg(avl != NULL, "AVL tree creation failed");

    // Test AVL insertion
    for (int i = 0; i < 10; i++) {
        avl_insert(avl, __data[i], &__data[i]);
    }

    assert_msg(avl->root != NULL, "AVL tree root is NULL after insertions");
    for (int i = 0; i < 10; i++) {
        void *data = avl_search(avl, __data[i]);
        assert_msg(data != NULL, "AVL tree search failed");
        assert_msg(*(int *)data == i, "AVL tree search returned incorrect data");
    }

    // Display the AVL tree
    // __display_avl(avl->root, 0);

    // Test AVL deletion
    for (int i = 0; i < 10; i++) {
        avl_delete(avl, __data[i]);
        void *data = avl_search(avl, __data[i]);
        assert_msg(data == NULL, "AVL tree delete failed");
    }

    // Ensure AVL tree is empty
    assert_msg(avl->root == NULL, "AVL tree root is not NULL after deletions");

    // Re-insert data to test balancing
    for (int i = 0; i < 10; i++) {
        avl_insert(avl, __data[i], &__data[i]);
    }

    // Display the AVL tree
    // __display_avl(avl->root, 0);

    // Test AVL search
    for (int i = 0; i < 10; i++) {
        void *data = avl_search(avl, __data[i]);
        assert_msg(data != NULL, "AVL tree search failed");
        assert_msg(*(int *)data == i, "AVL tree search returned incorrect data");
    }

    // Test AVL tree balancing with additional elements within bounds
    avl_insert(avl, 50, &__data[50]);
    avl_insert(avl, 75, &__data[75]);
    avl_insert(avl, 100, &__data[100]);

    // __display_avl(avl->root, 0);

    // Clean up
    avl_destroy(avl);

    return (0);
}
