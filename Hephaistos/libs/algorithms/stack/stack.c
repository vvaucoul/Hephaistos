/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:43:07 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/22 11:57:02 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <charon.h>

/**
 * @brief Creates a new stack.
 *
 * @return A pointer to the newly created stack, or NULL if memory allocation failed.
 */
stack_t *stack_create(void) {
    stack_t *stack = (stack_t *)kmalloc(sizeof(stack_t));
    if (!stack) {
        return NULL; // Memory allocation failed
    }
    stack->size = 0;
    return stack;
}

/**
 * @brief Destroys a stack.
 *
 * @param stack The stack to destroy.
 */
void stack_destroy(stack_t *stack) {
    if (stack) {
        kfree(stack);
    }
}

/**
 * @brief Pushes an element onto the stack.
 *
 * @param stack The stack to push the element onto.
 * @param data The element to push onto the stack.
 */
void stack_push(stack_t *stack, void *data) {
    if (!stack || stack->size >= STACK_MAX_SIZE) {
        return; // Stack is full or NULL
    }
    stack->data[stack->size] = data;
    stack->size++;
}

/**
 * @brief Pops an element from the stack.
 *
 * @param stack The stack to pop the element from.
 * @return The popped element, or NULL if the stack is empty or NULL.
 */
void *stack_pop(stack_t *stack) {
    if (!stack || stack->size == 0) {
        return NULL; // Stack is empty or NULL
    }
    stack->size--;
    return stack->data[stack->size];
}

/**
 * @brief Returns the element at the top of the stack without removing it.
 *
 * @param stack The stack to peek the element from.
 * @return The element at the top of the stack, or NULL if the stack is empty or NULL.
 */
void *stack_peek(stack_t *stack) {
    if (!stack || stack->size == 0) {
        return NULL; // Stack is empty or NULL
    }
    return stack->data[stack->size - 1];
}

/**
 * @brief Returns the element at the specified index in the stack.
 *
 * @param stack The stack to get the element from.
 * @param index The index of the element to get.
 * @return The element at the specified index, or NULL if the index is invalid or the stack is NULL.
 */
void *stack_get_element(stack_t *stack, int index) {
    if (!stack || index < 0 || index >= stack->size) {
        return NULL; // Invalid index or NULL stack
    }
    return stack->data[index];
}

/**
 * @brief Checks if the stack is empty.
 *
 * @param stack The stack to check.
 * @return 1 if the stack is empty or NULL, 0 otherwise.
 */
int stack_is_empty(stack_t *stack) {
    return stack ? stack->size == 0 : 1; // Return 1 if stack is NULL or empty
}

/**
 * @brief Checks if the stack is full.
 *
 * @param stack The stack to check.
 * @return 1 if the stack is full, 0 if the stack is NULL.
 */
int stack_is_full(stack_t *stack) {
    return stack ? stack->size >= STACK_MAX_SIZE : 0; // Return 0 if stack is NULL
}

/**
 * @brief Returns the size of the stack.
 *
 * @param stack The stack to get the size of.
 * @return The size of the stack, or -1 if the stack is NULL.
 */
int stack_get_size(stack_t *stack) {
    return stack ? stack->size : -1; // Return -1 if stack is NULL
}
