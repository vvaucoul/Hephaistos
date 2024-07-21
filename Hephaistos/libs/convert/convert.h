/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:58:53 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/21 23:55:15 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONVERT_H
#define _CONVERT_H

#include <libs/stdbool/stdbool.h>
#include <libs/stddef/stddef.h>

#define __ITOA_BUFFER_LENGTH__ 12
#define __ASCII_BASE__ "0123456789ABCDEF"

extern int atoi(const char *str);
extern int itoa(int nbr, char str[__ITOA_BUFFER_LENGTH__]);
extern int uitoa(uint32_t nbr, char str[__ITOA_BUFFER_LENGTH__]);
extern int itoa_base(int nbr, int base, char str[__ITOA_BUFFER_LENGTH__]);
extern uint32_t uitoa_base(uint32_t nbr, int base, char str[__ITOA_BUFFER_LENGTH__]);

// ! ||--------------------------------------------------------------------------------||
// ! ||                        SAFE FUNCTIONS (MEMORY AVAILABLE)                       ||
// ! ||--------------------------------------------------------------------------------||

extern int atoi_base_s(const char *str, int base);
extern char *itoa_s(int nbr);
extern char *uitoa_s(uint32_t nbr);
extern char *itoa_base_s(int nbr, int base);
extern char *uitoa_base_s(uint32_t nbr, int base);

extern char *ftoa(double num, int precision);
extern char *htoa(uint32_t num);
extern char *btoa(uint32_t num);
extern char *otoa(uint32_t num);
extern double atof(const char *str);

#endif /* !_CONVERT_H */