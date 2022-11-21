/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printk.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:55:51 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/21 13:52:11 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTK_H
#define PRINTK_H

#include <libs/stdarg/stdarg.h>
#include <libs/stddef/stddef.h>
#include <libs/stdbool/stdbool.h>
#include <libs/stdio/stdio.h>
#include <libs/ctype/ctype.h>
#include <libs/string/string.h>

#define __DEL_MOD 0x25 // '%'
#define __DEL_D 0x64   // 'd'
#define __DEL_I 0x69   // 'i'
#define __DEL_C 0x63   // 'c'
#define __DEL_P 0x70   // 'p'
#define __DEL_S 0x73   // 's'
#define __DEL_U 0x75   // 'u'
#define __DEL_X 0x78   // 'x'
#define __DEL_F 0x66   // 'f'

#define __SPE_STAR 0x2A // '*'
#define __SPE_NEG 0x2D  // '-'
#define __SPE_ZERO 0x30 // '0'
#define __SPE_DOT 0x2E  // '.'

typedef struct s_printk
{
    va_list args;
    char *format;

    int32_t space;
    bool space_is_star;

    bool is_neg_space;
    bool use_zero;
} printk_t;

extern printk_t _g_printk;

extern uint32_t printk(const char *format, ...);
extern void vsprintk(const char *str, void (*write)(const char), const char *format, va_list arg);

extern void __kpf_manage_space_front(const int arg_len);
extern void __kpf_manage_space_back(const int arg_len);

extern size_t __kpf_manage_mod(const char *format, size_t i);
extern void __kpf_manage_char();
extern void __kpf_manage_nbr();
extern void __kpf_manage_str();
extern void __kpf_manage_ptr();
extern void __kpf_manage_hexa();
extern void __kpf_manage_unsigned();
extern void __kpf_manage_float();

extern size_t __kptrlen(const void *ptr);

// extern uint8_t __check_colors(const char *str);
// extern uint32_t __check_mods(const char *str, uint32_t i);
// extern uint8_t __check_special_strings(const char *str);

// extern uint32_t __mods_manager_mod(const char *format, uint32_t i);
// extern void __mods_manager_str(void);
// extern void __mods_manager_int(void);
// extern void __mods_manager_char(void);
// extern void __mods_manager_uint(void);
// extern void __mods_manager_hex(void);
// extern void __mods_manager_ptr(void);
// extern void __mods_manager_float(void);

// extern void __printk_display_char(char c);
// extern void __printk_display_string(char *str);

#endif /* !PRINTK_H */