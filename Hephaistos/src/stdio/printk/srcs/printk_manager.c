/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printk_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:54:20 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/10/26 11:22:09 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <stdio.h>
#include <stdio/printk.h>
#include <string.h>

// Fonction générique pour gérer l'affichage des nombres (décimaux, hexadécimaux, etc.)
static void __kpf_manage_number(long long nbr, int base, bool is_signed) {
	uint32_t precision = _g_printk.precision < 0 ? (is_signed ? nbrlen(nbr) : nbrlen_base(nbr, base)) : (uint32_t)_g_printk.precision;

	__kpf_manage_spaces(precision);
	if (is_signed) {
		putnbr_len(nbr, precision);
	} else {
		putunbr_hex_len(nbr, precision);
	}
}

uint32_t __kpf_manage_mod(const char *format, uint32_t i) {
	__kpf_manage_spaces(1);
	--i;
	if (format[i + 1] != __DEL_MOD)
		putchar(__DEL_MOD);
	++i;
	return (i);
}

void __kpf_manage_char() {
	char c = va_arg(_g_printk.args, int);
	__kpf_manage_spaces(1);
	putchar(c);
}

void __kpf_manage_nbr() {
	__kpf_manage_number(va_arg(_g_printk.args, int), 10, true);
}

void __kpf_manage_str() {
	char *str = va_arg(_g_printk.args, char *);
	const char *to_print = str ? str : "(null)";
	uint32_t precision = _g_printk.precision < 0 ? strlen(to_print) : (uint32_t)_g_printk.precision;

	__kpf_manage_spaces(precision);
	putstr_len(to_print, precision);
}

void __kpf_manage_ptr() {
	// void *ptr = va_arg(_g_printk.args, void *);
	// uint32_t precision = _g_printk.precision < 0 ? __kptrlen(ptr) : (uint32_t)_g_printk.precision;

	// __kpf_manage_spaces(precision);
	// putptr_len(ptr, precision);

	void *ptr = va_arg(_g_printk.args, void *);

	__kpf_manage_spaces(2);
	putptr_len(ptr, 8);
}

void __kpf_manage_hexa() {
	__kpf_manage_number(va_arg(_g_printk.args, uint32_t), 16, false);
}

void __kpf_manage_unsigned() {
	__kpf_manage_number(va_arg(_g_printk.args, uint64_t), 10, false);
}

void __kpf_manage_float() {
	double nbr = va_arg(_g_printk.args, double);
	uint32_t precision = _g_printk.precision < 0 ? nbrlen(nbr) : (uint32_t)_g_printk.precision;

	__kpf_manage_spaces(precision);
	putf_len(nbr, precision);
}

void __kpf_manage_long_hexa() {
	__kpf_manage_number(va_arg(_g_printk.args, unsigned long), 16, false);
}

void __kpf_manage_long_long_hexa() {
	__kpf_manage_number(va_arg(_g_printk.args, unsigned long long), 16, false);
}

void __kpf_manage_long_long_unsigned() {
	__kpf_manage_number(va_arg(_g_printk.args, unsigned long long), 10, false);
}

void __kpf_manage_long_long_nbr() {
	__kpf_manage_number(va_arg(_g_printk.args, long long), 10, true);
}

void __kpf_manage_long_nbr() {
	__kpf_manage_number(va_arg(_g_printk.args, long), 10, true);
}