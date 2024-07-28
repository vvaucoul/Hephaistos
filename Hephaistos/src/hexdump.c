/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:15:55 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 02:04:05 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory.h>
#include <stdio.h>

void khexdump(uint32_t ebp, int limit) {
    int i = 0;

    if (limit <= 0)
        return;
    do {
        printk(ebp == 0x00000800 ? _GREEN : _CYAN);
        printk("0x%08X: ", ebp);

        uint32_t next = ebp + 16;
        uint32_t tmp = ebp;
        for (; tmp < next && i < limit; ++tmp, ++i) {
            if (*((char *)&tmp) >= 32)
                printk(_GREEN "%02X " _END, *(uint8_t *)(&tmp));
            else
                printk(_END "00 " _END);
        }

        next = ebp + 16;
        tmp = ebp;
        for (; tmp < next && i < limit; ++tmp, ++i) {
            if (*((char *)&tmp) > 32)
                printk("%c", *((char *)&tmp));
            else
                printk(".");
        }
        printk("\n");
        ebp += 16;
    } while (i < limit);
}
