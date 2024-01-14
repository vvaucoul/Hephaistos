/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:19:39 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/14 12:52:02 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libs/stdio/stdio.h>
#include <libs/convert/convert.h>
#include <charon.h>

void putchar(char c)
{
	terminal_putchar(c);
}

void putstr(const char *str)
{
	while (*str)
	{
		putchar(*str);
		++str;
	}
}

void putendl(const char *str)
{
	putstr(str);
	putchar('\n');
}

void putnbr(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n >= 10)
		putnbr(n / 10);
	putchar(n % 10 + '0');
}

void putnbr_base(int n, uint8_t base)
{
	char s_base[18] = "0123456789ABCDEF";

	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n >= base)
		putnbr_base(n / base, base);
	putchar(s_base[n % base]);
}

void putunbr_base(uint32_t n, uint8_t base)
{
	char s_base[18] = "0123456789ABCDEF";

	if (n >= base)
		putnbr_base(n / base, base);
	putchar(s_base[n % base]);
}

void putunbr(uint32_t n)
{
	if (n >= 10)
		putunbr(n / 10);
	putchar(n % 10 + '0');
}

void putptr(void *ptr)
{
	putstr("0x");
	putunbr_hex((uint32_t)ptr);
}

void uputs(const uint8_t *str)
{
	for (size_t i = 0; str[i]; i++)
		putchar(str[i]);
	putchar('\n');
}

void puts(const char *str)
{
	for (size_t i = 0; str[i]; i++)
		putchar(str[i]);
	putchar('\n');
}

/* ----------- */

static void __ftoa(char *buffer, float value)
{
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
	else
	{
		while (decimal > 0)
		{
			uint32_t y = decimal * 10;
			*buffer++ = y + '0';
			decimal = (decimal * 10) - y;
			count++;
			if (count == DEFAULT_DECIMAL_COUNT)
				break;
		}
	}
}

void putf(const float value)
{
	char buffer[32];
	bzero(buffer, 32);
	__ftoa(buffer, value);
	putstr(buffer);
}