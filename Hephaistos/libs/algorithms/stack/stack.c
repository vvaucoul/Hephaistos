/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:43:07 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/14 16:33:14 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <charon.h>

/**
 * @brief Creates a new stack.
 *
 * @return A pointer to the newly created stack.
 */
stack_t *stack_create(void) {
    stack_t *stack = kmalloc(sizeof(stack_t));

    if (stack == NULL) {
        return (NULL);
    }

    stack->size = 0;

    memset(stack->data, 0, sizeof(stack->data));
    return (stack);
}

/**
 * @brief Destroys a stack and frees the allocated memory.
 *
 * This function destroys the given stack and frees the memory allocated for it.
 *
 * @param stack The stack to be destroyed.
 */
void stack_destroy(stack_t *stack) {
    if (stack == NULL) {
        return;
    }
    kfree(stack);
}

/**
 * @brief Pushes an element onto the stack.
 *
 * This function adds the specified data to the top of the stack.
 *
 * @param stack The stack to push the element onto.
 * @param data The data to be pushed onto the stack.
 */
void stack_push(stack_t *stack, void *data) {
    if (stack == NULL) {
        return;
    } else {
        stack->data[stack->size] = data;
        stack->size += 1;
    }
}

/**
 * @brief Removes and returns the top element from the stack.
 *
 * This function removes the top element from the specified stack and returns it.
 *
 * @param stack A pointer to the stack from which to pop the element.
 * @return A pointer to the element that was popped from the stack, or NULL if the stack is empty.
 */
void *stack_pop(stack_t *stack) {
    void *data = NULL;

    if (stack == NULL) {
        return (NULL);
    } else {
        data = stack->data[stack->size - 1];
        stack->data[stack->size - 1] = NULL;
        stack->size -= 1;
    }
    return (data);
}

/**
 * @brief Retrieves the top element of the stack without removing it.
 *
 * This function returns a pointer to the top element of the stack without modifying the stack itself.
 *
 * @param stack A pointer to the stack.
 * @return A pointer to the top element of the stack, or NULL if the stack is empty.
 */
void *stack_peek(stack_t *stack) {
    void *data = NULL;

    if (stack == NULL) {
        return (NULL);
    } else {
        data = stack->data[stack->size - 1];
    }
    return (data);
}

/**
 * @brief Retrieves the element at the specified index in the stack.
 *
 * This function returns a pointer to the element at the given index in the stack.
 * The index parameter should be a valid index within the range of the stack.
 *
 * @param stack The stack from which to retrieve the element.
 * @param index The index of the element to retrieve.
 * @return A pointer to the element at the specified index, or NULL if the index is out of range.
 */
void *stack_get_element(stack_t *stack, int index) {
    void *data = NULL;

    if (stack == NULL) {
        return (NULL);
    } else {
        data = stack->data[index];
    }
    return (data);
}

/**
 * Checks if the stack is empty.
 *
 * @param stack The stack to be checked.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int stack_is_empty(stack_t *stack) {
    if (stack == NULL) {
        return (-1);
    }

    return (stack->size == 0);
}

/**
 * Checks if the stack is full.
 *
 * @param stack The stack to be checked.
 * @return 1 if the stack is full, 0 otherwise.
 */
int stack_is_full(stack_t *stack) {
    if (stack == NULL) {
        return (-1);
    }

    return (stack->size == STACK_MAX_SIZE);
}

/**
 * Returns the size of the stack.
 *
 * @param stack The stack whose size is to be returned.
 * @return The size of the stack.
 */
int stack_get_size(stack_t *stack) {
    if (stack == NULL) {
        return (-1);
    }

    return (stack->size);
}