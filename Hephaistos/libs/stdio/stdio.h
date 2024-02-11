/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:13:31 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/02/11 12:28:34 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STDIO_H
#define _STDIO_H

/*******************************************************************************
 *                                   COLORS                                    *
 ******************************************************************************/

#define _BLACK "\033[0;30m"
#define _BLUE "\033[0;31m"
#define _GREEN "\033[0;32m"
#define _CYAN "\033[0;33m"
#define _RED "\033[0;34m"
#define _MAGENTA "\033[0;35m"
#define _YELLOW "\033[0;36m"
#define _LGREY "\033[0;37m"
#define _DGREY "\033[0;38m"
#define _LBLUE "\033[0;39m"
#define _LGREEN "\033[0;40m"
#define _LCYAN "\033[0;41m"
#define _LRED "\033[0;42m"
#define _LMAGENTA "\033[0;43m"
#define _LYELLOW "\033[0;44m"
#define _WHITE "\033[0;45m"
#define _END "\033[0m"

#define _BOLD "\033[1m"
#define _DIM "\033[2m"
#define _UNDERLINE "\033[4m"
#define _BLINK "\033[5m"
#define _REVERSE "\033[7m"
#define _CONCEALED "\033[8m"

#define _CURSOR_MOVE_UP "\033[1A"

#include "printk/printk.h"

/* Basic print functions */
extern void putchar(char c);
extern void puts(const char *str);
extern void putstr(const char *str);
extern void putnbr(int nbr);
extern void putunbr(uint32_t nbr);
extern void putptr(void *ptr);
extern void putnbr_base(int nbr, uint8_t base);
extern void putunbr_base(uint32_t nbr, uint8_t base);
extern void putf(const float value);

/* Print with precision */
extern void putnbr_precision(int n, int precision);
extern void putnbr_base_precision(int n, uint8_t base, int precision);
extern void putunbr_base_precision(uint32_t n, uint8_t base, int precision);
extern void putunbr_precision(uint32_t n, int precision);
extern void putunbr_hex_precision(uint32_t n, int precision);
extern void putptr_precision(void *ptr, int precision);
extern void putf_precision(const float value, int precision);

/* Print with length */
extern void putstr_len(const char *str, int len);
extern void putnbr_len(int n, int len);
extern void putnbr_base_len(int n, uint8_t base, int len);
extern void putunbr_base_len(uint32_t n, uint8_t base, int len);
extern void putunbr_len(uint32_t n, int len);
extern void putunbr_hex_len(uint32_t n, int len);
extern void putptr_len(void *ptr, int len);
extern void putf_len(const float value, int len);

static inline void putnbr_hex(int n) {
    putnbr_base(n, 16);
}

static inline void putnbr_bin(int n) {
    putnbr_base(n, 2);
}

static inline void putunbr_hex(uint32_t n) {
    putunbr_base(n, 16);
}

static inline void putunbr_bin(uint32_t n) {
    putunbr_base(n, 2);
}

#endif /* !_STDIO_H */