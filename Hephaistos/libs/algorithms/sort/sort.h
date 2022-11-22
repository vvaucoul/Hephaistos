/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:26:20 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/22 01:28:18 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SORT_H
#define _SORT_H

#include <libs/stddef/stddef.h>

extern int cmp_int(const void *a, const void *b);
extern int cmp_string(const void *a, const void *b);

extern void bubble_sort(void *array, uint32_t size, int (*cmp)(const void *, const void *));

extern void insertion_sort(void *array, uint32_t size, int (*cmp)(const void *, const void *));

extern void radix_sort(void *array, uint32_t size, int (*cmp)(const void *, const void *));

#endif /* _SORT_H */