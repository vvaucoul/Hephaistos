/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:58:53 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/10/23 18:31:48 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file convert.h
 * @brief This header file provides declarations for various conversion functions.
 *
 * These functions allow you to convert between different data types, such as:
 * - integers and strings
 * - floating-point numbers and strings
 * - hexadecimal, binary, and octal numbers and strings
 */

#ifndef _CONVERT_H
#define _CONVERT_H

#include <stdbool.h>
#include <stdint.h>

/**
 * @brief Maximum size of the buffer used for integer to string conversions.
 */
#define __ITOA_BUFFER_LENGTH__ 12

/**
 * @brief String containing the characters used for base conversions.
 */
#define __ASCII_BASE__ "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

/*******************************************************************************
 * Conversion functions using stack-based buffers
 ******************************************************************************/

/**
 * @brief Converts a string to an integer.
 *
 * @param str The string to be converted.
 * @return The converted integer value.
 */
extern int atoi(const char *str);

/**
 * @brief Converts an integer to a string representation.
 *
 * @param nbr The integer to be converted.
 * @param str The character array to store the string representation.
 * @return 0 on success, 1 on error.
 */
extern int itoa(int nbr, char str[__ITOA_BUFFER_LENGTH__]);

/**
 * @brief Converts an unsigned integer to a string representation.
 *
 * @param nbr The unsigned integer to convert.
 * @param str The character array to store the string representation.
 * @return 0 on success, 1 on error.
 */
extern int uitoa(uint32_t nbr, char str[__ITOA_BUFFER_LENGTH__]);

/**
 * @brief Converts an integer to a string representation in the specified base.
 *
 * @param nbr The integer to be converted.
 * @param base The base to use for the conversion.
 * @param str The character array to store the string representation.
 * @return 0 on success, 1 on error.
 */
extern int itoa_base(int nbr, int base, char str[__ITOA_BUFFER_LENGTH__]);

/**
 * @brief Converts an unsigned integer to a string representation in the specified base.
 *
 * @param nbr The unsigned integer to convert.
 * @param base The base to use for the conversion. Must be between 2 and 36.
 * @param str The array to store the resulting string.
 * @return 0 on success, 1 on error.
 */
extern uint32_t uitoa_base(uint32_t nbr, int base, char str[__ITOA_BUFFER_LENGTH__]);

/*******************************************************************************
 * Conversion functions using heap-based buffers
 ******************************************************************************/

/**
 * @brief Converts a string to an integer in the specified base.
 *
 * @param str The string to be converted.
 * @param base The base to use for the conversion.
 * @return The converted integer value.
 */
extern int atoi_base_s(const char *str, int base);

/**
 * @brief Converts an integer to a string representation.
 *
 * @param nbr The integer to be converted.
 * @return A pointer to the allocated string representation, or NULL on error.
 */
extern char *itoa_s(int nbr);

/**
 * @brief Converts an unsigned integer to a string representation.
 *
 * @param nbr The unsigned integer to convert.
 * @return A pointer to the allocated string representation, or NULL on error.
 */
extern char *uitoa_s(uint32_t nbr);

/**
 * @brief Converts an integer to a string representation in the specified base.
 *
 * @param nbr The integer to be converted.
 * @param base The base for the conversion.
 * @return A pointer to the allocated string representation, or NULL on error.
 */
extern char *itoa_base_s(int nbr, int base);

/**
 * @brief Converts an unsigned integer to a string representation in a specified base.
 *
 * @param nbr The unsigned integer to convert.
 * @param base The base to use for the conversion.
 * @return A char pointer to the string representation of the unsigned integer, or NULL on error.
 */
extern char *uitoa_base_s(uint32_t nbr, int base);

/**
 * @brief Converts a floating-point number to a string representation.
 *
 * @param num The floating-point number to convert.
 * @param precision The number of decimal places to include in the string representation.
 * @return A pointer to the allocated string representation, or NULL on error.
 */
extern char *ftoa(double num, int precision);

/**
 * @brief Converts a hexadecimal number to ASCII representation.
 *
 * @param num The hexadecimal number to convert.
 * @return The ASCII representation of the hexadecimal number, or NULL on error.
 */
extern char *htoa(uint32_t num);

/**
 * @brief Converts a binary number to ASCII representation.
 *
 * @param num The binary number to convert.
 * @return The ASCII representation of the binary number, or NULL on error.
 */
extern char *btoa(uint32_t num);

/**
 * @brief Converts an octal number to ASCII representation.
 *
 * @param num The octal number to convert.
 * @return The ASCII representation of the octal number, or NULL on error.
 */
extern char *otoa(uint32_t num);

/**
 * @brief Converts a string to a floating-point number.
 *
 * @param str The string to convert.
 * @return The floating-point number representation of the string.
 */
extern double atof(const char *str);

#endif /* !_CONVERT_H */