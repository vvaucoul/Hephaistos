/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:33:51 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 11:18:44 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/sort.h>
#include <stddef.h>
#include <memory.h>

static int get_max(void *array, uint32_t size, uint32_t elem_size, int (*cmp)(const void *, const void *)) {
    int max = cmp(array, array + (size - 1) * elem_size);

    for (uint32_t i = 1; i < size; ++i) {
        if (cmp(array + i * elem_size, array + (i - 1) * elem_size) > max) {
            max = cmp(array + i * elem_size, array + (i - 1) * elem_size);
        }
    }
    return (max);
}

void counting_sort(void *array, uint32_t size, uint32_t elem_size, int (*cmp)(const void *, const void *)) {
    int max = get_max(array, size, elem_size, cmp);
    int count[max + 1];
    char output[size * elem_size];

    memset(count, 0, sizeof(count));
    for (uint32_t i = 0; i < size; ++i) {
        ++count[cmp(array + i * elem_size, array + (i - 1) * elem_size)];
    }
    for (int i = 1; i <= max; ++i) {
        count[i] += count[i - 1];
    }
    for (uint32_t i = size - 1; i >= 0; --i) {
        memcpy(output + (count[cmp(array + i * elem_size, array + (i - 1) * elem_size)] - 1) * elem_size, array + i * elem_size, elem_size);
        --count[cmp(array + i * elem_size, array + (i - 1) * elem_size)];
    }
    memcpy(array, output, size * elem_size);
}

/**
 * @brief Sorts an array using the radix sort algorithm.
 *
 * This function sorts the given array in ascending order using the radix sort algorithm.
 *
 * @param array The array to be sorted.
 * @param size The number of elements in the array.
 * @param elem_size The size of each element in the array.
 * @param cmp A pointer to the comparison function used to compare elements.
 *            The comparison function should return a negative value if the first element is less than the second element,
 *            a positive value if the first element is greater than the second element,
 *            and zero if the elements are equal.
 */
void rsort(void *array, uint32_t size, uint32_t elem_size, int (*cmp)(const void *, const void *)) {
    int max = get_max(array, size, elem_size, cmp);

    for (uint32_t place = 1; max / place > 0; place *= 10) {
        counting_sort(array, size, elem_size, cmp);
    }
}
