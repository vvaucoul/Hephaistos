/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:59:13 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/14 12:53:01 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include <charon.h>
#include <libs/memory/memory.h>

static uint32_t __get_nbr_base_length(uint32_t nbr, uint32_t base) {
    uint32_t length = 0;
    while (nbr > 0) {
        nbr /= base;
        length++;
    }
    return (length);
}

/**
 * @brief Converts an unsigned integer to a string representation in the specified base.
 *
 * This function converts the given unsigned integer `nbr` to a string representation in the specified `base`.
 * The resulting string is stored in the `str` array.
 *
 * @param nbr The unsigned integer to convert.
 * @param base The base to use for the conversion. Must be between 2 and 36.
 * @param str The array to store the resulting string.
 * @return The pointer to the resulting string.
 */
uint32_t uitoa_base(uint32_t nbr, int base, char str[__ITOA_BUFFER_LENGTH__]) {
    int i;
    int size;

    size = __get_nbr_base_length(nbr, base);
    if (str == NULL)
        return (1);
    else {
        bzero(str, __ITOA_BUFFER_LENGTH__);
        for (uint8_t i = 0; i < 8; ++i)
            str[i] = '0';
    }
    i = 1;
    while (size - i >= 0) {
        str[size - i] = __ASCII_BASE__[nbr % base];
        nbr /= base;
        ++i;
    }
    return (0);
}

/**
 * @brief Converts an integer to a string representation in the specified base.
 *
 * This function converts the given integer `nbr` to a string representation in the specified `base`.
 * The resulting string is stored in the `str` array.
 *
 * @param nbr The integer to be converted.
 * @param base The base to use for the conversion.
 * @param str The array to store the resulting string.
 *
 * @return The length of the resulting string.
 */
int itoa_base(int nbr, int base, char str[__ITOA_BUFFER_LENGTH__]) {
    int i;
    int size;
    int isneg;

    size = __get_nbr_base_length(nbr, base);
    if (!str)
        return (1);
    if ((isneg = ((nbr >= -2147483647 && nbr < 0) ? 1 : 0)) == 1)
        nbr *= -1;
    i = (isneg ? 1 : 1);
    while (size - i >= 0) {
        str[size - i] = __ASCII_BASE__[nbr % base];
        nbr /= base;
        ++i;
    }
    if (isneg)
        str[0] = '-';
    str[size] = '\0';
    return (0);
}

/**
 * @brief Converts a string to an integer.
 *
 * The atoi function converts the string pointed to by 'str' to an integer representation.
 *
 * @param str The string to be converted.
 * @return The converted integer value.
 */
int atoi(const char *str) {
    int res = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str) {
        res = res * 10 + (*str - '0');
        str++;
    }
    return (res * sign);
}

/**
 * @brief Converts a string to an integer in the specified base.
 *
 * This function converts the string pointed to by `str` to an integer representation
 * using the specified `base`.
 *
 * @param str The string to be converted.
 * @param base The base to use for the conversion.
 * @return The converted integer value.
 */
int atoi_base_s(const char *str, int base) {
    int res = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str) {
        res = res * base + (*str - '0');
        str++;
    }
    return (res * sign);
}

/**
 * @brief Converts an integer to a string representation.
 *
 * This function converts the given integer `nbr` to a string representation
 * and stores it in the character array `str`. The maximum length of the
 * character array `str` should be defined by the macro `__ITOA_BUFFER_LENGTH__`.
 *
 * @param nbr The integer to be converted.
 * @param str The character array to store the string representation.
 * @return void
 */
int itoa(int nbr, char str[__ITOA_BUFFER_LENGTH__]) {
    int i;
    bool is_neg;

    if (!str)
        return (1);
    is_neg = ((nbr >= -2147483647 && nbr < 0) ? 1 : 0);
    if (is_neg)
        nbr *= -1;
    i = (is_neg ? 1 : 1);
    while (nbr) {
        str[__ITOA_BUFFER_LENGTH__ - i] = nbr % 10 + 48;
        nbr /= 10;
        ++i;
    }
    if (is_neg)
        str[0] = '-';
    str[__ITOA_BUFFER_LENGTH__ - i] = '\0';
    return (0);
}

/**
 * @brief Converts an unsigned integer to a string representation.
 *
 * This function converts the given unsigned integer to a string representation
 * and stores it in the provided character array.
 *
 * @param nbr The unsigned integer to convert.
 * @param str The character array to store the string representation.
 * @return None.
 */
int uitoa(uint32_t nbr, char str[__ITOA_BUFFER_LENGTH__]) {
    int i = 1;
    int size = 0;

    if (str == NULL)
        return (1);
    else {
        uint32_t __tmp_nbr = nbr;
        while (__tmp_nbr) {
            __tmp_nbr /= 10;
            ++size;
        }
    }
    while (nbr) {
        str[size - i] = nbr % 10 + 48;
        nbr /= 10;
        ++i;
    }
    str[size] = '\0';
    return (0);
}

/**
 * @brief Converts an integer to a string representation.
 *
 * This function takes an integer as input and converts it to a string representation.
 *
 * @param nbr The integer to be converted.
 * @return A pointer to the string representation of the integer.
 */
char *itoa_s(int nbr) {
    uint32_t length = __get_nbr_base_length(nbr, 10);
    char *str = kmalloc(sizeof(char) * (length + 1));

    if (str == NULL) {
        return (NULL);
    } else {
        memset(str, 0, length + 1);
    }
    itoa(nbr, str);
    return (str);
}

/**
 * @brief Converts an unsigned 32-bit integer to a string representation.
 *
 * This function converts the given unsigned 32-bit integer to a string representation.
 *
 * @param nbr The unsigned 32-bit integer to convert.
 * @return A pointer to the string representation of the integer.
 */
char *uitoa_s(uint32_t nbr) {
    uint32_t length = __get_nbr_base_length(nbr, 10);
    char *str = kmalloc(sizeof(char) * (length + 1));

    if (str == NULL) {
        return (NULL);
    } else {
        memset(str, 0, length + 1);
    }
    uitoa(nbr, str);
    return (str);
}

/**
 * @brief Converts an integer to a string representation in the specified base.
 *
 * This function takes an integer and a base as input and converts the integer to a string representation
 * in the specified base. It returns a pointer to the string representation.
 *
 * @param nbr The integer to be converted.
 * @param base The base for the conversion.
 * @return A pointer to the string representation of the integer.
 */
char *itoa_base_s(int nbr, int base) {
    uint32_t length = __get_nbr_base_length(nbr, base);
    char *str = kmalloc(sizeof(char) * (length + 1));

    if (str == NULL) {
        return (NULL);
    } else {
        memset(str, 0, length + 1);
    }
    itoa_base(nbr, base, str);
    return (str);
}

/**
 * @brief Converts an unsigned integer to a string representation in a specified base.
 *
 * This function takes an unsigned integer and converts it to a string representation
 * using the specified base. The resulting string is returned as a char pointer.
 *
 * @param nbr The unsigned integer to convert.
 * @param base The base to use for the conversion.
 * @return A char pointer to the string representation of the unsigned integer.
 */
char *uitoa_base_s(uint32_t nbr, int base) {
    uint32_t length = __get_nbr_base_length(nbr, base);
    char *str = kmalloc(sizeof(char) * (length + 1));

    if (str == NULL) {
        return (NULL);
    } else {
        memset(str, 0, length + 1);
    }
    uitoa_base(nbr, base, str);
    return (str);
}

/**
 * @brief Converts a floating-point number to a string representation.
 *
 * This function takes a floating-point number and converts it to a string representation
 * with a specified precision. The resulting string can be used for display or further processing.
 *
 * @param num The floating-point number to convert.
 * @param precision The number of decimal places to include in the string representation.
 * @return A pointer to the string representation of the floating-point number.
 */
char *ftoa(double num, int precision) {
    char *str = kmalloc(sizeof(char) * (precision + 1));
    int i = 0;
    int int_part = (int)num;
    double dec_part = num - (double)int_part;

    if (str == NULL) {
        return (NULL);
    } else {
        memset(str, 0, precision + 1);
    }
    while (i < precision) {
        dec_part *= 10;
        str[i++] = (int)dec_part + '0';
        dec_part -= (int)dec_part;
    }
    str[i] = '\0';
    return (str);
}

/**
 * Converts a hexadecimal number to ASCII representation.
 *
 * @param num The hexadecimal number to convert.
 * @return The ASCII representation of the hexadecimal number.
 */
char *htoa(uint32_t num) {
    char *str = kmalloc(sizeof(char) * 9);
    int i = 0;

    if (str == NULL) {
        return (NULL);
    } else {
        memset(str, 0, 9);
    }
    while (i < 8) {
        int temp = i++;
        str[temp] = __ASCII_BASE__[(num >> (temp * 4)) & 0xF];
    }
    str[i] = '\0';
    return (str);
}

/**
 * Converts a binary number to ASCII representation.
 *
 * @param num The binary number to convert.
 * @return The ASCII representation of the binary number.
 */
char *btoa(uint32_t num) {
    char *str = kmalloc(sizeof(char) * 33);
    int i = 0;

    if (str == NULL) {
        return (NULL);
    } else {
        memset(str, 0, 33);
    }
    while (i < 32) {
        int temp = i++;
        str[temp] = __ASCII_BASE__[(num >> (temp * 1)) & 0x1];
    }
    str[i] = '\0';
    return (str);
}

/**
 * Converts an octal number to ASCII representation.
 *
 * @param num The octal number to convert.
 * @return The ASCII representation of the octal number.
 */
char *otoa(uint32_t num) {
    char *str = kmalloc(sizeof(char) * 12);
    int i = 0;

    if (str == NULL) {
        return (NULL);
    } else {
        memset(str, 0, 12);
    }
    while (i < 11) {
        int temp = i++;
        str[temp] = __ASCII_BASE__[(num >> (temp * 3)) & 0x7];
    }
    str[i] = '\0';
    return (str);
}

/**
 * Converts a string to a floating-point number.
 *
 * @param str The string to convert.
 * @return The floating-point number representation of the string.
 */
double atof(const char *str) {
    double res = 0;
    double sign = 1;
    int i = 0;

    if (*str == '-') {
        sign = -1;
        str++;
    }
    while (*str) {
        if (*str == '.') {
            i++;
            str++;
            continue;
        }
        res = res * 10 + (*str - '0');
        str++;
        if (i)
            i++;
    }
    while (i-- > 0)
        res /= 10;
    return (res * sign);
}