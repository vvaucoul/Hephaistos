/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:31:06 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/12/10 15:19:35 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STRING_H
#define _STRING_H

#include <libs/stddef/stddef.h>
#include <libs/stdbool/stdbool.h>

/*******************************************************************************
 *                                ASM FUNCTIONS                                *
 ******************************************************************************/

extern uint32_t __strlen(const char *str);
extern uint32_t __nbrlen(int32_t nbr);
extern uint32_t __nbrlen_base(int32_t nbr, const uint8_t base);
extern int32_t __strcmp(const char *s1, const char *s2);
extern int32_t __strncmp(const char *s1, const char *s2, uint32_t n);

/*******************************************************************************
 *                                 C FUNCTIONS                                 *
 ******************************************************************************/

inline uint32_t nbrlen(int32_t nbr)
{
    return (__nbrlen(nbr));
}

inline uint32_t unbrlen(uint32_t nbr)
{
    return (__nbrlen((uint32_t)nbr));
}

inline uint32_t strlen(const char *str)
{
    return (__strlen(str));
}

inline uint32_t nbrlen_base(const int32_t nbr, const uint8_t base)
{
    return (__nbrlen_base(nbr, base));
}

inline uint32_t unbrlen_base(const uint32_t nbr, const uint8_t base)
{
    return (__nbrlen_base((uint32_t)nbr, base));
}

inline int32_t strcmp(const char *s1, const char *s2)
{
    return (__strcmp(s1, s2));
}

inline int32_t strncmp(const char *s1, const char *s2, uint32_t n)
{
    return (__strncmp(s1, s2, n));
}

extern char *strtrtc(const char *str, const char c);

extern char *strclr(char *new_str, char *str);

extern char *strcpy(char *dest, const char *src);

#endif /* !_STRING_H */