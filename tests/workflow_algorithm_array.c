/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithm_array.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:31:48 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 11:00:23 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>

#include <algorithms/array.h>
#include <assert.h>

void test_array_create(void) {
    Array *array = array_create(2);
    assert(array != NULL);
    assert(array->size == 0);
    assert(array->capacity == 2);
    array_destroy(array);
}

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

int workflow_hephaistos_a_array(void) {
    test_array_create();
    test_array_push_pop();
    test_array_get_set();
    test_array_insert_remove();
    return (0);
}