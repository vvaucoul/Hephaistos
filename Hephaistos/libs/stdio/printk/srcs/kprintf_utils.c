/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kprintf_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:11:35 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/20 18:41:48 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libs/stdio/printk/printk.h>

size_t __kptrlen(const void *ptr)
{
    size_t len = 0;
    unsigned char *p = (unsigned char *)ptr;
    
    if (ptr == NULL)
        return (0);
    while (*p)
    {
        len++;
        p++;
    }
    return len;
}