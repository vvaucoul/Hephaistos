/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printk_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:11:35 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/31 02:05:22 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio/printk.h>

uint32_t __kptrlen(const void *ptr) {
    uint32_t len = 0;
    unsigned char *p = (unsigned char *)ptr;

    if (ptr == NULL)
        return (0);
    while (*p) {
        len++;
        p++;
    }
    return len;
}

//Todo: Fix this function
uint32_t __k_get_len(uint32_t arg_len) {
    uint32_t precision = _g_printk.precision;
    uint32_t space = _g_printk.space;

    // If precision is specified and is greater than the length of the argument,
    // use precision as the length of the display.
    if (arg_len < precision) {
        arg_len = precision;
    }

    // If space (field width) is specified and is greater than both
    // the length of the argument and the precision, use space as the length of the display.
    if (space > 0 && space > arg_len) {
        return space;
    }

    // Otherwise, return the length calculated from the argument and precision.
    return arg_len;
}