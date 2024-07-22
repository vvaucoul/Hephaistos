/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 00:00:03 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/22 11:18:32 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include <charon.h>

/**
 * Creates a new Array with the specified capacity.
 *
 * @param capacity The initial capacity of the Array.
 * @return A pointer to the newly created Array.
 */
Array *array_create(size_t capacity) {
    Array *array = (Array *)kmalloc(sizeof(Array));
    if (!array)
        return NULL;

    array->data = (void **)kmalloc(capacity * sizeof(void *));
    if (!array->data) {
        kfree(array);
        return NULL;
    }
    array->size = 0;
    array->capacity = capacity;
    return array;
}

/**
 * Destroys an array and frees the memory allocated for it.
 *
 * @param array The array to be destroyed.
 */
void array_destroy(Array *array) {
    if (array) {
        kfree(array->data);
        kfree(array);
    }
}

/**
 * Resizes the given array to the specified new capacity.
 *
 * @param array The array to be resized.
 * @param new_capacity The new capacity of the array.
 */
void array_resize(Array *array, size_t new_capacity) {
    if (new_capacity < array->size) {
        new_capacity = array->size;
    }
    void **new_data = (void **)krealloc(array->data, new_capacity * sizeof(void *));
    if (new_data) {
        array->data = new_data;
        array->capacity = new_capacity;
    }
}

/**
 * Adds an element to the end of the array.
 *
 * @param array The array to which the element will be added.
 * @param data The data to be added to the array.
 */
void array_push(Array *array, void *data) {
    if (array->size == array->capacity) {
        array_resize(array, array->capacity * 2);
    }
    array->data[array->size++] = data;
}

/**
 * Removes and returns the last element from the array.
 *
 * @param array The array from which to remove the element.
 * @return The removed element, or NULL if the array is empty.
 */
void *array_pop(Array *array) {
    if (array->size == 0) {
        return NULL;
    }
    void *data = array->data[--array->size];
    if (array->size > 0 && array->size < array->capacity / 4) {
        array_resize(array, array->capacity / 2);
    }
    return data;
}

/**
 * Retrieves the element at the specified index in the given array.
 *
 * @param array The array from which to retrieve the element.
 * @param index The index of the element to retrieve.
 * @return A pointer to the element at the specified index, or NULL if the index is out of bounds.
 */
void *array_get(Array *array, size_t index) {
    if (index >= array->size) {
        return NULL;
    }
    return array->data[index];
}

/**
 * Sets the element at the specified index in the given array to the provided data.
 *
 * @param array The array to modify.
 * @param index The index of the element to set.
 * @param data The data to set at the specified index.
 */
void array_set(Array *array, size_t index, void *data) {
    if (index < array->size) {
        array->data[index] = data;
    }
}

/**
 * Inserts an element at the specified index in the array.
 *
 * @param array The array to insert the element into.
 * @param index The index at which to insert the element.
 * @param data The data to be inserted.
 */
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

/**
 * Removes an element from the array at the specified index.
 *
 * @param array The array from which to remove the element.
 * @param index The index of the element to remove.
 */
void array_remove(Array *array, size_t index) {
    if (index >= array->size) {
        return;
    }
    memmove(&array->data[index], &array->data[index + 1], (array->size - index - 1) * sizeof(void *));
    array->size--;
    if (array->size > 0 && array->size < array->capacity / 4) {
        array_resize(array, array->capacity / 2);
    }
}