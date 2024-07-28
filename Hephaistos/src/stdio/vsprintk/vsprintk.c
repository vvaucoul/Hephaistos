/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsprintk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 09:56:43 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 10:11:06 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <stdio/vsprintk.h>

extern printk_t _g_printk;

static char *buffer_ptr;

static void buffer_putchar(char c) {
	*buffer_ptr++ = c;
}

static void buffer_putstr(const char *str) {
	while (*str) {
		buffer_putchar(*str++);
	}
}

static void buffer_putnbr(int nbr) {
	if (nbr == 0) {
		buffer_putchar('0');
		return;
	}
	if (nbr < 0) {
		buffer_putchar('-');
		nbr = -nbr;
	}
	char buffer[20];
	int i = 0;
	while (nbr) {
		buffer[i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	while (i > 0) {
		buffer_putchar(buffer[--i]);
	}
}

static void buffer_putunbr(unsigned int nbr) {
	if (nbr == 0) {
		buffer_putchar('0');
		return;
	}
	char buffer[20];
	int i = 0;
	while (nbr) {
		buffer[i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	while (i > 0) {
		buffer_putchar(buffer[--i]);
	}
}

// int vprintf(const char *format, va_list ap) {

// }

// int vfprintf(FILE *stream, const char *format, va_list ap) {
// }

// int vdprintf(int fd, const char *format, va_list ap) {
// }

int vsprintk(char *str, const char *format, va_list args) {
	buffer_ptr = str;

	while (*format) {
		if (*format == '%') {
			format++;
			if (*format == 'd' || *format == 'i') {
				int num = va_arg(args, int);
				buffer_putnbr(num);
			} else if (*format == 'u') {
				unsigned int num = va_arg(args, unsigned int);
				buffer_putunbr(num);
			} else if (*format == 's') {
				char *s = va_arg(args, char *);
				buffer_putstr(s);
			} else if (*format == 'c') {
				char c = (char)va_arg(args, int);
				buffer_putchar(c);
			} else if (*format == 'x') {
				unsigned int num = va_arg(args, unsigned int);
				char buffer[20];
				int i = 0;
				if (num == 0) {
					buffer_putchar('0');
				} else {
					while (num) {
						int digit = num % 16;
						buffer[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'a';
						num /= 16;
					}
					while (i > 0) {
						buffer_putchar(buffer[--i]);
					}
				}
			} else if (*format == 'p') {
				void *ptr = va_arg(args, void *);
				buffer_putstr("0x");
				unsigned long addr = (unsigned long)ptr;
				char buffer[20];
				int i = 0;
				if (addr == 0) {
					buffer_putchar('0');
				} else {
					while (addr) {
						int digit = addr % 16;
						buffer[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'a';
						addr /= 16;
					}
					while (i > 0) {
						buffer_putchar(buffer[--i]);
					}
				}
			} else if (*format == '%') {
				buffer_putchar('%');
			}
			format++;
		} else {
			buffer_putchar(*format++);
		}
	}

	buffer_putchar('\0');
	return buffer_ptr - str - 1;
}

// int vsnprintf(char *str, size_t size, const char *format, va_list ap) {
// }