/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:19:39 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 01:37:55 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <convert.h>
#include <stdio.h>

// ! ||--------------------------------------------------------------------------------||
// ! ||                              BASIC PRINT FUNCTIONS                             ||
// ! ||--------------------------------------------------------------------------------||

void putchar(char c) {
    terminal_putchar(c);
}

void putstr(const char *str) {
    while (*str) {
        putchar(*str);
        ++str;
    }
}

void putendl(const char *str) {
    putstr(str);
    putchar('\n');
}

void putnbr(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n >= 10)
        putnbr(n / 10);
    putchar(n % 10 + '0');
}

void putnbr_base(int n, uint8_t base) {
    char s_base[18] = "0123456789ABCDEF";

    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n >= base)
        putnbr_base(n / base, base);
    putchar(s_base[n % base]);
}

void putunbr_base(uint32_t n, uint8_t base) {
    char s_base[18] = "0123456789ABCDEF";

    if (n >= base)
        putnbr_base(n / base, base);
    putchar(s_base[n % base]);
}

void putunbr(uint32_t n) {
    if (n >= 10)
        putunbr(n / 10);
    putchar(n % 10 + '0');
}

void putptr(void *ptr) {
    putstr("0x");
    putunbr_hex((uint32_t)ptr);
}

void uputs(const uint8_t *str) {
    for (size_t i = 0; str[i]; i++)
        putchar(str[i]);
    putchar('\n');
}

void puts(const char *str) {
    for (size_t i = 0; str[i]; i++)
        putchar(str[i]);
    putchar('\n');
}

/* ----------- */

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

void putf(const float value) {
    char buffer[32];
    bzero(buffer, 32);
    __ftoa(buffer, value);
    putstr(buffer);
}

// ! ||--------------------------------------------------------------------------------||
// ! ||                         PRINT FUNCTIONS WITH PRECISION                         ||
// ! ||--------------------------------------------------------------------------------||

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

void putnbr_base_precision(int n, uint8_t base, int precision) {
    char s_base[18] = "0123456789ABCDEF";

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

void putunbr_base_precision(uint32_t n, uint8_t base, int precision) {
    char s_base[18] = "0123456789ABCDEF";

    if (n >= base)
        putunbr_base_precision(n / base, base, precision);
    putchar(s_base[n % base]);
    if (precision > 0)
        --precision;
    if (precision == 0)
        return;
}

void putunbr_precision(uint32_t n, int precision) {
    if (n >= 10)
        putunbr_precision(n / 10, precision);
    putchar(n % 10 + '0');
    if (precision > 0)
        --precision;
    if (precision == 0)
        return;
}

void putunbr_hex_precision(uint32_t n, int precision) {
    char s_base[18] = "0123456789ABCDEF";

    if (n >= 16)
        putunbr_hex_precision(n / 16, precision);
    putchar(s_base[n % 16]);
    if (precision > 0)
        --precision;
    if (precision == 0)
        return;
}

void putptr_precision(void *ptr, int precision) {
    putstr("0x");
    putunbr_hex_precision((uint32_t)ptr, precision);
}

void putf_precision(const float value, int precision) {
    char buffer[32];
    bzero(buffer, 32);
    __ftoa(buffer, value);
    putstr(buffer);
}

// ! ||--------------------------------------------------------------------------------||
// ! ||                         PRINT FUNCTIONS WITH LENGTH                            ||
// ! ||--------------------------------------------------------------------------------||

void putstr_len(const char *str, int len) {
    for (int i = 0; i < len; i++) {
        putchar(str[i]);
    }
}

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

void putnbr_base_len(int n, uint8_t base, int len) {
    char s_base[18] = "0123456789ABCDEF";
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
    } while (n > 0 && i < sizeof(numStr));

    len = (i > len) ? len : i;

    for (int j = len - 1; j >= 0; j--) {
        putchar(numStr[j]);
    }
}

void putunbr_base_len(uint32_t n, uint8_t base, int len) {
    char s_base[18] = "0123456789ABCDEF";
    char numStr[32];
    int i = 0;

    if (len <= 0)
        return;

    do {
        numStr[i++] = s_base[n % base];
        n /= base;
    } while (n > 0 && i < sizeof(numStr));

    len = (i > len) ? len : i;

    for (int j = len - 1; j >= 0; j--) {
        putchar(numStr[j]);
    }
}

void putunbr_len(uint32_t n, int len) {
    char numStr[32];
    int i = 0;

    if (len <= 0)
        return;

    do {
        numStr[i++] = (n % 10) + '0';
        n /= 10;
    } while (n > 0 && i < sizeof(numStr));

    len = (i > len) ? len : i;

    for (int j = len - 1; j >= 0; j--) {
        putchar(numStr[j]);
    }
}

void putunbr_hex_len(uint32_t n, int len) {
    char s_base[18] = "0123456789ABCDEF";
    char numStr[32];
    int i = 0;

    if (len <= 0)
        return;

    do {
        numStr[i++] = s_base[n % 16];
        n /= 16;
    } while (n > 0 && i < sizeof(numStr));

    len = (i > len) ? len : i;

    for (int j = len - 1; j >= 0; j--) {
        putchar(numStr[j]);
    }
}

void putptr_len(void *ptr, int len) {
    // 0x added without counting it in len
    putstr("0x");
    putunbr_hex_len((uintptr_t)ptr, len);
}

void putf_len(const float value, int len) {
    char buffer[32];
    bzero(buffer, 32);
    __ftoa(buffer, value);
    putstr(buffer);
}