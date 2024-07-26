/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:59:48 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/26 22:05:14 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/avl.h>
#include <math.h>
#include <charon.h>

/**
 * @brief Get the height of a node.
 * 
 * @param node The node to get the height of.
 * @return int The height of the node.
 */
static int height(AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

/**
 * @brief Create a new AVL node.
 * 
 * @param key The key of the node.
 * @param data The data of the node.
 * @return AVLNode* A pointer to the new node.
 */
static AVLNode *new_node(int key, void *data) {
    AVLNode *node = (AVLNode *)kmalloc(sizeof(AVLNode));
    if (!node) {
        return NULL; // Memory allocation failed
    }
    node->key = key;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially added at leaf
    return node;
}

/**
 * @brief Perform a right rotation on a node.
 * 
 * @param y The node to rotate.
 * @return AVLNode* The new root of the subtree.
 */
static AVLNode *right_rotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

/**
 * @brief Perform a left rotation on a node.
 * 
 * @param x The node to rotate.
 * @return AVLNode* The new root of the subtree.
 */
static AVLNode *left_rotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

/**
 * @brief Get the balance factor of a node.
 * 
 * @param node The node to get the balance factor of.
 * @return int The balance factor of the node.
 */
static int get_balance(AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

/**
 * @brief Insert a node into the AVL tree.
 * 
 * @param node The root of the subtree.
 * @param key The key of the node to insert.
 * @param data The data of the node to insert.
 * @return AVLNode* The new root of the subtree.
 */
static AVLNode *insert_node(AVLNode *node, int key, void *data) {
    // Perform the normal BST insertion
    if (node == NULL) {
        return new_node(key, data);
    }

    if (key < node->key) {
        node->left = insert_node(node->left, key, data);
    } else if (key > node->key) {
        node->right = insert_node(node->right, key, data);
    } else {
        return node; // Equal keys are not allowed in BST
    }

    // Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor of this ancestor node to check whether
    // this node became unbalanced
    int balance = get_balance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key) {
        return right_rotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key) {
        return left_rotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

/**
 * @brief Delete a node from the AVL tree.
 * 
 * @param root The root of the subtree.
 * @param key The key of the node to delete.
 * @return AVLNode* The new root of the subtree.
 */
static AVLNode *delete_node(AVLNode *root, int key) {
    // Perform standard BST delete
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = delete_node(root->left, key);
    } else if (key > root->key) {
        root->right = delete_node(root->right, key);
    } else {
        // Node with only one child or no child
        if ((root->left == NULL) || (root->right == NULL)) {
            AVLNode *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else { // One child case
                *root = *temp; // Copy the contents of the non-empty child
            }
            kfree(temp);
        } else {
            // Node with two children: Get the inorder successor
            AVLNode *temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }

            // Copy the inorder successor's data to this node
            root->key = temp->key;
            root->data = temp->data;

            // Delete the inorder successor
            root->right = delete_node(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == NULL) {
        return root;
    }

    // Update height of the current node
    root->height = max(height(root->left), height(root->right)) + 1;

    // Get the balance factor of this node to check whether this node became unbalanced
    int balance = get_balance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && get_balance(root->left) >= 0) {
        return right_rotate(root);
    }

    // Left Right Case
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // Right Right Case
    if (balance < -1 && get_balance(root->right) <= 0) {
        return left_rotate(root);
    }

    // Right Left Case
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

/**
 * @brief Search for a node with the given key in the AVL tree.
 * 
 * @param root The root of the subtree.
 * @param key The key to search for.
 * @return void* A pointer to the data of the node if found, NULL otherwise.
 */
static void *search_node(AVLNode *root, int key) {
    if (root == NULL || root->key == key) {
        return root ? root->data : NULL;
    }

    if (key < root->key) {
        return search_node(root->left, key);
    } else {
        return search_node(root->right, key);
    }
}

/**
 * @brief Create a new AVL tree.
 * 
 * @return AVL* A pointer to the new AVL tree.
 */
AVL *avl_create(void) {
    AVL *tree = (AVL *)kmalloc(sizeof(AVL));
    if (!tree) {
        return NULL; // Memory allocation failed
    }
    tree->root = NULL;
    return tree;
}

/**
 * @brief Destroy an AVL tree.
 * 
 * @param tree The AVL tree to destroy.
 */
void avl_destroy(AVL *tree) {
    if (tree) {
        // Add a function to recursively free nodes if needed
        // free_nodes(tree->root);
        kfree(tree);
    }
}

/**
 * @brief Insert a node into the AVL tree.
 * 
 * @param tree The AVL tree.
 * @param key The key of the node to insert.
 * @param data The data of the node to insert.
 */
void avl_insert(AVL *tree, int key, void *data) {
    if (tree) {
        tree->root = insert_node(tree->root, key, data);
    }
}

/**
 * @brief Delete a node from the AVL tree.
 * 
 * @param tree The AVL tree.
 * @param key The key of the node to delete.
 */
void avl_delete(AVL *tree, int key) {
    if (tree) {
        tree->root = delete_node(tree->root, key);
    }
}

/**
 * @brief Search for a node with the given key in the AVL tree.
 * 
 * @param tree The AVL tree.
 * @param key The key to search for.
 * @return void* A pointer to the data of the node if found, NULL otherwise.
 */
void *avl_search(AVL *tree, int key) {
    if (tree) {
        return search_node(tree->root, key);
    }
    return NULL;
}
