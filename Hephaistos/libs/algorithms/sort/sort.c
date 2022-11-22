/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:26:13 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/22 01:33:49 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <libs/string/string.h>
#include <libs/stdio/stdio.h>

/*******************************************************************************
 *                              COMPARE FUNCTIONS                              *
 ******************************************************************************/

int cmp_int(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int cmp_string(const void *a, const void *b)
{
    return (strcmp((char *)a, (char *)b));
}

/*******************************************************************************
 *                            UTILS SORT FUNCTIONS                             *
 ******************************************************************************/

static uint32_t __radix_get_max(void *array, uint32_t size)
{
    uint32_t max = ((uint32_t *)array)[0];
    uint32_t i = 1;

    while (i < size)
    {
        if (((uint32_t *)array)[i] > max)
            max = ((uint32_t *)array)[i];
        ++i;
    }
    return (max);
}

static void __radix_count_sort(void *array, uint32_t size, uint32_t exp)
{
    uint32_t output[size];
    uint32_t count[10] = {0};

    for (uint32_t i = 0; i < size; ++i)
        count[(((uint32_t *)array)[i] / exp) % 10]++;
    for (uint32_t i = 1; i < 10; ++i)
        count[i] += count[i - 1];
    for (int32_t i = size - 1; i >= 0; --i)
    {
        output[count[(((uint32_t *)array)[i] / exp) % 10] - 1] = ((uint32_t *)array)[i];
        count[(((uint32_t *)array)[i] / exp) % 10]--;
    }
    for (uint32_t i = 0; i < size; ++i)
        ((uint32_t *)array)[i] = output[i];
}

static void __sort_swap(void *array, uint32_t i, uint32_t j)
{
    uint32_t tmp = (((uint32_t *)array)[i]);

    (((uint32_t *)array)[i]) = (((uint32_t *)array)[j]);
    (((uint32_t *)array)[j]) = tmp;
}

/*******************************************************************************
 *                               SORT ALGORITHMS                               *
 ******************************************************************************/

void bubble_sort(void *array, uint32_t size, int (*cmp)(const void *, const void *))
{
    uint32_t i = 0;
    uint32_t j = 0;

    while (i < size)
    {
        j = 0;
        while (j < size - 1)
        {
            if (cmp(&(((uint32_t *)array)[j]), &(((uint32_t *)array)[j + 1])) > 0)
            {
                __sort_swap(array, j, j + 1);
            }
            ++j;
        }
        ++i;
    }
}

void insertion_sort(void *array, uint32_t size, int (*cmp)(const void *, const void *))
{
    uint32_t i = 0;
    uint32_t j = 0;
    uint32_t tmp = 0;

    while (i < size)
    {
        j = i;
        while (j > 0)
        {
            if (cmp(&(((uint32_t *)array)[j]), &(((uint32_t *)array)[j - 1])) < 0)
            {
                __sort_swap(array, j, j - 1);
                --j;
            }
            else
                break;
        }
        ++i;
    }
}

void radix_sort(void *array, uint32_t size, int (*cmp)(const void *, const void *))
{
    uint32_t m = __radix_get_max(array, size);

    for (uint32_t exp = 1; m / exp > 0; exp *= 10)
        __radix_count_sort(array, size, exp);
}