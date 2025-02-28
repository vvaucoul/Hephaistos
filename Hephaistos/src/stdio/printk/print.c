/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:19:39 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/10/26 11:21:59 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <convert.h>
#include <macros.h>
#include <stdio.h>
#include <string.h>

// ! ||--------------------------------------------------------------------------------||
// ! ||                              BASIC PRINT FUNCTIONS                             ||
// ! ||--------------------------------------------------------------------------------||

/**
 * @brief Outputs a character to the terminal.
 *
 * @param c Character to output.
 */
void putchar(char c) {
	tty_putchar(c);
}

/**
 * @brief Outputs a string to the terminal.
 *
 * @param str Null-terminated string to output.
 */
void putstr(const char *str) {
	while (*str) {
		putchar(*str);
		++str;
	}
}

/**
 * @brief Outputs a string followed by a newline to the terminal.
 *
 * @param str Null-terminated string to output.
 */
void putendl(const char *str) {
	putstr(str);
	putchar('\n');
}

/**
 * @brief Outputs an integer to the terminal.
 *
 * @param n Integer to output.
 */
void putnbr(int n) {
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n >= 10)
		putnbr(n / 10);
	putchar(n % 10 + '0');
}

/**
 * @brief Outputs an integer in a specified base to the terminal.
 *
 * @param n Integer to output.
 * @param base Base for the output (2-16).
 */
void putnbr_base(int n, uint8_t base) {
	const char s_base[18] = "0123456789ABCDEF";

	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n >= base)
		putnbr_base(n / base, base);
	putchar(s_base[n % base]);
}

/**
 * @brief Outputs an unsigned integer in a specified base to the terminal.
 *
 * @param n Unsigned integer to output.
 * @param base Base for the output (2-16).
 */
void putunbr_base(uint32_t n, uint8_t base) {
	const char s_base[18] = "0123456789ABCDEF";

	if (n >= base)
		putunbr_base(n / base, base);
	putchar(s_base[n % base]);
}

/**
 * @brief Outputs an unsigned integer to the terminal.
 *
 * @param n Unsigned integer to output.
 */
void putunbr(uint32_t n) {
	if (n >= 10)
		putunbr(n / 10);
	putchar(n % 10 + '0');
}

/**
 * @brief Outputs a pointer address to the terminal.
 *
 * @param ptr Pointer to output.
 */
void putptr(void *ptr) {
	putstr("0x");
	putunbr_hex((uint32_t)ptr);
}

/**
 * @brief Outputs a string of unsigned characters followed by a newline to the terminal.
 *
 * @param str Null-terminated string of unsigned characters to output.
 */
void uputs(const uint8_t *str) {
	for (size_t i = 0; str[i]; i++)
		putchar(str[i]);
	putchar('\n');
}

/**
 * @brief Outputs a string followed by a newline to the terminal.
 *
 * @param str Null-terminated string to output.
 */
void puts(const char *str) {
	for (size_t i = 0; str[i]; i++)
		putchar(str[i]);
	putchar('\n');
}

/* ----------- */

/**
 * @brief Converts a float to a string.
 *
 * @param buffer Buffer to store the resulting string.
 * @param value Float value to convert.
 */
static void __ftoa(char *buffer, float value) {
	uint32_t count = 1;
	const uint32_t DEFAULT_DECIMAL_COUNT = 0;
	char int_part_buffer[16];
	char *p;

	bzero(int_part_buffer, 16);

	int x = (int)value;
	itoa(x, int_part_buffer);
	p = int_part_buffer;
	while (*p)
		*buffer++ = *p++;
	*buffer++ = '.';

	float decimal = value - x;
	if (decimal == 0)
		*buffer++ = '0';
	else {
		while (decimal > 0) {
			uint32_t y = decimal * 10;
			*buffer++ = y + '0';
			decimal = (decimal * 10) - y;
			count++;
			if (count == DEFAULT_DECIMAL_COUNT)
				break;
		}
	}
}

/**
 * @brief Outputs a float to the terminal.
 *
 * @param value Float value to output.
 */
void putf(const float value) {
	char buffer[32];
	bzero(buffer, 32);
	__ftoa(buffer, value);
	putstr(buffer);
}

// ! ||--------------------------------------------------------------------------------||
// ! ||                         PRINT FUNCTIONS WITH PRECISION                         ||
// ! ||--------------------------------------------------------------------------------||

/**
 * @brief Outputs an integer with a specified precision to the terminal.
 *
 * @param n Integer to output.
 * @param precision Number of digits to output.
 */
void putnbr_precision(int n, int precision) {
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n >= 10)
		putnbr_precision(n / 10, precision);
	putchar(n % 10 + '0');
	if (precision > 0)
		--precision;
	if (precision == 0)
		return;
}

/**
 * @brief Outputs an integer in a specified base with a specified precision to the terminal.
 *
 * @param n Integer to output.
 * @param base Base for the output (2-16).
 * @param precision Number of digits to output.
 */
void putnbr_base_precision(int n, uint8_t base, int precision) {
	const char s_base[18] = "0123456789ABCDEF";

	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n >= base)
		putnbr_base_precision(n / base, base, precision);
	putchar(s_base[n % base]);
	if (precision > 0)
		--precision;
	if (precision == 0)
		return;
}

/**
 * @brief Outputs an unsigned integer in a specified base with a specified precision to the terminal.
 *
 * @param n Unsigned integer to output.
 * @param base Base for the output (2-16).
 * @param precision Number of digits to output.
 */
void putunbr_base_precision(uint32_t n, uint8_t base, int precision) {
	const char s_base[18] = "0123456789ABCDEF";

	if (n >= base)
		putunbr_base_precision(n / base, base, precision);
	putchar(s_base[n % base]);
	if (precision > 0)
		--precision;
	if (precision == 0)
		return;
}

/**
 * @brief Outputs an unsigned integer with a specified precision to the terminal.
 *
 * @param n Unsigned integer to output.
 * @param precision Number of digits to output.
 */
void putunbr_precision(uint32_t n, int precision) {
	if (n >= 10)
		putunbr_precision(n / 10, precision);
	putchar(n % 10 + '0');
	if (precision > 0)
		--precision;
	if (precision == 0)
		return;
}

/**
 * @brief Outputs an unsigned integer in hexadecimal with a specified precision to the terminal.
 *
 * @param n Unsigned integer to output.
 * @param precision Number of digits to output.
 */
void putunbr_hex_precision(uint32_t n, int precision) {
	const char s_base[18] = "0123456789ABCDEF";

	if (n >= 16)
		putunbr_hex_precision(n / 16, precision);
	putchar(s_base[n % 16]);
	if (precision > 0)
		--precision;
	if (precision == 0)
		return;
}

/**
 * @brief Outputs a pointer address with a specified precision to the terminal.
 *
 * @param ptr Pointer to output.
 * @param precision Number of digits to output.
 */
void putptr_precision(void *ptr, int precision) {
	putstr("0x");
	putunbr_hex_precision((uint32_t)ptr, precision);
}

/**
 * @brief Outputs a float with a specified precision to the terminal.
 *
 * @param value Float value to output.
 * @param precision Number of digits to output (unused).
 */
void putf_precision(const float value, __unused__ int precision) {
	char buffer[32];
	bzero(buffer, 32);
	__ftoa(buffer, value);
	putstr(buffer);
}

// ! ||--------------------------------------------------------------------------------||
// ! ||                         PRINT FUNCTIONS WITH LENGTH                            ||
// ! ||--------------------------------------------------------------------------------||

/**
 * @brief Outputs a string with a specified length to the terminal.
 *
 * @param str String to output.
 * @param len Number of characters to output.
 */
void putstr_len(const char *str, int len) {
	for (int i = 0; i < len; i++) {
		putchar(str[i]);
	}
}

/**
 * @brief Outputs an integer with a specified length to the terminal.
 *
 * @param n Integer to output.
 * @param len Number of digits to output.
 */
void putnbr_len(int n, int len) {
	if (len <= 0)
		return;

	int digitCount = 0;
	int n_copy = n;

	if (n == 0) {
		digitCount = 1;
	} else {
		if (n < 0) {
			putchar('-');
			n = -n;
			n_copy = n;
			len--;
		}
		while (n_copy != 0) {
			n_copy /= 10;
			digitCount++;
		}
	}

	while (digitCount > len) {
		n /= 10;
		digitCount--;
	}

	if (n >= 10) {
		putnbr_len(n / 10, len - 1);
	}
	putchar(n % 10 + '0');
}

/**
 * @brief Outputs an integer in a specified base with a specified length to the terminal.
 *
 * @param n Integer to output.
 * @param base Base for the output (2-16).
 * @param len Number of digits to output.
 */
void putnbr_base_len(int n, uint8_t base, int len) {
	const char s_base[18] = "0123456789ABCDEF";
	char numStr[32];
	int i = 0;

	if (len <= 0)
		return;

	if (n < 0) {
		putchar('-');
		n = -n;
		len--;
	}

	do {
		numStr[i++] = s_base[n % base];
		n /= base;
	} while (n > 0 && (uint32_t)i < sizeof(numStr));

	len = (i > len) ? len : i;

	for (int j = len - 1; j >= 0; j--) {
		putchar(numStr[j]);
	}
}

/**
 * @brief Outputs an unsigned integer in a specified base with a specified length to the terminal.
 *
 * @param n Unsigned integer to output.
 * @param base Base for the output (2-16).
 * @param len Number of digits to output.
 */
void putunbr_base_len(uint32_t n, uint8_t base, int len) {
	const char s_base[18] = "0123456789ABCDEF";
	char numStr[32];
	int i = 0;

	if (len <= 0)
		return;

	do {
		numStr[i++] = s_base[n % base];
		n /= base;
	} while (n > 0 && (uint32_t)i < sizeof(numStr));

	len = (i > len) ? len : i;

	for (int j = len - 1; j >= 0; j--) {
		putchar(numStr[j]);
	}
}

/**
 * @brief Outputs an unsigned integer with a specified length to the terminal.
 *
 * @param n Unsigned integer to output.
 * @param len Number of digits to output.
 */
void putunbr_len(uint32_t n, int len) {
	char numStr[32];
	int i = 0;

	if (len <= 0)
		return;

	do {
		numStr[i++] = (n % 10) + '0';
		n /= 10;
	} while (n > 0 && (uint32_t)i < sizeof(numStr));

	len = (i > len) ? len : i;

	for (int j = len - 1; j >= 0; j--) {
		putchar(numStr[j]);
	}
}

/**
 * @brief Outputs an unsigned integer in hexadecimal with a specified length to the terminal.
 *
 * @param n Unsigned integer to output.
 * @param len Number of digits to output.
 */
void putunbr_hex_len(uint32_t n, int len) {
	const char s_base[18] = "0123456789ABCDEF";
	char numStr[32];
	int i = 0;

	if (len <= 0)
		return;

	do {
		numStr[i++] = s_base[n % 16];
		n /= 16;
	} while (n > 0 && (uint32_t)i < sizeof(numStr));

	len = (i > len) ? len : i;

	for (int j = len - 1; j >= 0; j--) {
		putchar(numStr[j]);
	}
}

/**
 * @brief Outputs a pointer address with a specified length to the terminal.
 *
 * @param ptr Pointer to output.
 * @param len Number of digits to output.
 */
void putptr_len(void *ptr, int len) {
	putstr("0x");
	putunbr_hex_len((uintptr_t)ptr, len);
}

/**
 * @brief Outputs a float with a specified length to the terminal.
 *
 * @param value Float value to output.
 * @param len Number of digits to output (unused).
 */
void putf_len(const float value, __unused__ int len) {
	char buffer[32];
	bzero(buffer, 32);
	__ftoa(buffer, value);
	putstr(buffer);
}