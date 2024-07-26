/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:40:45 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/26 22:04:37 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_H
#define BST_H

typedef struct s_bst_node {
    void *data;
    struct s_bst_node *left;
    struct s_bst_node *right;
} BSTNode;

typedef struct s_bst {
    BSTNode *root;
} BST;

BST *bst_create(void);
BSTNode *bst_create_node(void *data);

void bst_insert(BST *bst, void *data, int (*cmp)(const void *, const void *));

void bst_destroy(BST *bst);
void bst_destroy_node(BSTNode *node);

void *bst_search(BST *bst, void *data, int (*cmp)(const void *, const void *));

#endif /* !BST_H */