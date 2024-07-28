/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithm_stack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:00:41 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 13:17:16 by vvaucoul         ###   ########.fr       */
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
    for (int i = 0; i < STACK_MAX_SIZE; i++) {
        __data[i] = i;
    }
}

void test_stack_create_and_destroy() {
    stack_t *stack = stack_create();
    assert(stack != NULL);
    assert(stack_get_size(stack) == 0);
    assert(stack_is_empty(stack));
    assert(!stack_is_full(stack));
    stack_destroy(stack);
}

void test_stack_push_and_pop() {
    stack_t *stack = stack_create();
    assert(stack != NULL);

    for (int i = 0; i < 10; i++) {
        stack_push(stack, (int *)(&__data[i]));
    }

    assert(stack_get_size(stack) == 10);

    for (int i = 9; i >= 0; i--) {
        void *data = stack_pop(stack);
        assert(data != NULL);
        assert(*(int *)data == i);
    }

    assert(stack_get_size(stack) == 0);
    assert(stack_is_empty(stack));

    stack_destroy(stack);
}

void test_stack_peek() {
    stack_t *stack = stack_create();
    assert(stack != NULL);

    for (int i = 0; i < 10; i++) {
        stack_push(stack, (int *)(&__data[i]));
    }

    for (int i = 9; i >= 0; i--) {
        void *data = stack_peek(stack);
        assert(data != NULL);
        assert(*(int *)data == i);
        stack_pop(stack);
    }

    stack_destroy(stack);
}

void test_stack_get_element() {
    stack_t *stack = stack_create();
    assert(stack != NULL);

    for (int i = 0; i < 10; i++) {
        stack_push(stack, (int *)(&__data[i]));
    }

    for (int i = 0; i < 10; i++) {
        void *data = stack_get_element(stack, i);
        assert(data != NULL);
        assert(*(int *)data == i);
    }

    stack_destroy(stack);
}

void test_stack_is_empty_and_is_full() {
    stack_t *stack = stack_create();
    assert(stack != NULL);

    assert(stack_is_empty(stack));
    assert(!stack_is_full(stack));

    for (int i = 0; i < STACK_MAX_SIZE; i++) {
        stack_push(stack, (int *)(&__data[i]));
    }

    assert(stack_is_full(stack));
    assert(!stack_is_empty(stack));

    stack_pop(stack);
    assert(!stack_is_full(stack));

    for (int i = 0; i < STACK_MAX_SIZE - 1; i++) {
        stack_pop(stack);
    }

    assert(stack_is_empty(stack));
    assert(!stack_is_full(stack));

    stack_destroy(stack);
}

void test_stack_edge_cases() {
    stack_t *stack = stack_create();
    assert(stack != NULL);

    // Pousser plus d'éléments que la taille maximale
    for (int i = 0; i < STACK_MAX_SIZE + 10; i++) {
        if (i < STACK_MAX_SIZE) {
            stack_push(stack, (int *)(&__data[i]));
        } else {
            // Stack should not allow push beyond max size
            stack_push(stack, (int *)(&__data[0]));
            assert(stack_get_size(stack) == STACK_MAX_SIZE);
            assert(stack_is_full(stack));
        }
    }

    stack_destroy(stack);
}

int workflow_hephaistos_a_stack(void) {
    initialize_data();

    test_stack_create_and_destroy();
    test_stack_push_and_pop();
    test_stack_peek();
    test_stack_get_element();
    test_stack_is_empty_and_is_full();
    test_stack_edge_cases();

    return (0);
}