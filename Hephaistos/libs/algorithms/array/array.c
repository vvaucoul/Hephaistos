/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 00:00:03 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/21 21:27:48 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include <passenger.h>

/*******************************************************************************
 *                              USEFULL FUNCTIONS                              *
 ******************************************************************************/

static void __array_swap(array_t *array, uint32_t i, uint32_t j)
{
    __array_data_t *tmp = array->data[i];

    array->data[i] = array->data[j];
    array->data[j] = tmp;
}

static void __array_shift(array_t *array, uint32_t i)
{
    while (i < array->size)
    {
        array->data[i] = array->data[i + 1];
        ++i;
    }
}

static void __array_update_first_free_index(array_t *array)
{
    uint32_t i = 0;

    while (i < array->size)
    {
        if (array->data[i] == NULL)
        {
            array->__first_free_index = i;
            return;
        }
        ++i;
    }
}

static void __array_update_last_free_index(array_t *index)
{
    uint32_t i = index->size - 1;

    while (i > 0)
    {
        if (index->data[i] == NULL)
        {
            index->__last_free_index = i;
            return;
        }
        --i;
    }
}

/*******************************************************************************
 *                          ALGORITHM ARRAY FUNCTIONS                          *
 ******************************************************************************/

static array_t *__array_create(const uint32_t size)
{
    array_t *array = kmalloc(sizeof(array_t));
    if (!array)
        return (NULL);
    array->size = size;
    array->length = 0;
    array->__first_free_index = 0;
    array->__last_free_index = 0;
    if (!(array->data = kmalloc(sizeof(__array_data_t *) * (size + 1))))
    {
        kfree(array);
        return (NULL);
    }
    else
        bzero(array->data, sizeof(__array_data_t *) * (size + 1));
    return (array);
}

static array_t *__array_expand(array_t *array, uint32_t new_size)
{
    __array_data_t **new_data = kmalloc(sizeof(__array_data_t *) * (new_size + 1));
    if (!new_data)
        return (NULL);
    bzero(new_data, sizeof(__array_data_t *) * (new_size + 1));
    memcpy(new_data, array->data, sizeof(__array_data_t *) * (array->size + 1));
    kfree(array->data);
    array->data = new_data;
    array->size = new_size;

    __array_update_first_free_index(array);
    __array_update_last_free_index(array);

    return (array);
}

static array_t *__array_contract(array_t *array, uint32_t new_size)
{
    __array_data_t **new_data = kmalloc(sizeof(__array_data_t *) * (new_size + 1));
    if (!new_data)
        return (NULL);
    bzero(new_data, sizeof(__array_data_t *) * (new_size + 1));
    memcpy(new_data, array->data, sizeof(__array_data_t *) * (new_size + 1));
    kfree(array->data);
    array->data = new_data;
    array->size = new_size;

    if (array->length > array->size)
        array->length = array->size;

    __array_update_first_free_index(array);
    __array_update_last_free_index(array);

    return (array);
}

static void __array_resize(array_t *array, uint32_t new_size)
{
    if (new_size < array->size)
        __array_contract(array, new_size);
    else if (new_size > array->size)
        __array_expand(array, new_size);
}

static void __array_add(array_t *array, __array_data_t *data)
{
    if (array->length == array->size)
    {
        if (!(array = __array_expand(array, array->size + 1)))
            return;
        else if (!(array->data))
            return;
    }

    array->data[array->__first_free_index] = data;
    array->length++;

    __array_update_first_free_index(array);
    __array_update_last_free_index(array);
}

static void __array_insert(array_t *array, __array_data_t *data, uint32_t index)
{
    if (array->length == array->size)
    {
        if (!(array = __array_expand(array, array->size + 1)))
            return;
        else if (!(array->data))
            return;
    }

    uint32_t i = array->length;

    while (i > index)
    {
        array->data[i] = array->data[i - 1];
        --i;
    }

    array->data[index] = data;
    array->length++;

    __array_update_first_free_index(array);
    __array_update_last_free_index(array);
}

static void __array_clear(array_t *array)
{
    if (!array)
        return;
    for (uint32_t i = 0; i <= array->size; ++i)
        array->data[i] = NULL;
    array->length = 0;

    __array_update_first_free_index(array);
    __array_update_last_free_index(array);
}

static void __array_destroy(array_t *array)
{
    if (!array)
        return;
    __array_clear(array);
    kfree(array->data);
    array->size = 0;
    kfree(array);
}

static void __array_remove(array_t *array, uint32_t index)
{
    if (!array || index > array->length)
        return;
    if (array->data[index])
    {
        kfree(array->data[index]);
        array->data[index] = NULL;
        __array_shift(array, index);
        array->length--;

        __array_update_first_free_index(array);
        __array_update_last_free_index(array);
    }
}

/*******************************************************************************
 *                             INTERFACE FUNCTIONS                             *
 ******************************************************************************/

/**
 * @brief Create a new array
 *
 * @param size
 * @return array_t*
 */
array_t *array_create(uint32_t size)
{
    return (__array_create(size));
}

/**
 * @brief Add data to the array
 * 
 * @param array 
 * @param data 
 */
void array_add(array_t *array, __array_data_t *data)
{
    __array_add(array, data);
}

/**
 * @brief Remove an element from the array at the given index
 * 
 * @param array 
 * @param index 
 */
void array_remove(array_t *array, uint32_t index)
{
    __array_remove(array, index);
}

/**
 * @brief Clear the array (clear all data)
 * 
 * @param array 
 */
void array_clear(array_t *array)
{
    __array_clear(array);
}

/**
 * @brief Destroy the array
 * 
 * @param array 
 */
void array_destroy(array_t *array)
{
    __array_destroy(array);
}

/**
 * @brief Resize the array
 * 
 * @param array 
 * @param size 
 */
void array_resize(array_t *array, uint32_t size)
{
    __array_resize(array, size);
}

/**
 * @brief Insert data at index
 * 
 * @param array 
 * @param data 
 * @param index 
 */
void array_insert(array_t *array, __array_data_t *data, uint32_t index)
{
    __array_insert(array, data, index);
}

/**
 * @brief Get the data at the specified index
 * 
 * @param array 
 * @param index 
 * @return __array_data_t* 
 */
__array_data_t *array_get(array_t *array, uint32_t index)
{
    if (!array)
        return (NULL);
    return (array->data[index]);
}

/**
 * @brief Get the size of the array
 * 
 * @param array 
 * @return uint32_t 
 */
uint32_t array_size(array_t *array)
{
    if (!array)
        return (0);
    return (array->size);
}

/**
 * @brief Get the length of the array
 * 
 * @param array 
 * @return uint32_t 
 */
uint32_t array_length(array_t *array)
{
    if (!array)
        return (0);
    return (array->length);
}

/**
 * @brief Get a reference to the array size
 *
 * @param array
 * @param size
 */
void array_size_ref(array_t *array, uint32_t *size)
{
    if (!array)
    {
        size = 0;
        return;
    }
    size = &array->size;
}

/**
 * @brief Get a reference to the array length
 *
 * @param array
 * @param length
 */
void array_length_ref(array_t *array, uint32_t *length)
{
    if (!array)
    {
        length = 0;
        return;
    }
    length = &array->length;
}
