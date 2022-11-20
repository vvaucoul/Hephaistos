/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:31:06 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/20 18:16:58 by vvaucoul         ###   ########.fr       */
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

/*******************************************************************************
 *                                 C FUNCTIONS                                 *
 ******************************************************************************/

extern uint32_t nbrlen(int32_t nbr);
extern uint32_t unbrlen(uint32_t nbr);
extern uint32_t strlen(const char *str);
extern uint32_t ptrlen(void *ptr);
extern uint32_t nbrlen_base(const uint32_t nbr, const uint8_t base);

extern int32_t strcmp(const char *s1, const char *s2);
extern int32_t strncmp(const char *s1, const char *s2, uint32_t n);
extern char *strclr(char *new_str, char *str);

#endif /* !_STRING_H */