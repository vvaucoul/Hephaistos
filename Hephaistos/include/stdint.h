/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:09:04 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/26 20:09:54 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STDINT_H
#define _STDINT_H

/* Exact-width integer types */
typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

/* Minimum-width integer types */
typedef signed char int_least8_t;
typedef short int_least16_t;
typedef int int_least32_t;
typedef long long int_least64_t;

typedef unsigned char uint_least8_t;
typedef unsigned short uint_least16_t;
typedef unsigned int uint_least32_t;
typedef unsigned long long uint_least64_t;

/* Fastest minimum-width integer types */
typedef signed char int_fast8_t;
typedef int int_fast16_t;
typedef int int_fast32_t;
typedef long long int_fast64_t;

typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
typedef unsigned long long uint_fast64_t;

/* Integer types capable of holding object pointers */
typedef long intptr_t;
typedef unsigned long uintptr_t;

/* Greatest-width integer types */
typedef long long intmax_t;
typedef unsigned long long uintmax_t;

/* Macros for minimum-width integer constants */
#define INT8_C(val) val
#define INT16_C(val) val
#define INT32_C(val) val
#define INT64_C(val) (val##LL)

#define UINT8_C(val) (val##U)
#define UINT16_C(val) (val##U)
#define UINT32_C(val) (val##U)
#define UINT64_C(val) (val##ULL)

/* Macros for greatest-width integer constants */
#define INTMAX_C(val) (val##LL)
#define UINTMAX_C(val) (val##ULL)

#endif /* _STDINT_H */