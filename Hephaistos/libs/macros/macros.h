/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:21:32 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/22 13:05:43 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MACROS_H
#define _MACROS_H

/* Logical Operators for C */
#ifndef __cplusplus
#define and &&
#define or ||
#define not !
#define not_eq !=
#define equals ==
#define is =
#endif

/* Pause Execution Indefinitely */
#define pause() \
    while (1) { \
    }

/* Loop Macros */
#define for_range(i, x, y) \
    for (i = (x); i < (y); ++i)

#define for_range_reverse(i, x, y) \
    for (i = (x); i > (y); --i)

#define for_range_step(i, x, y, step) \
    for (i = (x); i < (y); i += (step))

#define for_range_reverse_step(i, x, y, step) \
    for (i = (x); i > (y); i -= (step))

#define for_each(i, array) \
    for (i = 0; i < array_get_size(array); ++i)

#define for_each_reverse(i, array) \
    for (i = array_get_size(array) - 1; i >= 0; --i)

/* Array Macros */
#define array_get_size(array) \
    (sizeof(array) / sizeof((array)[0]))

#define array_last(array) \
    (array[array_get_size(array) - 1])

#define array_first(array) \
    (array[0])

#define array_last_index(array) \
    (array_get_size(array) - 1)

#define set_array(array, value)                      \
    for (uint32_t i = 0; i < array_get_size(array); ++i) \
        (array)[i] = (value);

#define init_array(array)                            \
    for (uint32_t i = 0; i < array_get_size(array); ++i) \
        (array)[i] = 0x0;

#define is_array(array) \
    ((void *)&(array) == (void *)(array))

/* Utility Macros */
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

/* Attribute Macros */
#define __unused__ __attribute__((unused))
#define __noreturn__ __attribute__((noreturn))
#define __packed__ __attribute__((packed))
#define __aligned__(x) __attribute__((aligned(x)))
#define __section__(x) __attribute__((section(x)))
#define __deprecated__ __attribute__((deprecated))
#define __used__ __attribute__((used))
#define __weak__ __attribute__((weak))
#define __malloc__ __attribute__((malloc))
#define __always_inline__ __attribute__((always_inline))
#define __nonnull__ __attribute__((nonnull))
#define __pure__ __attribute__((pure))
#define __const__ __attribute__((const))
#define __format__(x, y, z) __attribute__((format(x, y, z)))
#define __returns_twice__ __attribute__((returns_twice))
#define __warn_unused_result__ __attribute__((warn_unused_result))
#define __cleanup__(x) __attribute__((cleanup(x)))
#define __constructor__ __attribute__((constructor))

#endif /* !_MACROS_H */