/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:03:11 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/14 14:04:33 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <libs/memory/memory.h>

/**
 * @brief Sorts an array using the insertion sort algorithm.
 *
 * This function sorts the given array in ascending order using the insertion sort algorithm.
 *
 * @param array The array to be sorted.
 * @param size The number of elements in the array.
 * @param elem_size The size of each element in the array.
 * @param cmp A pointer to the comparison function used to compare elements.
 *            The comparison function should return a negative value if the first element is less than the second element,
 *            a positive value if the first element is greater than the second element,
 *            and zero if the elements are equal.
 */
void isort(void *array, uint32_t size, uint32_t elem_size, int (*cmp)(const void *, const void *)) {
    char *arr = (char *)array;

    for (size_t i = 1; i < size; ++i) {
        size_t j = i;
        while (j > 0 && cmp(arr + (j - 1) * elem_size, arr + j * elem_size) > 0) {
            char temp[elem_size];

            memcpy(temp, arr + j * elem_size, elem_size);
            memcpy(arr + j * elem_size, arr + (j - 1) * elem_size, elem_size);
            memcpy(arr + (j - 1) * elem_size, temp, elem_size);
            --j;
        }
    }
}
