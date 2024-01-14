/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compares.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:08:11 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/14 13:58:15 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <libs/string/string.h>

// ! ||--------------------------------------------------------------------------------||
// ! ||                                COMPARE FUNCTIONS                               ||
// ! ||--------------------------------------------------------------------------------||

int cmp_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int cmp_string(const void *a, const void *b) {
    return (strcmp((char *)a, (char *)b));
}

int cmp_char(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int cmp_int8_t(const void *a, const void *b) {
    return (*(int8_t *)a - *(int8_t *)b);
}

int cmp_int16_t(const void *a, const void *b) {
    return (*(int16_t *)a - *(int16_t *)b);
}

int cmp_int32_t(const void *a, const void *b) {
    return (*(int32_t *)a - *(int32_t *)b);
}

int cmp_int64_t(const void *a, const void *b) {
    return (*(int64_t *)a > *(int64_t *)b) - (*(int64_t *)a < *(int64_t *)b);
}

int cmp_uint8_t(const void *a, const void *b) {
    return (*(uint8_t *)a - *(uint8_t *)b);
}

int cmp_uint16_t(const void *a, const void *b) {
    return (*(uint16_t *)a - *(uint16_t *)b);
}

int cmp_uint32_t(const void *a, const void *b) {
    return (*(uint32_t *)a - *(uint32_t *)b);
}

int cmp_uint64_t(const void *a, const void *b) {
    return (*(uint64_t *)a > *(uint64_t *)b) - (*(uint64_t *)a < *(uint64_t *)b);
}

int cmp_float(const void *a, const void *b) {
    return (*(float *)a > *(float *)b) - (*(float *)a < *(float *)b);
}

int cmp_double(const void *a, const void *b) {
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}
