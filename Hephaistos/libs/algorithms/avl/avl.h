/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:02:31 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/22 12:02:32 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_H
#define AVL_H

/**
 * @brief AVL Tree implementation
 *
 * An AVL tree is a self-balancing binary search tree where the heights of the left and right subtrees of any node differ by at most one.
 * This implementation provides functions to insert, delete, and search for elements in the AVL tree.
 */

typedef struct AVLNode {
    int key;               // The key value of the node
    void *data;            // The data associated with the node
    struct AVLNode *left;  // Pointer to the left child node
    struct AVLNode *right; // Pointer to the right child node
    int height;            // The height of the node
} AVLNode;

typedef struct AVL {
    AVLNode *root; // Pointer to the root node of the AVL tree
} AVL;

AVL *avl_create(void);
void avl_destroy(AVL *tree);
void avl_insert(AVL *tree, int key, void *data);
void avl_delete(AVL *tree, int key);
void *avl_search(AVL *tree, int key);

#endif /* AVL_H */