/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:07:04 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 13:30:27 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/bst.h>
#include <charon.h>

/**
 * Creates a new Binary Search Tree (BST) and returns a pointer to it.
 *
 * @return A pointer to the newly created BST.
 */
BST *bst_create(void) {
    BST *bst = (BST *)kmalloc(sizeof(BST));
    if (bst == NULL) {
        return NULL;
    }
    bst->root = NULL;
    return bst;
}

/**
 * Creates a new node for a binary search tree (BST) with the given data.
 *
 * @param data The data to be stored in the new node.
 * @return A pointer to the newly created BSTNode.
 */
BSTNode *bst_create_node(void *data) {
    BSTNode *node = (BSTNode *)kmalloc(sizeof(BSTNode));
    if (node == NULL) {
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * Inserts a new node with the specified data into the binary search tree (BST).
 *
 * @param bst The binary search tree to insert the node into.
 * @param data The data to be stored in the new node.
 * @param cmp The comparison function used to determine the order of the nodes in the BST.
 *            This function should return a negative value if the first argument is less than the second,
 *            a positive value if the first argument is greater than the second, and 0 if they are equal.
 */
void bst_insert(BST *bst, void *data, int (*cmp)(const void *, const void *)) {
    BSTNode *node = bst_create_node(data);
    if (node == NULL) {
        return;
    }

    if (bst->root == NULL) {
        bst->root = node;
    } else {
        BSTNode *current = bst->root;
        BSTNode *parent = NULL;

        while (current != NULL) {
            parent = current;
            if (cmp(data, current->data) < 0) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (cmp(data, parent->data) < 0) {
            parent->left = node;
        } else {
            parent->right = node;
        }
    }
}

/**
 * Removes a node with the specified data from the binary search tree.
 *
 * @param bst The binary search tree.
 * @param data The data to be removed.
 * @param cmp The comparison function used to compare data.
 */
void bst_remove(BST *bst, void *data, int (*cmp)(const void *, const void *)) {
    BSTNode *current = bst->root;
    BSTNode *parent = NULL;

    while (current != NULL) {
        int comparison = cmp(data, current->data);
        if (comparison == 0) {
            break;
        } else {
            parent = current;
            if (comparison < 0) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
    }

    if (current == NULL) {
        return;
    }

    if (current->left == NULL && current->right == NULL) {
        if (parent == NULL) {
            bst->root = NULL;
        } else if (parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        kfree(current);
    } else if (current->left == NULL) {
        if (parent == NULL) {
            bst->root = current->right;
        } else if (parent->left == current) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        kfree(current);
    } else if (current->right == NULL) {
        if (parent == NULL) {
            bst->root = current->left;
        } else if (parent->left == current) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        kfree(current);
    } else {
        BSTNode *successor = current->right;
        parent = NULL;
        while (successor->left != NULL) {
            parent = successor;
            successor = successor->left;
        }
        current->data = successor->data;
        if (parent == NULL) {
            current->right = successor->right;
        } else {
            parent->left = successor->right;
        }
        kfree(successor);
    }
}

/**
 * @brief Destroys a node in a binary search tree.
 *
 * This function frees the memory allocated for a node in a binary search tree.
 *
 * @param node The node to be destroyed.
 */
void bst_destroy_node(BSTNode *node) {
    if (node == NULL) {
        return;
    }
    bst_destroy_node(node->left);
    bst_destroy_node(node->right);
    kfree(node);
}

/**
 * @brief Destroys a binary search tree (BST) and frees the memory allocated for it.
 *
 * This function deallocates all the nodes in the BST and frees the memory used by them.
 * After calling this function, the BST will no longer be valid and should not be used.
 *
 * @param bst A pointer to the BST structure to be destroyed.
 */
void bst_destroy(BST *bst) {
    if (bst == NULL) {
        return;
    }
    bst_destroy_node(bst->root);
    kfree(bst);
}

/**
 * Searches for a specific element in a binary search tree.
 *
 * @param bst The binary search tree to search in.
 * @param data The element to search for.
 * @param cmp The comparison function used to compare elements in the tree.
 *            It should return a negative value if the first element is less than the second,
 *            a positive value if the first element is greater than the second,
 *            and zero if the elements are equal.
 * @return A pointer to the found element, or NULL if the element is not found.
 */
void *bst_search(BST *bst, void *data, int (*cmp)(const void *, const void *)) {
    BSTNode *current = bst->root;
    while (current != NULL) {
        int comparison = cmp(data, current->data);
        if (comparison == 0) {
            return current->data;
        } else if (comparison < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}