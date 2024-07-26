/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sscank_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:07:48 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/26 22:11:02 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio/sscank.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Reads an integer value from a string and updates the string pointer.
 *
 * @param str A pointer to a pointer to the string to read from.
 * @return The integer value read from the string.
 */
int read_int(const char **str) {
    int value = 0;
    bool negative = false;

    if (**str == '-') {
        negative = true;
        (*str)++;
    }

    while (isdigit(**str)) {
        value = value * 10 + (**str - '0');
        (*str)++;
    }

    return negative ? -value : value;
}

/**
 * Reads a string from the given source and stores it in the provided buffer.
 *
 * @param str The source string to read from.
 * @param buffer The buffer to store the read string.
 * @param max_len The maximum length of the buffer.
 */
void read_string(const char **str, char *buffer, int max_len) {
    int len = 0;

    while (**str && !isspace(**str) && len < max_len - 1) {
        *buffer++ = **str;
        (*str)++;
        len++;
    }
    *buffer = '\0';
}

void read_float(const char **str, float *value) {
    float result = 0.0;
    float fraction = 1.0;
    bool negative = false;

    if (**str == '-') {
        negative = true;
        (*str)++;
    }

    while (isdigit(**str)) {
        result = result * 10 + (**str - '0');
        (*str)++;
    }

    if (**str == '.') {
        (*str)++;
        while (isdigit(**str)) {
            result = result + (**str - '0') * fraction;
            fraction /= 10;
            (*str)++;
        }
    }

    *value = negative ? -result : result;
}

void read_double(const char **str, double *value) {
    double result = 0.0;
    double fraction = 1.0;
    bool negative = false;

    if (**str == '-') {
        negative = true;
        (*str)++;
    }

    while (isdigit(**str)) {
        result = result * 10 + (**str - '0');
        (*str)++;
    }

    if (**str == '.') {
        (*str)++;
        while (isdigit(**str)) {
            result = result + (**str - '0') * fraction;
            fraction /= 10;
            (*str)++;
        }
    }

    *value = negative ? -result : result;
}

void read_unsigned(const char **str, unsigned int *value) {
    unsigned int result = 0;

    while (isdigit(**str)) {
        result = result * 10 + (**str - '0');
        (*str)++;
    }

    *value = result;
}

void read_hexa(const char **str, unsigned int *value) {
    unsigned int result = 0;

    while (isxdigit(**str)) {
        if (isdigit(**str)) {
            result = result * 16 + (**str - '0');
        } else {
            result = result * 16 + (tolower(**str) - 'a' + 10);
        }
        (*str)++;
    }

    *value = result;
}

void read_ptr(const char **str, void **value) {
    unsigned int result = 0;

    while (isxdigit(**str)) {
        if (isdigit(**str)) {
            result = result * 16 + (**str - '0');
        } else {
            result = result * 16 + (tolower(**str) - 'a' + 10);
        }
        (*str)++;
    }

    *value = (void *)result;
}

void read_char(const char **str, char *value) {
    *value = **str;
    (*str)++;
}

void read_bool(const char **str, bool *value) {
    if (**str == 't') {
        *value = true;
        (*str)++;
    } else if (**str == 'f') {
        *value = false;
        (*str)++;
    }
}

void read_null(const char **str, void **value) {
    *value = NULL;
    (*str)++;
}

void read_long(const char **str, long *value) {
    long result = 0;
    bool negative = false;

    if (**str == '-') {
        negative = true;
        (*str)++;
    }

    while (isdigit(**str)) {
        result = result * 10 + (**str - '0');
        (*str)++;
    }

    *value = negative ? -result : result;
}

void read_long_long(const char **str, long long *value) {
    long long result = 0;
    bool negative = false;

    if (**str == '-') {
        negative = true;
        (*str)++;
    }

    while (isdigit(**str)) {
        result = result * 10 + (**str - '0');
        (*str)++;
    }

    *value = negative ? -result : result;
}

void read_unsigned_long(const char **str, unsigned long *value) {
    unsigned long result = 0;

    while (isdigit(**str)) {
        result = result * 10 + (**str - '0');
        (*str)++;
    }

    *value = result;
}

void read_unsigned_long_long(const char **str, unsigned long long *value) {
    unsigned long long result = 0;

    while (isdigit(**str)) {
        result = result * 10 + (**str - '0');
        (*str)++;
    }

    *value = result;
}
