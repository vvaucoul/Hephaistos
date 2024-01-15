/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 00:00:03 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/15 18:00:59 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include <charon.h>

Array *array_create(size_t capacity) {
    Array *array = kmalloc(sizeof(Array));
    array->data = kmalloc(capacity * sizeof(void *));
    array->size = 0;
    array->capacity = capacity;
    return array;
}

void array_destroy(Array *array) {
    kfree(array->data);
    kfree(array);
}

void array_resize(Array *array, size_t new_capacity) {
    array->data = krealloc(array->data, new_capacity * sizeof(void *));
    array->capacity = new_capacity;
}

void array_push(Array *array, void *data) {
    if (array->size == array->capacity) {
        array_resize(array, array->capacity * 2);
    }
    array->data[array->size] = data;
    array->size++;
}

void *array_pop(Array *array) {
    if (array->size == 0) {
        return NULL;
    }
    void *data = array->data[array->size - 1];
    array->size--;
    if (array->size < array->capacity / 4) {
        array_resize(array, array->capacity / 2);
    }
    return data;
}

void *array_get(Array *array, size_t index) {
    if (index >= array->size) {
        return NULL;
    }
    return array->data[index];
}

void array_set(Array *array, size_t index, void *data) {
    if (index >= array->size) {
        return;
    }
    array->data[index] = data;
}

void array_insert(Array *array, size_t index, void *data) {
    if (index > array->size) {
        return;
    }
    if (array->size == array->capacity) {
        array_resize(array, array->capacity * 2);
    }
    memmove(&array->data[index + 1], &array->data[index], (array->size - index) * sizeof(void *));
    array->data[index] = data;
    array->size++;
}

void array_remove(Array *array, size_t index) {
    if (index >= array->size) {
        return;
    }
    memmove(&array->data[index], &array->data[index + 1], (array->size - index - 1) * sizeof(void *));
    array->size--;
    if (array->size < array->capacity / 4) {
        array_resize(array, array->capacity / 2);
    }
}