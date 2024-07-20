/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stddef.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:08:03 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/20 12:34:28 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STDDEF_H
# define _STDDEF_H

typedef unsigned int size_t;
typedef int ssize_t;
typedef signed long ptrdiff_t;
typedef unsigned char uchar_t;
typedef unsigned int wchar_t;

typedef unsigned long hex_t;
typedef unsigned long long hex64_t;

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long int64_t;
typedef signed long long int128_t;

typedef signed long intptr_t;
typedef signed long intmax_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;
typedef unsigned long long uint128_t;

typedef unsigned long uintptr_t;
typedef unsigned long uintmax_t;

#define NULL ((void *)0)

#define __UNUSED(x) ((void)(x))

#define INT8_MIN -128
#define INT8_MAX 127

#define INT16_MIN -32768
#define INT16_MAX 32767

#define INT32_MIN -2147483648
#define INT32_MAX 2147483647

#define INT64_MIN -9223372036854775808
#define INT64_MAX 9223372036854775807

#define INT128_MIN (-170141183460469231731687303715884105728LL)
#define INT128_MAX (170141183460469231731687303715884105727LL)

#define UINT8_MIN 0
#define UINT8_MAX 255

#define UINT16_MIN 0
#define UINT16_MAX 65535

#define UINT32_MIN 0
#define UINT32_MAX 4294967295

#define UINT64_MIN 0
#define UINT64_MAX 18446744073709551615

#define UINT128_MIN 0ULL
#define UINT128_MAX 340282366920938463463374607431768211455ULL

#define INTPTR_MIN -9223372036854775808
#define INTPTR_MAX 9223372036854775807

#define UINTPTR_MIN 0
#define UINTPTR_MAX 18446744073709551615

#define SIZE_MAX ((size_t)-1)
#define SSIZE_MAX ((ssize_t)(SIZE_MAX / 2))
#define SSIZE_MIN (-SSIZE_MAX - 1)

#define offsetof(type, member) ((size_t) &((type *)0)->member)

#endif /* !_STDDEF_H */