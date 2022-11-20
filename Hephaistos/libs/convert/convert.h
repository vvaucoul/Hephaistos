/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:58:53 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/20 23:03:38 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONVERT_H
#define _CONVERT_H

#include <libs/stddef/stddef.h>
#include <libs/stdbool/stdbool.h>   

#define __ITOA_BUFFER_LENGTH__ 11
#define __ASCII_BASE__ "0123456789ABCDEF"

/*
** Convert Int To Ascii
*/
extern int itoa(int nbr, char str[__ITOA_BUFFER_LENGTH__]);

/*
** Convert Unsigned Int To Ascii
*/
extern int uitoa(uint32_t nbr, char str[__ITOA_BUFFER_LENGTH__]);

/*
** Convert Int to Ascii with base
*/
extern int itoa_base(int nbr, int base, char str[__ITOA_BUFFER_LENGTH__]);

/*
** Convert Unsigned Int to Ascii with base
*/
extern uint32_t uitoa_base(uint32_t nbr, int base, char str[__ITOA_BUFFER_LENGTH__]);

/*
** Convert Unsigned long to Ascii
*/
extern int ultoa(uint64_t nbr, char str[__ITOA_BUFFER_LENGTH__]);

/*
** Convert Short to Ascii
*/
extern int stoa(int8_t nbr, char str[__ITOA_BUFFER_LENGTH__]);

/*
** Convert Unsigned Short to Ascii
*/
extern int ustoa(uint8_t nbr, char str[__ITOA_BUFFER_LENGTH__]);

/*
** Convert Ascii to Int
*/
extern int atoi(const char *str);

/*
** Convert Float to Ascii
*/
extern void ftoa(char *buffer, float value);

#endif /* !_CONVERT_H */