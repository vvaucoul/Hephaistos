/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snprintk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 23:57:52 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 11:23:36 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <convert.h>
#include <stdarg.h>
#include <stdio/snprintk.h>

int snprintk(char *str, uint32_t size, const char *format, ...) {
	if (str == NULL || format == NULL || size == 0) {
		return -1; // Gestion des erreurs
	}

	va_list args;
	size_t i = 0;
	const char *p;
	char *s;
	int d;
	double f;
	char buffer[64] = {0};

	va_start(args, format);

	for (p = format; *p != '\0' && i < size - 1; p++) {
		if (*p != '%') {
			str[i++] = *p;
			continue;
		}

		p++;
		switch (*p) {
		case 's':
			s = va_arg(args, char *);
			if (s == NULL)
				s = "(null)";
			while (*s && i < size - 1) {
				str[i++] = *s++;
			}
			break;

		case 'd':
			d = va_arg(args, int);
			itoa(d, buffer);
			s = buffer;
			while (*s && i < size - 1) {
				str[i++] = *s++;
			}
			break;

		case 'u':
			va_arg(args, unsigned int);
			// utoa(u, buffer);
			s = buffer;
			while (*s && i < size - 1) {
				str[i++] = *s++;
			}
			break;

		case 'x':
			va_arg(args, unsigned int);
			// xtoa(u, buffer);
			s = buffer;
			while (*s && i < size - 1) {
				str[i++] = *s++;
			}
			break;

		case 'f':
			f = va_arg(args, double);
			s = ftoa(f, 6);
			while (*s && i < size - 1) {
				str[i++] = *s++;
			}
			break;

		case 'c':
			d = va_arg(args, int);
			if (i < size - 1) {
				str[i++] = (char)d;
			}
			break;

		default:
			str[i++] = '%';
			if (i < size - 1) {
				str[i++] = *p;
			}
			break;
		}
	}

	str[i] = '\0';
	va_end(args);
	return i;
}