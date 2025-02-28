/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printk_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:11:35 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/10/19 19:05:34 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio/printk.h>

uint32_t __kptrlen(const void *ptr) {
	if (ptr == NULL)
		return 0;

	uint32_t len = 0;
	const unsigned char *p = (const unsigned char *)ptr;

	while (*p) {
		len++;
		p++;
	}
	return len;
}

uint32_t __k_get_len(uint32_t arg_len) {
	uint32_t precision = _g_printk.precision < 0 ? 0 : _g_printk.precision;
	uint32_t space = _g_printk.space;

	// Use the larger of arg_len and precision
	arg_len = arg_len > precision ? arg_len : precision;

	// If space is specified and is larger, use space
	return space > arg_len ? space : arg_len;
}