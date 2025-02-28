/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printk_special_manager.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:59:37 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/10/19 19:10:02 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdio/printk.h>

// Fonctions d'assistance pour gérer les espaces
static void print_spaces(int count, char c) {
	for (int i = 0; i < count; i++) {
		putchar(c);
	}
}

void __kpf_manage_space_front(uint32_t arg_len) {
	if (arg_len > (uint32_t)_g_printk.space) {
		return;
	}
	int space_count = _g_printk.space - arg_len;
	if (space_count > 0 && !_g_printk.is_neg_space) {
		print_spaces(space_count, _g_printk.use_zero ? '0' : ' ');
		_g_printk.space = 0;
	}
}

void __kpf_manage_space_back(uint32_t arg_len) {
	if (arg_len > (uint32_t)_g_printk.space) {
		return;
	}
	int space_count = _g_printk.space - arg_len;
	if (space_count > 0 && _g_printk.is_neg_space) {
		print_spaces(space_count, _g_printk.use_zero ? '0' : ' ');
		_g_printk.space = 0;
	}
}

void __kpf_manage_spaces(uint32_t arg_len) {
	int space_count = _g_printk.space - arg_len;
	if (space_count > 0) {
		char c = _g_printk.use_zero ? '0' : ' ';
		if (!_g_printk.is_neg_space) {
			print_spaces(space_count, c);
		}
		// ... (L'argument sera affiché ici par la fonction appelante) ...
		if (_g_printk.is_neg_space) {
			print_spaces(space_count, c);
		}
		_g_printk.space = 0; // Réinitialiser l'espace après utilisation
	}
}