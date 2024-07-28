/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithm_array.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:31:48 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 13:43:36 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>

#include <algorithms/array.h>
#include <assert.h>

// Test array creation
void test_array_create(void) {
    Array *array = array_create(2);
    assert(array != NULL);
    assert(array->size == 0);
    assert(array->capacity == 2);
    array_destroy(array);
}

// Test push and pop operations
void test_array_push_pop(void) {
    Array *array = array_create(2);
    int values[] = {1, 2, 3};

    array_push(array, &values[0]);
    array_push(array, &values[1]);
    array_push(array, &values[2]);

    assert(array->size == 3);
    assert(array->capacity >= 3);

    int *pop_value = array_pop(array);
    assert(pop_value == &values[2]);
    assert(array->size == 2);

    pop_value = array_pop(array);
    assert(pop_value == &values[1]);
    assert(array->size == 1);

    pop_value = array_pop(array);
    assert(pop_value == &values[0]);
    assert(array->size == 0);

    pop_value = array_pop(array);
    assert(pop_value == NULL);

    array_destroy(array);
}

// Test get and set operations
void test_array_get_set(void) {
    Array *array = array_create(2);
    int values[] = {1, 2};

    array_push(array, &values[0]);
    array_push(array, &values[1]);

    assert(*(int *)array_get(array, 0) == 1);
    assert(*(int *)array_get(array, 1) == 2);
    assert(array_get(array, 2) == NULL);

    int new_value = 3;
    array_set(array, 1, &new_value);
    assert(*(int *)array_get(array, 1) == 3);

    array_destroy(array);
}

// Test insert and remove operations
void test_array_insert_remove(void) {
    Array *array = array_create(2);
    int values[] = {1, 3};
    int new_value = 2;

    array_push(array, &values[0]);
    array_push(array, &values[1]);

    array_insert(array, 1, &new_value);
    assert(array->size == 3);
    assert(*(int *)array_get(array, 0) == 1);
    assert(*(int *)array_get(array, 1) == 2);
    assert(*(int *)array_get(array, 2) == 3);

    array_remove(array, 1);
    assert(array->size == 2);
    assert(*(int *)array_get(array, 0) == 1);
    assert(*(int *)array_get(array, 1) == 3);

    array_destroy(array);
}

// Test array edge cases
void test_array_edge_cases(void) {
    Array *array = array_create(1);
    int value = 1;

    // Test insertion and removal of a single element
    array_push(array, &value);
    assert(array->size == 1);
    assert(*(int *)array_get(array, 0) == 1);

    array_remove(array, 0);
    assert(array->size == 0);
    assert(array_get(array, 0) == NULL);

    // Test exceeding initial capacity
    for (int i = 0; i < 10; i++) {
        int *val = (int *)kmalloc(sizeof(int));
        *val = i;
        array_push(array, val);
    }
    assert(array->size == 10);
    for (int i = 0; i < 10; i++) {
        assert(*(int *)array_get(array, i) == i);
    }

    for (int i = 0; i < 10; i++) {
        kfree(array_get(array, i));
    }
    array_destroy(array);
}

// Test array resizing
void test_array_resize(void) {
    Array *array = array_create(2);
    int values[] = {1, 2, 3, 4};

    // Fill the array with more elements than its initial capacity
    for (int i = 0; i < 4; i++) {
        array_push(array, &values[i]);
    }

    // Check that the size and capacity of the array are correct
    assert(array->size == 4);
    assert(array->capacity >= 4);

    // Resize the array to a smaller capacity
    array_resize(array, 2);
    assert(array->size == 4);  // The size should not change
    assert(array->capacity >= 4);  // The capacity should still be sufficient to hold the existing elements

    // Resize the array to a larger capacity
    array_resize(array, 10);
    assert(array->capacity == 10);

    array_destroy(array);
}


int workflow_hephaistos_a_array(void) {
    test_array_create();
    test_array_push_pop();
    test_array_get_set();
    test_array_insert_remove();
    test_array_edge_cases();
    test_array_resize();
    return (0);
}