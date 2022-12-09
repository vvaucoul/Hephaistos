/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stddef.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:08:03 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/12/09 22:27:44 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STDDEF_H
# define _STDDEF_H

typedef unsigned int size_t;
typedef int ssize_t;
typedef unsigned char uchar_t;

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

#endif /* !_STDDEF_H */