/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:25:46 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/20 14:16:08 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MEMORY_H
#define _MEMORY_H

#include <libs/stddef/stddef.h>

extern void *memset(void *ptr, int value, uint32_t length);
extern void *memcpy(void *dest, const void *src, uint32_t length);
extern void *memmove(void *dest, const void *src, uint32_t length);
extern void *memchr(const void *s, int c, uint32_t n);
extern int memcmp(const void *s1, const void *s2, uint32_t n);
extern void *memjoin(void *s1, const void *s2, uint32_t n1, uint32_t n2);

extern void *bzero(void *ptr, uint32_t len);

extern void khexdump(uint32_t addr, int limit);

#endif /* !_MEMORY_H */