/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:21:32 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/20 23:16:35 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MACROS_H
#define _MACROS_H

/* OPERATORS */

#define and &&
#define or ||
#define not !
#define not_eq !=
#define equals ==
#define is =

/* INLINE FUNCTIONS */

#define pause() \
    while (1)   \
    {           \
    }

/* LOOP */

#define for_range(i, x, y) \
    for (i = x; i < y; ++i)

#define for_range_reverse(i, x, y) \
    for (i = x; i > y; --i)

#define for_range_step(i, x, y, step) \
    for (i = x; i < y; i += step)

#define for_range_reverse_step(i, x, y, step) \
    for (i = x; i > y; i -= step)

#define for_each(i, array) \
    for (i = 0; i < array_size(array); ++i)

#define for_each_reverse(i, array) \
    for (i = array_size(array) - 1; i >= 0; --i)

/* ARRAY */

#define array_get_size(array) \
    (sizeof(array) / sizeof(array[0]))

#define array_last(array) \
    array[array_size(array) - 1]

#define array_first(array) \
    array[0]

#define array_last_index(array) \
    array_size(array) - 1

#define set_array(array, value)                      \
    for (uint32_t i = 0; i < array_size(array); ++i) \
        array[i] = value;

#define init_array(array)                            \
    for (uint32_t i = 0; i < array_size(array); ++i) \
        array[i] = 0x0;

#define is_array(array) \
    ((void *)&a == (void *)a)

#endif /* !_MACROS_H */