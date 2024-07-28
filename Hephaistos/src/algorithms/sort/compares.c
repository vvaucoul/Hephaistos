/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compares.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:08:11 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 01:28:40 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/sort.h>
#include <string.h>

// ! ||--------------------------------------------------------------------------------||
// ! ||                                COMPARE FUNCTIONS                               ||
// ! ||--------------------------------------------------------------------------------||

/**
 * @brief Compares two integers.
 *
 * This function is used as a comparison function for sorting algorithms.
 * It compares two integers pointed to by the parameters `a` and `b`.
 *
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 * @return An integer less than, equal to, or greater than zero if the first integer is considered to be respectively less than, equal to, or greater than the second integer.
 */
int cmp_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * @brief Compares two strings.
 *
 * This function is used as a comparison function for sorting strings.
 * It compares two strings pointed to by the arguments `a` and `b`.
 *
 * @param a Pointer to the first string.
 * @param b Pointer to the second string.
 * @return An integer less than, equal to, or greater than zero if the first string is found to be less than, equal to, or greater than the second string, respectively.
 */
int cmp_string(const void *a, const void *b) {
    return (strcmp((const char *)a, (const char *)b));
}

/**
 * @brief Compares two characters.
 *
 * This function is used as a comparison function for sorting characters.
 * It compares the values of the characters pointed to by the pointers `a` and `b`.
 *
 * @param a Pointer to the first character.
 * @param b Pointer to the second character.
 * @return An integer less than, equal to, or greater than zero if the first character is found to be less than, equal to, or greater than the second character, respectively.
 */
int cmp_char(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

/**
 * @brief Compares two int8_t values.
 *
 * This function is used as a comparison function for sorting or searching algorithms.
 * It compares the values pointed to by the pointers 'a' and 'b'.
 *
 * @param a Pointer to the first int8_t value.
 * @param b Pointer to the second int8_t value.
 * @return An integer less than, equal to, or greater than zero if the first value is found to be less than, equal to, or greater than the second value, respectively.
 */
int cmp_int8_t(const void *a, const void *b) {
    return (*(int8_t *)a - *(int8_t *)b);
}

/**
 * @brief Compares two int16_t values.
 *
 * This function is used as a comparison function for sorting int16_t values.
 * It compares the values pointed to by the pointers 'a' and 'b' and returns
 * an integer value indicating their relative order.
 *
 * @param a Pointer to the first int16_t value.
 * @param b Pointer to the second int16_t value.
 * @return An integer value less than, equal to, or greater than zero if the
 *         first value is considered to be respectively less than, equal to, or
 *         greater than the second value.
 */
int cmp_int16_t(const void *a, const void *b) {
    return (*(int16_t *)a - *(int16_t *)b);
}

/**
 * @brief Compares two int32_t values.
 *
 * This function is used as a comparison function for sorting int32_t values.
 * It compares the values pointed to by the pointers 'a' and 'b' and returns
 * an integer value indicating their relative order.
 *
 * @param a Pointer to the first int32_t value.
 * @param b Pointer to the second int32_t value.
 * @return An integer value less than, equal to, or greater than zero if the
 *         first value is considered to be respectively less than, equal to, or
 *         greater than the second value.
 */
int cmp_int32_t(const void *a, const void *b) {
    return (*(int32_t *)a - *(int32_t *)b);
}

/**
 * @brief Compares two int64_t values.
 *
 * This function is used as a comparison function for sorting int64_t values.
 * It compares the values pointed to by the pointers 'a' and 'b' and returns
 * an integer value indicating their relative order.
 *
 * @param a Pointer to the first int64_t value.
 * @param b Pointer to the second int64_t value.
 * @return An integer value less than, equal to, or greater than zero if the
 *         first value is considered to be respectively less than, equal to, or
 *         greater than the second value.
 */
int cmp_int64_t(const void *a, const void *b) {
    return (*(int64_t *)a > *(int64_t *)b) - (*(int64_t *)a < *(int64_t *)b);
}

/**
 * @brief Compares two uint8_t values.
 *
 * This function is used as a comparison function for sorting uint8_t values.
 * It compares the values pointed to by the pointers 'a' and 'b'.
 *
 * @param a Pointer to the first uint8_t value.
 * @param b Pointer to the second uint8_t value.
 * @return An integer less than, equal to, or greater than zero if the first value is found to be less than, equal to, or greater than the second value, respectively.
 */
int cmp_uint8_t(const void *a, const void *b) {
    return (*(uint8_t *)a - *(uint8_t *)b);
}

/**
 * @brief Compares two uint16_t values.
 *
 * This function is used as a comparison function for sorting or searching algorithms.
 * It compares the values pointed to by the pointers 'a' and 'b' and returns an integer
 * indicating their relative order.
 *
 * @param a Pointer to the first uint16_t value.
 * @param b Pointer to the second uint16_t value.
 * @return An integer less than, equal to, or greater than zero if the first value is
 *         considered to be less than, equal to, or greater than the second value,
 *         respectively.
 */
int cmp_uint16_t(const void *a, const void *b) {
    return (*(uint16_t *)a - *(uint16_t *)b);
}

/**
 * @brief Compares two uint32_t values.
 *
 * This function is used as a comparison function for sorting uint32_t values.
 * It compares the values pointed to by the pointers 'a' and 'b'.
 *
 * @param a Pointer to the first uint32_t value.
 * @param b Pointer to the second uint32_t value.
 * @return An integer less than, equal to, or greater than zero if the first value is found to be less than, equal to, or greater than the second value, respectively.
 */
int cmp_uint32_t(const void *a, const void *b) {
    return (*(uint32_t *)a - *(uint32_t *)b);
}

/**
 * @brief Compares two uint64_t values.
 *
 * This function is used as a comparison function for sorting uint64_t values.
 * It compares the values pointed to by the pointers 'a' and 'b' and returns
 * an integer value indicating their relative order.
 *
 * @param a Pointer to the first uint64_t value.
 * @param b Pointer to the second uint64_t value.
 * @return An integer value less than, equal to, or greater than zero if the
 *         first value is considered to be respectively less than, equal to, or
 *         greater than the second value.
 */
int cmp_uint64_t(const void *a, const void *b) {
    return (*(uint64_t *)a > *(uint64_t *)b) - (*(uint64_t *)a < *(uint64_t *)b);
}

/**
 * @brief Compares two floating-point numbers.
 *
 * This function is used as a comparison function for sorting floating-point numbers.
 * It compares the values pointed to by the arguments 'a' and 'b'.
 *
 * @param a Pointer to the first floating-point number.
 * @param b Pointer to the second floating-point number.
 * @return An integer less than, equal to, or greater than zero if 'a' is found to be
 *         less than, equal to, or greater than 'b', respectively.
 */
int cmp_float(const void *a, const void *b) {
    return (*(float *)a > *(float *)b) - (*(float *)a < *(float *)b);
}

/**
 * @brief Compares two double values.
 *
 * This function is used as a comparison function for sorting double values.
 * It compares the values pointed to by the pointers 'a' and 'b'.
 *
 * @param a Pointer to the first double value.
 * @param b Pointer to the second double value.
 * @return An integer value less than, equal to, or greater than zero if the first value is found to be less than, equal to, or greater than the second value, respectively.
 */
int cmp_double(const void *a, const void *b) {
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}