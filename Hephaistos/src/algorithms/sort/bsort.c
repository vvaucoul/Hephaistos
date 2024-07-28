/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:58:52 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 11:30:56 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/sort.h>
#include <string.h>

/**
 * @brief Sorts an array using the bubble sort algorithm.
 *
 * This function sorts the elements of the array in ascending order using the bubble sort algorithm.
 *
 * @param array The array to be sorted.
 * @param size The number of elements in the array.
 * @param elem_size The size of each element in the array.
 * @param cmp A pointer to the comparison function used to compare elements.
 *            The comparison function should return a negative value if the first element is less than the second element,
 *            a positive value if the first element is greater than the second element,
 *            and zero if the elements are equal.
 */
void bsort(void *array, uint32_t size, uint32_t elem_size, int (*cmp)(const void *, const void *)) {
    char *ptr = (char *)array;
    char *end = (char *)array + (size - 1) * elem_size;
    char tmp[elem_size];

    while (ptr < end) {
        if (cmp(ptr, ptr + elem_size) > 0) {
            memcpy(tmp, ptr, elem_size);
            memcpy(ptr, ptr + elem_size, elem_size);
            memcpy(ptr + elem_size, tmp, elem_size);
            ptr = (char *)array;
        } else {
            ptr += elem_size;
        }
    }
}
