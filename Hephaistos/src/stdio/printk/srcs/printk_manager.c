/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printk_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:54:20 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/31 02:08:01 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <stdio.h>
#include <stdio/printk.h>
#include <string.h>

uint32_t __kpf_manage_mod(const char *format, uint32_t i) {
	__kpf_manage_space_front(1);
	--i;
	if (format[i + 1] != __DEL_MOD)
		putchar(__DEL_MOD);
	++i;
	__kpf_manage_space_back(1);
	return (i);
}

void __kpf_manage_char() {
	char c = va_arg(_g_printk.args, int);

	__kpf_manage_space_front(1);
	putchar(c);
	__kpf_manage_space_back(1);
}

void __kpf_manage_nbr() {
	int nbr = va_arg(_g_printk.args, int);
	uint32_t len = (uint32_t)(_g_printk.precision < 0 ? nbrlen(nbr) : (uint32_t)_g_printk.precision);

	__kpf_manage_space_front(len);
	putnbr_len(nbr, len);
	__kpf_manage_space_back(len);
}

void __kpf_manage_str() {
	char *str = va_arg(_g_printk.args, char *);
	uint32_t len = (uint32_t)(_g_printk.precision < 0 ? strlen(str) : (uint32_t)_g_printk.precision);

	if (str == NULL) {
		char __str[7];

		bzero(__str, 7);
		memcpy(__str, "(null)", 6);
		__kpf_manage_space_front(strlen(__str));
		putstr(__str);
		__kpf_manage_space_back(strlen(__str));
	} else {
		__kpf_manage_space_front(len);
		putstr_len(str, len);
		__kpf_manage_space_back(len);
	}
}

void __kpf_manage_ptr() {
	void *ptr = va_arg(_g_printk.args, void *);
	uint32_t len = (uint32_t)(_g_printk.precision < 0 ? __kptrlen(ptr) : (uint32_t)_g_printk.precision);

	__kpf_manage_space_front(len);
	putptr_len(ptr, len);
	__kpf_manage_space_back(len);
}

void __kpf_manage_hexa() {
	uint32_t nbr = va_arg(_g_printk.args, uint32_t);
	uint32_t len = (uint32_t)(_g_printk.precision < 0 ? nbrlen_base(nbr, 16) : (uint32_t)_g_printk.precision);

	__kpf_manage_space_front(len);
	putunbr_hex_len(nbr, len);
	__kpf_manage_space_back(len);
}

void __kpf_manage_unsigned() {
	uint64_t nbr = va_arg(_g_printk.args, uint64_t);
	uint64_t len = (uint64_t)(_g_printk.precision < 0 ? nbrlen(nbr) : (uint32_t)_g_printk.precision);

	__kpf_manage_space_front(len);
	putunbr_len(nbr, len);
	__kpf_manage_space_back(len);
}

void __kpf_manage_float() {
	double nbr = va_arg(_g_printk.args, double);
	uint32_t len = (uint32_t)(_g_printk.precision < 0 ? nbrlen(nbr) : (uint32_t)_g_printk.precision);

	__kpf_manage_space_front(len);
	putf_len(nbr, len);
	__kpf_manage_space_back(len);
}

void __kpf_manage_long_hexa() {
	unsigned long nbr = va_arg(_g_printk.args, unsigned long);
	uint32_t len = (uint32_t)(_g_printk.precision < 0 ? nbrlen_base(nbr, 16) : (uint32_t)_g_printk.precision);

	__kpf_manage_space_front(len);
	putunbr_hex_len(nbr, len);
	__kpf_manage_space_back(len);
}

void __kpf_manage_long_long_hexa() {
	unsigned long long nbr = va_arg(_g_printk.args, unsigned long long);
	uint32_t len = (uint32_t)(_g_printk.precision < 0 ? nbrlen_base(nbr, 16) : (uint32_t)_g_printk.precision);

	__kpf_manage_space_front(len);
	putunbr_hex_len(nbr, len);
	__kpf_manage_space_back(len);
}

void __kpf_manage_long_long_unsigned() {
	unsigned long long nbr = va_arg(_g_printk.args, unsigned long long);
	uint64_t len = (uint64_t)(_g_printk.precision < 0 ? nbrlen(nbr) : (uint32_t)_g_printk.precision);

	__kpf_manage_space_front(len);
	putunbr_len(nbr, len);
	__kpf_manage_space_back(len);
}

void __kpf_manage_long_long_nbr() {
	long long nbr = va_arg(_g_printk.args, long long);
	uint64_t len = (uint64_t)(_g_printk.precision < 0 ? nbrlen(nbr) : (uint32_t)_g_printk.precision);

	__kpf_manage_space_front(len);
	putnbr_len(nbr, len);
	__kpf_manage_space_back(len);
}

void __kpf_manage_long_nbr() {
	long nbr = va_arg(_g_printk.args, long);
	uint32_t len = (uint32_t)(_g_printk.precision < 0 ? nbrlen(nbr) : (uint32_t)_g_printk.precision);

	__kpf_manage_space_front(len);
	putnbr_len(nbr, len);
	__kpf_manage_space_back(len);
}