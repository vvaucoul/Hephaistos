/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:26:20 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/14 15:34:45 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SORT_H
#define _SORT_H

#include <libs/stddef/stddef.h>

extern int cmp_int(const void *a, const void *b);
extern int cmp_string(const void *a, const void *b);
extern int cmp_char(const void *a, const void *b);
extern int cmp_int8_t(const void *a, const void *b);
extern int cmp_int16_t(const void *a, const void *b);
extern int cmp_int32_t(const void *a, const void *b);
extern int cmp_int64_t(const void *a, const void *b);
extern int cmp_uint8_t(const void *a, const void *b);
extern int cmp_uint16_t(const void *a, const void *b);
extern int cmp_uint32_t(const void *a, const void *b);
extern int cmp_uint64_t(const void *a, const void *b);
extern int cmp_float(const void *a, const void *b);
extern int cmp_double(const void *a, const void *b);

// extern void bubble_sort(void *array, uint32_t size, int (*cmp)(const void *, const void *));
// extern void insertion_sort(void *array, uint32_t size, int (*cmp)(const void *, const void *));
// extern void radix_sort(void *array, uint32_t size, int (*cmp)(const void *, const void *));

extern void bsort(void *array, uint32_t size, uint32_t elem_size, int (*cmp)(const void *, const void *));
extern void isort(void *array, uint32_t size, uint32_t elem_size, int (*cmp)(const void *, const void *));
extern void qsort(void *array, uint32_t low, uint32_t high, uint32_t elem_size, int (*cmp)(const void *, const void *));
extern void rsort(void *array, uint32_t size, uint32_t elem_size, int (*cmp)(const void *, const void *));

#endif /* _SORT_H */