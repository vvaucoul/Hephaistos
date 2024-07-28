/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithm_stack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:00:41 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 11:14:46 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>

#include <algorithms/stack.h>
#include <assert.h>

#define STACK_DEBUG 0

static int __data[STACK_MAX_SIZE];

#if STACK_DEBUG == 1
static void __display_stack(stack_t *stack) {
    printk("Stack size: %d\n", stack_get_size(stack));
    for (int i = 0; i < stack_get_size(stack); i++) {
        void *data = stack_get_element(stack, i);
        printk("%d", *(int *)data);
        if (i < stack_get_size(stack) - 1) {
            printk(", ");
        }
    }
    printk("\n");
}
#endif

static void initialize_data() {
    for (int i = 0; i < 128; i++) {
        __data[i] = i;
    }
}

int workflow_hephaistos_a_stack(void) {

    initialize_data();

    stack_t *stack = stack_create();
    assert_msg(stack != NULL, "Stack creation failed");

    // Test stack push and pop
    for (int i = 0; i < 10; i++) {
        stack_push(stack, (int *)(&__data[i]));
    }

    assert_msg(stack_get_size(stack) == 10, "Stack size is incorrect");
    for (int i = 9; i >= 0; i--) {
        void *data = stack_pop(stack);
        assert_msg(data != NULL, "Stack pop failed");
        assert_msg(*(int *)data == i, "Stack pop returned incorrect data");
    }
    assert_msg(stack_get_size(stack) == 0, "Stack size is incorrect");

    // Test stack peek
    for (int i = 0; i < 10; i++) {
        stack_push(stack, (int *)(&__data[i]));
    }

    for (int i = 9; i >= 0; i--) {
        void *data = stack_peek(stack);
        assert_msg(data != NULL, "Stack peek failed");
        assert_msg(*(int *)data == i, "Stack peek returned incorrect data");
        stack_pop(stack);
    }

    // Test stack get element
    for (int i = 0; i < 10; i++) {
        stack_push(stack, (int *)(&__data[i]));
    }

    for (int i = 0; i < 10; i++) {
        void *data = stack_get_element(stack, i);
        assert_msg(data != NULL, "Stack get element failed");
        assert_msg(*(int *)data == i, "Stack get element returned incorrect data");
    }

    for (int i = 0; i < 10; i++) {
        stack_pop(stack);
    }

    // Test stack is empty and is full
    for (int i = 0; i < STACK_MAX_SIZE; i++) {
        stack_push(stack, (int *)(&__data[i]));
    }

    assert_msg(stack_is_full(stack), "Stack is not full");
    stack_pop(stack);
    assert_msg(!stack_is_full(stack), "Stack is full");
    for (int i = 0; i < STACK_MAX_SIZE - 1; i++) {
        stack_pop(stack);
    }
    assert_msg(stack_is_empty(stack), "Stack is not empty");

    stack_destroy(stack);

    return (0);
}