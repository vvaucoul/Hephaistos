/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:10:57 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/26 20:11:20 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIMITS_H
#define _LIMITS_H

/* Number of bits in a `char`.  */
#define CHAR_BIT 8

/* Minimum and maximum values a `signed char` can hold.  */
#define SCHAR_MIN (-128)
#define SCHAR_MAX 127

/* Maximum value an `unsigned char` can hold.  (Minimum is 0).  */
#define UCHAR_MAX 255

/* Minimum and maximum values a `char` can hold.  */
#ifdef __CHAR_UNSIGNED__
#define CHAR_MIN 0
#define CHAR_MAX UCHAR_MAX
#else
#define CHAR_MIN SCHAR_MIN
#define CHAR_MAX SCHAR_MAX
#endif

/* Minimum and maximum values a `signed short int` can hold.  */
#define SHRT_MIN (-32768)
#define SHRT_MAX 32767

/* Maximum value an `unsigned short int` can hold.  (Minimum is 0).  */
#define USHRT_MAX 65535

/* Minimum and maximum values a `signed int` can hold.  */
#define INT_MIN (-INT_MAX - 1)
#define INT_MAX 2147483647

/* Maximum value an `unsigned int` can hold.  (Minimum is 0).  */
#define UINT_MAX 4294967295U

/* Minimum and maximum values a `signed long int` can hold.  */
#define LONG_MIN (-LONG_MAX - 1L)
#define LONG_MAX 9223372036854775807L

/* Maximum value an `unsigned long int` can hold.  (Minimum is 0).  */
#define ULONG_MAX 18446744073709551615UL

/* Minimum and maximum values a `signed long long int` can hold.  */
#define LLONG_MIN (-LLONG_MAX - 1LL)
#define LLONG_MAX 9223372036854775807LL

/* Maximum value an `unsigned long long int` can hold.  (Minimum is 0).  */
#define ULLONG_MAX 18446744073709551615ULL

#endif /* _LIMITS_H */