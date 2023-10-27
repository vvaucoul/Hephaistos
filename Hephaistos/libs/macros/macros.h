/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:21:32 by vvaucoul          #+#    #+#             */
/*   Updated: 2023/10/21 13:03:26 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MACROS_H
#define _MACROS_H

/* OPERATORS */

#ifndef __cplusplus
#define and &&
#define or ||
#define not !
#define not_eq !=
#define equals ==
#define is =
#endif

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

/* UTILS */

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#endif /* !_MACROS_H */