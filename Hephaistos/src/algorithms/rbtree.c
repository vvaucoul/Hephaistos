/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:51:25 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/26 22:04:51 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/rbtree.h>
#include <charon.h>

/**
 * Creates a new Red-Black Tree node with the given data.
 *
 * @param data The data to be stored in the node.
 * @return A pointer to the newly created node.
 */
static RBNode *rb_create_node(void *data) {
    RBNode *node = (RBNode *)kmalloc(sizeof(RBNode));
    if (!node)
        return NULL;

    node->data = data;
    node->color = RB_RED;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return node;
}

/**
 * Creates a new Red-Black Tree (RBTree) and returns a pointer to it.
 *
 * @return A pointer to the newly created RBTree.
 */
RBTree *rb_tree_create(void) {
    RBTree *tree = (RBTree *)kmalloc(sizeof(RBTree));
    if (!tree)
        return NULL;

    tree->root = NULL;
    return tree;
}

/**
 * Rotates the given node and its right child to the left in the red-black tree.
 *
 * @param tree The red-black tree.
 * @param x The node to rotate.
 */
static void rb_rotate_left(RBTree *tree, RBNode *x) {
    RBNode *y = x->right;
    x->right = y->left;
    if (y->left)
        y->left->parent = x;
    y->parent = x->parent;
    if (!x->parent) {
        tree->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

/**
 * Rotates the given node and its left child to the right in the red-black tree.
 *
 * @param tree The red-black tree.
 * @param x The node to rotate.
 */
static void rb_rotate_right(RBTree *tree, RBNode *x) {
    RBNode *y = x->left;
    x->left = y->right;
    if (y->right)
        y->right->parent = x;
    y->parent = x->parent;
    if (!x->parent) {
        tree->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

/**
 * Performs the fixup process after inserting a node into a red-black tree.
 *
 * @param tree The red-black tree.
 * @param z The newly inserted node.
 */
static void rb_insert_fixup(RBTree *tree, RBNode *z) {
    while (z->parent && z->parent->color == RB_RED) {
        if (z->parent == z->parent->parent->left) {
            RBNode *y = z->parent->parent->right;
            if (y && y->color == RB_RED) {
                z->parent->color = RB_BLACK;
                y->color = RB_BLACK;
                z->parent->parent->color = RB_RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rb_rotate_left(tree, z);
                }
                z->parent->color = RB_BLACK;
                z->parent->parent->color = RB_RED;
                rb_rotate_right(tree, z->parent->parent);
            }
        } else {
            RBNode *y = z->parent->parent->left;
            if (y && y->color == RB_RED) {
                z->parent->color = RB_BLACK;
                y->color = RB_BLACK;
                z->parent->parent->color = RB_RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rb_rotate_right(tree, z);
                }
                z->parent->color = RB_BLACK;
                z->parent->parent->color = RB_RED;
                rb_rotate_left(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = RB_BLACK;
}

/**
 * Inserts a new node with the specified data into the red-black tree.
 *
 * @param tree The red-black tree to insert the node into.
 * @param data The data to be stored in the new node.
 * @param cmp  The comparison function used to determine the order of the nodes.
 *             It should return a negative value if the first argument is less than the second,
 *             a positive value if the first argument is greater than the second,
 *             and zero if the arguments are equal.
 */
void rb_tree_insert(RBTree *tree, void *data, int (*cmp)(const void *, const void *)) {
    RBNode *z = rb_create_node(data);
    if (!z)
        return;

    RBNode *y = NULL;
    RBNode *x = tree->root;

    while (x != NULL) {
        y = x;
        if (cmp(z->data, x->data) < 0) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == NULL) {
        tree->root = z;
    } else if (cmp(z->data, y->data) < 0) {
        y->left = z;
    } else {
        y->right = z;
    }

    rb_insert_fixup(tree, z);
}

/**
 * Finds the minimum node in a red-black tree.
 *
 * This function traverses the left child pointers of the given node until it reaches the leftmost node,
 * which is the minimum node in the tree.
 *
 * @param node The root node of the tree or subtree.
 * @return The minimum node in the tree.
 */
static RBNode *rb_minimum(RBNode *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

/**
 * Transplants the subtree rooted at node `u` with the subtree rooted at node `v` in the given red-black tree.
 *
 * @param tree The red-black tree.
 * @param u The node to be replaced.
 * @param v The node to replace `u`.
 */
static void rb_transplant(RBTree *tree, RBNode *u, RBNode *v) {
    if (u->parent == NULL) {
        tree->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != NULL) {
        v->parent = u->parent;
    }
}

/**
 * Performs the fixup process after deleting a node from a red-black tree.
 *
 * @param tree The red-black tree.
 * @param x The node to fix up.
 */
static void rb_delete_fixup(RBTree *tree, RBNode *x) {
    while (x != tree->root && x->color == RB_BLACK) {
        if (x == x->parent->left) {
            RBNode *w = x->parent->right;
            if (w->color == RB_RED) {
                w->color = RB_BLACK;
                x->parent->color = RB_RED;
                rb_rotate_left(tree, x->parent);
                w = x->parent->right;
            }
            if ((w->left == NULL || w->left->color == RB_BLACK) &&
                (w->right == NULL || w->right->color == RB_BLACK)) {
                w->color = RB_RED;
                x = x->parent;
            } else {
                if (w->right == NULL || w->right->color == RB_BLACK) {
                    if (w->left != NULL) {
                        w->left->color = RB_BLACK;
                    }
                    w->color = RB_RED;
                    rb_rotate_right(tree, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = RB_BLACK;
                if (w->right != NULL) {
                    w->right->color = RB_BLACK;
                }
                rb_rotate_left(tree, x->parent);
                x = tree->root;
            }
        } else {
            RBNode *w = x->parent->left;
            if (w->color == RB_RED) {
                w->color = RB_BLACK;
                x->parent->color = RB_RED;
                rb_rotate_right(tree, x->parent);
                w = x->parent->left;
            }
            if ((w->right == NULL || w->right->color == RB_BLACK) &&
                (w->left == NULL || w->left->color == RB_BLACK)) {
                w->color = RB_RED;
                x = x->parent;
            } else {
                if (w->left == NULL || w->left->color == RB_BLACK) {
                    if (w->right != NULL) {
                        w->right->color = RB_BLACK;
                    }
                    w->color = RB_RED;
                    rb_rotate_left(tree, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = RB_BLACK;
                if (w->left != NULL) {
                    w->left->color = RB_BLACK;
                }
                rb_rotate_right(tree, x->parent);
                x = tree->root;
            }
        }
    }
    if (x != NULL) {
        x->color = RB_BLACK;
    }
}

/**
 * Deletes a node with the specified data from the red-black tree.
 *
 * @param tree The red-black tree.
 * @param data The data to be deleted.
 * @param cmp  The comparison function used to compare the data.
 */
void rb_tree_delete(RBTree *tree, void *data, int (*cmp)(const void *, const void *)) {
    RBNode *z = rb_tree_search(tree, data, cmp);
    if (!z)
        return;

    RBNode *y = z;
    RBNode *x;
    RBColor y_original_color = y->color;

    if (z->left == NULL) {
        x = z->right;
        rb_transplant(tree, z, z->right);
    } else if (z->right == NULL) {
        x = z->left;
        rb_transplant(tree, z, z->left);
    } else {
        y = rb_minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            if (x != NULL) {
                x->parent = y;
            }
        } else {
            rb_transplant(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        rb_transplant(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    kfree(z);

    if (y_original_color == RB_BLACK) {
        rb_delete_fixup(tree, x);
    }
}

/**
 * Searches for a node containing the specified data in the given red-black tree.
 *
 * @param tree The red-black tree to search in.
 * @param data The data to search for.
 * @param cmp  The comparison function used to compare the data.
 * @return     A pointer to the node containing the data, or NULL if not found.
 */
RBNode *rb_tree_search(RBTree *tree, void *data, int (*cmp)(const void *, const void *)) {
    RBNode *current = tree->root;
    while (current != NULL) {
        int result = cmp(data, current->data);
        if (result == 0) {
            return current;
        } else if (result < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

/**
 * Frees the memory occupied by a Red-Black Tree node.
 *
 * @param node The node to be freed.
 */
static void rb_free_node(RBNode *node) {
    if (node) {
        rb_free_node(node->left);
        rb_free_node(node->right);
        kfree(node);
    }
}

/**
 * @brief Destroys a red-black tree and frees the allocated memory.
 *
 * This function destroys a red-black tree and frees the memory allocated for
 * the tree nodes. It does not free the memory allocated for the data stored
 * in the tree nodes. If the tree contains dynamically allocated data, it is
 * the responsibility of the caller to free that memory before calling this
 * function.
 *
 * @param tree The red-black tree to be destroyed.
 */
void rb_tree_destroy(RBTree *tree) {
    if (tree) {
        rb_free_node(tree->root);
        kfree(tree);
    }
}
