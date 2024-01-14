/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:04:49 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/14 15:33:08 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <libs/memory/memory.h>

/**
 * @brief Swaps two elements in an array.
 *
 * This function swaps the elements at indices `i` and `j` in the given `array`.
 * The size of each element in the array is specified by `elem_size`.
 *
 * @param array The array containing the elements to be swapped.
 * @param elem_size The size of each element in the array.
 * @param i The index of the first element to be swapped.
 * @param j The index of the second element to be swapped.
 */
static void swap(void *array, uint32_t elem_size, uint32_t i, uint32_t j) {
    char temp[elem_size];

    memcpy(temp, array + i * elem_size, elem_size);
    memcpy(array + i * elem_size, array + j * elem_size, elem_size);
    memcpy(array + j * elem_size, temp, elem_size);
}

/**
 * Partition the array for quicksort algorithm.
 *
 * This function partitions the given array into two parts based on a pivot element.
 * Elements smaller than the pivot are placed before it, and elements greater than the pivot are placed after it.
 *
 * @param array The array to be partitioned.
 * @param low The starting index of the partition.
 * @param high The ending index of the partition.
 * @param elem_size The size of each element in the array.
 * @param cmp The comparison function used to compare elements in the array.
 * @return The index of the pivot element after partitioning.
 */
static uint32_t partition(void *array, uint32_t low, uint32_t high, uint32_t elem_size, int (*cmp)(const void *, const void *)) {
    uint32_t pivot = low;
    uint32_t i = low;
    uint32_t j = high;

    while (i < j) {
        while (cmp(array + i * elem_size, array + pivot * elem_size) <= 0 && i < high) {
            ++i;
        }
        while (cmp(array + j * elem_size, array + pivot * elem_size) > 0) {
            --j;
        }
        if (i < j) {
            swap(array, elem_size, i, j);
        }
    }
    swap(array, elem_size, pivot, j);
    return (j);
}

/**
 * Sorts an array using the quicksort algorithm.
 *
 * @param array The array to be sorted.
 * @param low The lower bound of the array.
 * @param high The upper bound of the array.
 * @param elem_size The size of each element in bytes.
 * @param cmp The comparison function used to compare elements.
 *            It should return a negative value if the first element is less than the second,
 *            a positive value if the first element is greater than the second,
 *            and zero if the elements are equal.
 */
void qsort(void *array, uint32_t low, uint32_t high, uint32_t elem_size, int (*cmp)(const void *, const void *)) {
    if (low < high) {
        uint32_t pivot = partition(array, low, high, elem_size, cmp);
        if (pivot > 0) {
            qsort(array, low, pivot - 1, elem_size, cmp);
        }
        qsort(array, pivot + 1, high, elem_size, cmp);
    }
}