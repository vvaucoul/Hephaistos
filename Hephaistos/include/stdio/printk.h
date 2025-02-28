/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printk.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:55:51 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/10/19 19:10:09 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTK_H
#define PRINTK_H

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define __DEL_MOD 0x25	   // '%'
#define __DEL_D 0x64	   // 'd'
#define __DEL_I 0x69	   // 'i'
#define __DEL_C 0x63	   // 'c'
#define __DEL_P 0x70	   // 'p'
#define __DEL_S 0x73	   // 's'
#define __DEL_U 0x75	   // 'u'
#define __DEL_X 0x78	   // 'x'
#define __DEL_F 0x66	   // 'f'
#define __DEL_LX 0x6C78	   // 'lx'
#define __DEL_LL 0x6C6C	   // 'll'
#define __DEL_LD 0x6C64	   // 'ld'
#define __DEL_LLX 0x6C6C78 // 'llx'
#define __DEL_LLU 0x6C6C75 // 'llu'
#define __DEL_LLD 0x6C6C64 // 'lld'

#define __SPE_STAR 0x2A // '*'
#define __SPE_NEG 0x2D	// '-'
#define __SPE_ZERO 0x30 // '0'
#define __SPE_DOT 0x2E	// '.'

typedef struct s_printk {
	va_list args;
	char format[1024];

	int32_t space;
	bool space_is_star;

	bool is_neg_space;
	bool use_zero;

	int precision;
} printk_t;

extern printk_t _g_printk;

extern uint32_t printk(const char *format, ...);
// extern void vsprintk(const char *str, void (*write)(const char), const char *format, va_list arg);

// extern void __kpf_manage_space_front(const int arg_len);
// extern void __kpf_manage_space_back(const int arg_len);

void __kpf_manage_space_front(uint32_t arg_len);
void __kpf_manage_space_back(uint32_t arg_len);
void __kpf_manage_spaces(uint32_t arg_len);

extern uint32_t __kpf_manage_mod(const char *format, uint32_t i);
extern void __kpf_manage_char();
extern void __kpf_manage_nbr();
extern void __kpf_manage_str();
extern void __kpf_manage_ptr();
extern void __kpf_manage_hexa();
extern void __kpf_manage_unsigned();
extern void __kpf_manage_float();
extern void __kpf_manage_long_hexa();
extern void __kpf_manage_long_long_hexa();
extern void __kpf_manage_long_long_unsigned();
extern void __kpf_manage_long_long_nbr();
extern void __kpf_manage_long_nbr();

extern uint32_t __kptrlen(const void *ptr);
extern uint32_t __k_get_len(uint32_t arg_len);

#endif /* !PRINTK_H */