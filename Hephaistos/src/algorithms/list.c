/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:23:46 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/26 22:04:00 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/list.h>
#include <charon.h>

/**
 * Creates a new list.
 *
 * @return A pointer to the newly created list.
 */
list_t *list_create(void) {
    list_t *list = (list_t *)kmalloc(sizeof(list_t));
    if (list == NULL) {
        return NULL;
    }

    list->root = NULL;
    list->tail = NULL;
    list->size = 0;
    list->capacity = 0;
    list->ref_count = 0;
    list->context = NULL;
    // pthread_mutex_init(&list->lock, NULL); // Initialisation du verrou (si utilisé)

    return list;
}

/**
 * @brief Destroys a list and frees all allocated memory.
 *
 * This function destroys the given list by freeing all the memory allocated for its nodes.
 * After calling this function, the list will be empty and can no longer be used.
 *
 * @param list A pointer to the list to be destroyed.
 */
void list_destroy(list_t *list) {
    list_clear(list);
    // pthread_mutex_destroy(&list->lock); // Destruction du verrou (si utilisé)
    kfree(list);
}

/**
 * Adds an element to the back of the list.
 *
 * @param list The list to which the element will be added.
 * @param data The data to be added to the list.
 */
void list_add_back(list_t *list, void *data) {
    node_t *new_node = (node_t *)kmalloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (list->root == NULL) {
        list->root = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
    list->capacity++;
}

/**
 * Adds an element to the front of the list.
 *
 * @param list The list to add the element to.
 * @param data The data to be added to the list.
 */
void list_add_front(list_t *list, void *data) {
    node_t *new_node = (node_t *)kmalloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }

    new_node->data = data;
    new_node->next = list->root;

    list->root = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }

    list->size++;
    list->capacity++;
}

/**
 * Removes the specified data from the given list.
 *
 * @param list The list from which to remove the data.
 * @param data The data to be removed from the list.
 */
void list_remove(list_t *list, void *data) {
    node_t *current = list->root;
    node_t *previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                list->root = current->next;
                if (list->root == NULL) {
                    list->tail = NULL;
                }
            } else {
                previous->next = current->next;
                if (current->next == NULL) {
                    list->tail = previous;
                }
            }
            kfree(current);
            list->size--;
            list->capacity--;
            return;
        }

        previous = current;
        current = current->next;
    }
}

/**
 * Clears all elements from the list.
 *
 * This function removes all elements from the given list, making it empty.
 *
 * @param list A pointer to the list to be cleared.
 */
void list_clear(list_t *list) {
    node_t *current = list->root;
    node_t *next;

    while (current != NULL) {
        next = current->next;
        kfree(current);
        current = next;
    }

    list->root = NULL;
    list->tail = NULL;
    list->size = 0;
    list->capacity = 0;
}

/**
 * Inserts an element into the specified index of the list.
 *
 * @param list The list to insert the element into.
 * @param data The data to be inserted.
 * @param index The index at which the element should be inserted.
 */
void list_insert(list_t *list, void *data, uint32_t index) {
    if (index > list->size) {
        return;
    }

    if (index == 0) {
        list_add_front(list, data);
        return;
    }

    node_t *new_node = (node_t *)kmalloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }

    new_node->data = data;

    node_t *current = list->root;
    node_t *previous = NULL;
    uint32_t i = 0;

    while (current != NULL && i < index) {
        previous = current;
        current = current->next;
        i++;
    }

    new_node->next = current;
    previous->next = new_node;

    if (new_node->next == NULL) {
        list->tail = new_node;
    }

    list->size++;
    list->capacity++;
}

/**
 * Calculates the size of the given list.
 *
 * @param list Pointer to the list.
 * @return The size of the list.
 */
uint32_t list_size(const list_t *list) {
    return list->size;
}

/**
 * Checks if a list is empty.
 *
 * This function takes a pointer to a list and checks if it is empty.
 *
 * @param list A pointer to the list to be checked.
 * @return 1 if the list is empty, 0 otherwise.
 */
int list_is_empty(const list_t *list) {
    return list->size == 0;
}

/**
 * Iterates over each element in the given list and applies the provided function to each element.
 *
 * @param list The list to iterate over.
 * @param f A pointer to the function to apply to each element.
 *          The function should take a void pointer as its parameter.
 *          It is responsible for casting the void pointer to the appropriate type.
 *          The function should not modify the list structure itself.
 */
void list_iterate(const list_t *list, void (*f)(void *)) {
    node_t *current = list->root;

    while (current != NULL) {
        f(current->data);
        current = current->next;
    }
}

/**
 * Compares two elements of a list.
 *
 * This function is used as a comparison function for sorting or searching elements in a list.
 * It compares the values pointed to by the pointers `a` and `b`.
 *
 * @param a Pointer to the first element to compare.
 * @param b Pointer to the second element to compare.
 * @return An integer value less than, equal to, or greater than zero if `a` is found to be less than, equal to, or greater than `b`, respectively.
 */
int list_compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * Swaps the values of two integers.
 *
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Sorts the elements in the given list using the provided comparison function.
 *
 * @param list The list to be sorted.
 * @param cmp A pointer to the comparison function that determines the order of the elements.
 *            The comparison function should return a negative value if the first element is less than the second,
 *            a positive value if the first element is greater than the second, and zero if they are equal.
 */
void list_sort(list_t *list, int (*cmp)(const void *, const void *)) {
    node_t *current = list->root;
    node_t *next = NULL;

    if (list->size < 2) {
        return;
    }

    for (uint32_t i = 0; i < list->size - 1; i++) {
        current = list->root;
        next = current->next;

        for (uint32_t j = 0; j < list->size - i - 1; j++) {
            if (cmp(current->data, next->data) > 0) {
                void *temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
            current = next;
            next = next->next;
        }
    }
}

/**
 * Retrieves the element at the specified index in the given list.
 *
 * @param list The list from which to retrieve the element.
 * @param index The index of the element to retrieve.
 * @return A pointer to the element at the specified index, or NULL if the index is out of bounds.
 */
void *list_get(const list_t *list, uint32_t index) {
    if (index >= list->size) {
        return NULL;
    }

    node_t *current = list->root;
    uint32_t i = 0;

    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }

    return current->data;
}
