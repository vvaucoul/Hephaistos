/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithn_array.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:31:48 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/15 20:49:40 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <hephaistos.h>

void test_create_destroy() {
    Array *array = array_create(10);

    array_destroy(array);
}

void test_resize() {
    Array *array = array_create(10);

    array_resize(array, 20);
    array_destroy(array);
}

void test_push_pop() {
    Array *array = array_create(10);
    int int1 = 42;
    array_push(array, &int1);

    int int2 = 13;
    array_push(array, &int2);

    assert(array_get(array, 0) == &int1);
    assert(array_get(array, 1) == &int2);

    void *popped = array_pop(array);
    assert(popped == &int2);

    array_destroy(array);
}

void test_get_set() {
    Array *array = array_create(10);
    int int1 = 42;
    array_push(array, &int1);

    int int2 = 13;
    array_push(array, &int2);

    array_set(array, 0, &int2);
    array_set(array, 1, &int1);

    assert(array_get(array, 0) == &int2);
    assert(array_get(array, 1) == &int1);

    array_destroy(array);
}

void test_insert_remove() {
    Array *array = array_create(10);
    int int1 = 42;
    array_push(array, &int1);

    int int2 = 13;
    array_push(array, &int2);

    int int3 = 1337;
    array_push(array, &int3);

    array_insert(array, 0, &int3);
    array_insert(array, 1, &int2);
    array_insert(array, 2, &int1);

    assert(array_get(array, 0) == &int3);
    assert(array_get(array, 1) == &int2);
    assert(array_get(array, 2) == &int1);

    array_remove(array, 1);

    assert(array_get(array, 0) == &int3);
    assert(array_get(array, 1) == &int1);

    array_remove(array, 0);

    assert(array_get(array, 0) == &int1);

    array_destroy(array);
}

int workflow_hephaistos_a_array(void) {
    test_create_destroy();
    test_resize();
    test_push_pop();
    test_get_set();
    test_insert_remove();
    return (0);
}