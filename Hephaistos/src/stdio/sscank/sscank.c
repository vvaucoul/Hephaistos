/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sscank.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:04:36 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/26 22:10:35 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio/sscank.h>
#include <stdarg.h>

int sscank(const char *str, const char *format, ...) {
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
            case 'd': {
                int *int_arg = va_arg(args, int *);
                *int_arg = read_int(&str);
                count++;
                break;
            }
            case 's': {
                char *str_arg = va_arg(args, char *);
                read_string(&str, str_arg, 100); // Assume max string length 100 for simplicity
                count++;
                break;
            }
            case 'f': {
                float *float_arg = va_arg(args, float *);
                read_float(&str, float_arg);
                count++;
                break;
            }
            case 'l': {
                format++;
                if (*format == 'f') {
                    double *double_arg = va_arg(args, double *);
                    read_double(&str, double_arg);
                    count++;
                } else if (*format == 'd') {
                    long *long_arg = va_arg(args, long *);
                    read_long(&str, long_arg);
                    count++;
                } else if (*format == 'l') {
                    format++;
                    if (*format == 'd') {
                        long long *long_long_arg = va_arg(args, long long *);
                        read_long_long(&str, long_long_arg);
                        count++;
                    }
                }
                break;
            }
            case 'u': {
                unsigned int *uint_arg = va_arg(args, unsigned int *);
                read_unsigned(&str, uint_arg);
                count++;
                break;
            }
            case 'x': {
                unsigned int *hex_arg = va_arg(args, unsigned int *);
                read_hexa(&str, hex_arg);
                count++;
                break;
            }
            case 'p': {
                void **ptr_arg = va_arg(args, void **);
                read_ptr(&str, ptr_arg);
                count++;
                break;
            }
            case 'c': {
                char *char_arg = va_arg(args, char *);
                read_char(&str, char_arg);
                count++;
                break;
            }
            case 'b': {
                bool *bool_arg = va_arg(args, bool *);
                read_bool(&str, bool_arg);
                count++;
                break;
            }
            case 'n': {
                void **null_arg = va_arg(args, void **);
                read_null(&str, null_arg);
                count++;
                break;
            }
                // Add other cases here
            }
        } else {
            if (*str == *format) {
                str++;
            }
            format++;
        }
    }

    va_end(args);
    return count;
}