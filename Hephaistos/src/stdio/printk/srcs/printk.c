/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:06:11 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/10/26 11:14:16 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <ctype.h>
#include <stdio.h>
#include <stdio/printk.h>
#include <string.h>

printk_t _g_printk = {0}; // Initialize all members to 0

static int check_special_strings(const char *str) {
	if (strncmp(str, _CURSOR_MOVE_UP, strlen(_CURSOR_MOVE_UP)) == 0) {
		tty_move_cursor_up();
		return (strlen(_CURSOR_MOVE_UP));
	}
	return (0);
}

// Use an array to store color codes and their corresponding lengths
static const char *color_codes[] = {
	_END, _RED, _GREEN, _BLUE, _YELLOW, _MAGENTA, _CYAN, _LGREY, _LBLUE,
	_LGREEN, _LCYAN, _LRED, _LMAGENTA, _LYELLOW, _WHITE, _BG_BLACK,
	_BG_BLUE, _BG_GREEN, _BG_CYAN, _BG_RED, _BG_MAGENTA, _BG_YELLOW,
	_BG_LGREY, _BG_LBLUE, _BG_LGREEN, _BG_LCYAN, _BG_LRED, _BG_LMAGENTA,
	_BG_LYELLOW, _BG_WHITE};

static const int color_code_lengths[] = {
	__C_SRLEN(_END), __C_SRLEN(_RED), __C_SRLEN(_GREEN), __C_SRLEN(_BLUE), __C_SRLEN(_YELLOW),
	__C_SRLEN(_MAGENTA), __C_SRLEN(_CYAN), __C_SRLEN(_LGREY), __C_SRLEN(_LBLUE),
	__C_SRLEN(_LGREEN), __C_SRLEN(_LCYAN), __C_SRLEN(_LRED), __C_SRLEN(_LMAGENTA),
	__C_SRLEN(_LYELLOW), __C_SRLEN(_WHITE), __C_SRLEN(_BG_BLACK), __C_SRLEN(_BG_BLUE),
	__C_SRLEN(_BG_GREEN), __C_SRLEN(_BG_CYAN), __C_SRLEN(_BG_RED), __C_SRLEN(_BG_MAGENTA),
	__C_SRLEN(_BG_YELLOW), __C_SRLEN(_BG_LGREY), __C_SRLEN(_BG_LBLUE), __C_SRLEN(_BG_LGREEN),
	__C_SRLEN(_BG_LCYAN), __C_SRLEN(_BG_LRED), __C_SRLEN(_BG_LMAGENTA), __C_SRLEN(_BG_LYELLOW),
	__C_SRLEN(_BG_WHITE)};

static int check_colors(const char *str) {
	for (size_t i = 0; i < sizeof(color_codes) / sizeof(color_codes[0]); ++i) {
		if (strncmp(str, color_codes[i], color_code_lengths[i]) == 0) {
			switch (i) {
				case 0:
					tty_setcolor(VGA_COLOR_LIGHT_GREY);
					tty_set_background_color(VGA_COLOR_BLACK);
					break;
				case 1: tty_setcolor(VGA_COLOR_RED); break;
				case 2: tty_setcolor(VGA_COLOR_GREEN); break;
				case 3: tty_setcolor(VGA_COLOR_BLUE); break;
				case 4: tty_setcolor(VGA_COLOR_BROWN); break;
				case 5: tty_setcolor(VGA_COLOR_MAGENTA); break;
				case 6: tty_setcolor(VGA_COLOR_CYAN); break;
				case 7: tty_setcolor(VGA_COLOR_LIGHT_GREY); break;
				case 8: tty_setcolor(VGA_COLOR_LIGHT_BLUE); break;
				case 9: tty_setcolor(VGA_COLOR_LIGHT_GREEN); break;
				case 10: tty_setcolor(VGA_COLOR_LIGHT_CYAN); break;
				case 11: tty_setcolor(VGA_COLOR_LIGHT_RED); break;
				case 12: tty_setcolor(VGA_COLOR_LIGHT_MAGENTA); break;
				case 13: tty_setcolor(VGA_COLOR_LIGHT_BROWN); break;
				case 14: tty_setcolor(VGA_COLOR_WHITE); break;
				case 15: tty_set_background_color(VGA_COLOR_BLACK); break;
				case 16: tty_set_background_color(VGA_COLOR_BLUE); break;
				case 17: tty_set_background_color(VGA_COLOR_GREEN); break;
				case 18: tty_set_background_color(VGA_COLOR_CYAN); break;
				case 19: tty_set_background_color(VGA_COLOR_RED); break;
				case 20: tty_set_background_color(VGA_COLOR_MAGENTA); break;
				case 21: tty_set_background_color(VGA_COLOR_BROWN); break;
				case 22: tty_set_background_color(VGA_COLOR_LIGHT_GREY); break;
				case 23: tty_set_background_color(VGA_COLOR_LIGHT_BLUE); break;
				case 24: tty_set_background_color(VGA_COLOR_LIGHT_GREEN); break;
				case 25: tty_set_background_color(VGA_COLOR_LIGHT_CYAN); break;
				case 26: tty_set_background_color(VGA_COLOR_LIGHT_RED); break;
				case 27: tty_set_background_color(VGA_COLOR_LIGHT_MAGENTA); break;
				case 28: tty_set_background_color(VGA_COLOR_LIGHT_BROWN); break;
				case 29: tty_set_background_color(VGA_COLOR_WHITE); break;
				default:
					// Handle unexpected cases
					return 0;
			}
			return (color_code_lengths[i]);
		}
	}
	return (0);
}

static int kprint_mod(const char *format, uint32_t i) {
	_g_printk.is_neg_space = (format[i] == __SPE_NEG);
	if (_g_printk.is_neg_space) {
		++i;
	}

	_g_printk.use_zero = (format[i] == __SPE_ZERO);
	if (_g_printk.use_zero) {
		++i;
	}

	_g_printk.space = 0;
	while (isdigit(format[i])) {
		_g_printk.space = _g_printk.space * 10 + (format[i] - 0x30);
		i++;
	}

	_g_printk.precision = -1;
	if (format[i] == __SPE_DOT) {
		i++;
		if (format[i] == __SPE_STAR) {
			_g_printk.precision = va_arg(_g_printk.args, int);
			i++;
		} else {
			_g_printk.precision = 0;
			while (isdigit(format[i])) {
				_g_printk.precision = _g_printk.precision * 10 + (format[i] - 0x30);
				i++;
			}
		}
	}

	// Use a switch statement instead of if-else chain
	switch (format[i]) {
		case __DEL_MOD:
			i = __kpf_manage_mod(format, i);
			break;
		case __DEL_C:
			__kpf_manage_char();
			break;
		case __DEL_D:
		case __DEL_I:
			__kpf_manage_nbr();
			break;
		case __DEL_S:
			__kpf_manage_str();
			break;
		case __DEL_P:
			__kpf_manage_ptr();
			break;
		case __DEL_U:
			__kpf_manage_unsigned();
			break;
		case __DEL_X:
			__kpf_manage_hexa();
			break;
		case __DEL_F:
			__kpf_manage_float();
			break;
		case 'l':
			switch (format[++i]) {
				case 'l':
					switch (format[++i]) {
						case 'x':
							__kpf_manage_long_long_hexa();
							break;
						case 'u':
							__kpf_manage_long_long_unsigned();
							break;
						case 'd':
							__kpf_manage_long_long_nbr();
							break;
						default:
							// Handle unexpected cases
							return i;
					}
					break;
				case 'd':
					__kpf_manage_long_nbr();
					break;
				case 'x':
					__kpf_manage_long_hexa();
					break;
				default:
					// Handle unexpected cases
					return i;
			}
			break;
		default:
			// Handle unexpected cases
			return i;
	}
	return (i);
}

static int printk_loop(const char *format) {
	uint32_t i = 0;
	int ret = 0;

	while (format[i]) {
		if ((ret = check_colors(format + i)) != 0) {
			i += ret;
			continue;
		} else if ((ret = check_special_strings(format + i)) != 0) {
			i += ret;
			continue;
		}

		if (format[i] == __DEL_MOD) {
			i++;
			i = kprint_mod(format, i);
		} else {
			tty_putchar(format[i]);
		}
		++i;
	}
	return (ret);
}

uint32_t printk(const char *format, ...) {
	strncpy(_g_printk.format, format, sizeof(_g_printk.format) - 1);
	_g_printk.format[sizeof(_g_printk.format) - 1] = '\0';

	va_start(_g_printk.args, format);
	int ret = printk_loop(format);
	va_end(_g_printk.args);

	tty_refresh_cursor();
	return (ret);
}
