/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:15:55 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/22 13:16:20 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include <libs/stdio/stdio.h>

void khexdump(uint32_t ebp, int limit)
{
    int i = 0;

    if (limit <= 0)
        return;
    do
    {
        printk(ebp == 0x00000800 ? _GREEN : _CYAN);
        printk("0x%u: " _END, ebp);

        uint32_t next = ebp + 16;
        uint32_t tmp = ebp;
        while (tmp < next && i < limit)
        {
            if (*(char *)tmp >= 32)
                printk(_GREEN "%u " _END, *(char *)tmp);
            else
                printk(_END "00 " _END);
            ++tmp;
        }

        next = ebp + 16;
        tmp = ebp;
        while (tmp < next && i < limit)
        {
            if (*(char *)tmp > 32)
                printk("%c", *(char *)tmp);
            else
                printk(".");
            ++tmp;
        }
        printk("\n");
        i += 16;
        ebp += 16;
    } while (i < limit);
}