/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:06:11 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 01:41:00 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <ctype.h>
#include <stdio.h>
#include <stdio/printk.h>
#include <string.h>

printk_t _g_printk = {
    .format = {0},
    .space = 0,
    .space_is_star = false,
    .is_neg_space = false,
    .use_zero = false,
    .precision = -1,
};

static int check_special_strings(const char *str) {
	if (strncmp(str, _CURSOR_MOVE_UP, strlen(_CURSOR_MOVE_UP)) == 0) {
		terminal_move_cursor_up();
		return (strlen(_CURSOR_MOVE_UP));
	}
	return (0);
}

static int check_colors(const char *str) {
	/* Check Foreground colors */
	if (strncmp(str, _END, strlen(_END)) == 0) {
		terminal_set_color(VGA_COLOR_LIGHT_GREY);
		terminal_set_background_color(VGA_COLOR_BLACK);
		return (strlen(_END));
	} else if (strncmp(str, _RED, strlen(_RED)) == 0) {
		terminal_set_color(VGA_COLOR_RED);
		return (strlen(_RED));
	} else if (strncmp(str, _GREEN, strlen(_GREEN)) == 0) {
		terminal_set_color(VGA_COLOR_GREEN);
		return (strlen(_GREEN));
	} else if (strncmp(str, _BLUE, strlen(_BLUE)) == 0) {
		terminal_set_color(VGA_COLOR_BLUE);
		return (strlen(_BLUE));
	} else if (strncmp(str, _YELLOW, strlen(_YELLOW)) == 0) {
		terminal_set_color(VGA_COLOR_BROWN);
		return (strlen(_YELLOW));
	} else if (strncmp(str, _MAGENTA, strlen(_MAGENTA)) == 0) {
		terminal_set_color(VGA_COLOR_MAGENTA);
		return (strlen(_MAGENTA));
	} else if (strncmp(str, _CYAN, strlen(_CYAN)) == 0) {
		terminal_set_color(VGA_COLOR_CYAN);
		return (strlen(_CYAN));
	} else if (strncmp(str, _LGREY, strlen(_LGREY)) == 0) {
		terminal_set_color(VGA_COLOR_LIGHT_GREY);
		return (strlen(_LGREY));
	} else if (strncmp(str, _LBLUE, strlen(_LBLUE)) == 0) {
		terminal_set_color(VGA_COLOR_LIGHT_BLUE);
		return (strlen(_LBLUE));
	} else if (strncmp(str, _LGREEN, strlen(_LGREEN)) == 0) {
		terminal_set_color(VGA_COLOR_LIGHT_GREEN);
		return (strlen(_LGREEN));
	} else if (strncmp(str, _LCYAN, strlen(_LCYAN)) == 0) {
		terminal_set_color(VGA_COLOR_LIGHT_CYAN);
		return (strlen(_LCYAN));
	} else if (strncmp(str, _LRED, strlen(_LRED)) == 0) {
		terminal_set_color(VGA_COLOR_LIGHT_RED);
		return (strlen(_LRED));
	} else if (strncmp(str, _LMAGENTA, strlen(_LMAGENTA)) == 0) {
		terminal_set_color(VGA_COLOR_LIGHT_MAGENTA);
		return (strlen(_LMAGENTA));
	} else if (strncmp(str, _LYELLOW, strlen(_LYELLOW)) == 0) {
		terminal_set_color(VGA_COLOR_LIGHT_BROWN);
		return (strlen(_LYELLOW));
	} else if (strncmp(str, _WHITE, strlen(_WHITE)) == 0) {
		terminal_set_color(VGA_COLOR_WHITE);
		return (strlen(_WHITE));
	}

	/* Check Background colors */
	if (strncmp(str, _BG_BLACK, strlen(_BG_BLACK)) == 0) {
		terminal_set_background_color(VGA_COLOR_BLACK);
		return (strlen(_BG_BLACK));
	} else if (strncmp(str, _BG_BLUE, strlen(_BG_BLUE)) == 0) {
		terminal_set_background_color(VGA_COLOR_BLUE);
		return (strlen(_BG_BLUE));
	} else if (strncmp(str, _BG_GREEN, strlen(_BG_GREEN)) == 0) {
		terminal_set_background_color(VGA_COLOR_GREEN);
		return (strlen(_BG_GREEN));
	} else if (strncmp(str, _BG_CYAN, strlen(_BG_CYAN)) == 0) {
		terminal_set_background_color(VGA_COLOR_CYAN);
		return (strlen(_BG_CYAN));
	} else if (strncmp(str, _BG_RED, strlen(_BG_RED)) == 0) {
		terminal_set_background_color(VGA_COLOR_RED);
		return (strlen(_BG_RED));
	} else if (strncmp(str, _BG_MAGENTA, strlen(_BG_MAGENTA)) == 0) {
		terminal_set_background_color(VGA_COLOR_MAGENTA);
		return (strlen(_BG_MAGENTA));
	} else if (strncmp(str, _BG_YELLOW, strlen(_BG_YELLOW)) == 0) {
		terminal_set_background_color(VGA_COLOR_BROWN);
		return (strlen(_BG_YELLOW));
	} else if (strncmp(str, _BG_LGREY, strlen(_BG_LGREY)) == 0) {
		terminal_set_background_color(VGA_COLOR_LIGHT_GREY);
		return (strlen(_BG_LGREY));
	} else if (strncmp(str, _BG_LBLUE, strlen(_BG_LBLUE)) == 0) {
		terminal_set_background_color(VGA_COLOR_LIGHT_BLUE);
		return (strlen(_BG_LBLUE));
	} else if (strncmp(str, _BG_LGREEN, strlen(_BG_LGREEN)) == 0) {
		terminal_set_background_color(VGA_COLOR_LIGHT_GREEN);
		return (strlen(_BG_LGREEN));
	} else if (strncmp(str, _BG_LCYAN, strlen(_BG_LCYAN)) == 0) {
		terminal_set_background_color(VGA_COLOR_LIGHT_CYAN);
		return (strlen(_BG_LCYAN));
	} else if (strncmp(str, _BG_LRED, strlen(_BG_LRED)) == 0) {
		terminal_set_background_color(VGA_COLOR_LIGHT_RED);
		return (strlen(_BG_LRED));
	} else if (strncmp(str, _BG_LMAGENTA, strlen(_BG_LMAGENTA)) == 0) {
		terminal_set_background_color(VGA_COLOR_LIGHT_MAGENTA);
		return (strlen(_BG_LMAGENTA));
	} else if (strncmp(str, _BG_LYELLOW, strlen(_BG_LYELLOW)) == 0) {
		terminal_set_background_color(VGA_COLOR_LIGHT_BROWN);
		return (strlen(_BG_LYELLOW));
	} else if (strncmp(str, _BG_WHITE, strlen(_BG_WHITE)) == 0) {
		terminal_set_background_color(VGA_COLOR_WHITE);
		return (strlen(_BG_WHITE));
	}

	return (0);
}

static int kprint_mod(const char *format, uint32_t i) {

	/* CHECK SPECIAL DELIMITERS */

	// SPACES
	if (format[i] == __SPE_NEG) {
		_g_printk.is_neg_space = true;
		++i;
	} else
		_g_printk.is_neg_space = false;

	if (format[i] == __SPE_ZERO) {
		_g_printk.use_zero = true;
		++i;
	} else
		_g_printk.use_zero = false;

	int nbr = 0;
	while (isdigit(format[i])) {
		nbr = nbr * 10 + (format[i] - 0x30);
		i++;
	}
	_g_printk.space = nbr;

	if (format[i] == __SPE_DOT) {
		// Skip dot
		i++;
		int precision = 0;

		if (format[i] == __SPE_STAR) {
			_g_printk.precision = va_arg(_g_printk.args, int);
			i++;
		} else {
			while (isdigit(format[i])) {
				precision = precision * 10 + (format[i] - 0x30);
				i++;
			}
			_g_printk.precision = precision;
		}
	} else {
		_g_printk.precision = -1;
	}

	/* CHECK BASIC DELIMITERS */

	if (format[i] == __DEL_MOD)
		i = __kpf_manage_mod(format, i);
	else if (format[i] == __DEL_C)
		__kpf_manage_char();
	else if (format[i] == __DEL_D || format[i] == __DEL_I)
		__kpf_manage_nbr();
	else if (format[i] == __DEL_S)
		__kpf_manage_str();
	else if (format[i] == __DEL_P)
		__kpf_manage_ptr();
	else if (format[i] == __DEL_U)
		__kpf_manage_unsigned();
	else if (format[i] == __DEL_X)
		__kpf_manage_hexa();
	else if (format[i] == __DEL_F)
		__kpf_manage_float();
	return (i);
}

static int kprintf_loop(const char *format) {
	uint32_t i = 0;
	int ret = 0;

	while (format[i]) {
		if ((ret = (check_colors(format + i))) != 0) {
			i += ret;
			continue;
		} else if ((ret = (check_special_strings(format + i))) != 0) {
			i += ret;
			continue;
		} else {
			ret = 0;
		}
		if (format[i] == __DEL_MOD) {
			i++;
			i = kprint_mod(format, i);
		} else {
			terminal_putchar(format[i]);
		}
		++i;
	}
	return (ret);
}

uint32_t printk(const char *format, ...) {
	int ret;

	// Clear previous format string
	memset(_g_printk.format, 0, sizeof(_g_printk.format));
	memcpy(_g_printk.format, format, strlen(format));

	_g_printk.space = 0;
	_g_printk.space_is_star = false;

	_g_printk.is_neg_space = false;
	_g_printk.use_zero = false;

	_g_printk.precision = -1;

	va_start(_g_printk.args, format);
	ret = kprintf_loop(format);
	va_end(_g_printk.args);

	refresh_cursor();
	return (ret);
}