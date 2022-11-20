/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 00:00:03 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/20 23:16:08 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include <passenger.h>

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

array_t *array_create(uint32_t size)
{
    array_t *array = kmalloc(sizeof(array_t));
    if (!array)
        return (NULL);
    array->size = size;
    array->data = kmalloc(sizeof(__array_data_t *) * (size + 1));
    if (!array->data)
        return (NULL);
    else
    {
        for (uint32_t i = 0; i <= size; ++i)
            array->data[i] = NULL;
    }
    return (array);
}

void array_destroy(array_t *array)
{
    if (!array)
        return;
    if (array->data)
    {
        for (uint32_t i = 0; i <= array->size; ++i)
        {
            if (array->data[i])
                kfree(array->data[i]);
        }
        kfree(array->data);
    }
    kfree(array);
}

void array_add(array_t *array, __array_data_t *data)
{
    if (!array)
        return;
    for (uint32_t i = 0; i <= array->size; ++i)
    {
        if (!array->data[i])
        {
            array->data[i] = kmalloc(sizeof(__array_data_t));
            if (!array->data[i])
                return;
            array->data[i] = data;
            return;
        }
    }
}

void array_remove(array_t *array, uint32_t index)
{
    if (!array)
        return;
    if (array->data[index])
    {
        kfree(array->data[index]);
        array->data[index] = NULL;
        __array_shift(array, index);
    }
}

void array_clear(array_t *array)
{
    if (!array)
        return;
    for (uint32_t i = 0; i <= array->size; ++i)
    {
        if (array->data[i])
        {
            kfree(array->data[i]);
            array->data[i] = NULL;
        }
    }
}

void array_resize(array_t *array, uint32_t size)
{
    if (!array)
        return;
    array->size = size;
    array->data = krealloc(array->data, sizeof(__array_data_t *) * (size + 1));
    if (!array->data)
        return;
    else
    {
        for (uint32_t i = 0; i <= size; ++i)
            array->data[i] = NULL;
    }
}

void array_set(array_t *array, uint32_t index, __array_data_t *data)
{
    if (!array)
        return;
    if (array->data[index])
        kfree(array->data[index]);
    array->data[index] = kmalloc(sizeof(__array_data_t));
    if (!array->data[index])
        return;
    array->data[index] = data;
}

__array_data_t array_get(array_t *array, uint32_t index)
{
    if (!array)
        return (NULL);
    return (array->data[index]);
}

uint32_t array_size(array_t *array)
{
    if (!array)
        return (0);
    return (array->size);
}
