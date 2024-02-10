/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:25:46 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/02/10 12:04:19 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MEMORY_H
#define _MEMORY_H

#include <libs/stddef/stddef.h>
#include <libs/errno/errno.h>

typedef uint32_t rsize_t;

extern void *memset(void *ptr, int value, uint32_t length);
extern void *memccpy(void *dest, const void *src, int c, uint32_t length);
extern void *memcpy(void *dest, const void *src, uint32_t length);
extern void *memscpy(void *dest, uint32_t dest_size, const void *src, uint32_t length);
extern void *memmove(void *dest, const void *src, uint32_t length);
extern void *memchr(const void *s, int c, uint32_t n);
extern int memcmp(const void *s1, const void *s2, uint32_t n);
extern void *memjoin(void *s1, const void *s2, uint32_t n1, uint32_t n2);
extern void *bzero(void *ptr, uint32_t len);

extern void khexdump(uint32_t addr, int limit);

// ! ||--------------------------------------------------------------------------------||
// ! ||                      Annexe K (Bounds-checking interfaces)                     ||
// ! ||--------------------------------------------------------------------------------||

/**
 * @brief *_s compliant with ISO/IEC TR 24731 / C11 Annex K (Bounds-checking interfaces)
 */

extern errno_t memset_s(void *ptr, rsize_t smax, int value, rsize_t length);
extern errno_t memmove_s(void *dest, rsize_t destmax, const void *src, rsize_t length);
extern errno_t memcpy_s(void *dest, rsize_t destmax, const void *src, rsize_t length);
extern errno_t memccpy_s(void *dest, rsize_t destmax, const void *src, int c, rsize_t length);
extern errno_t memchr_s(const void *s, rsize_t smax, int c, rsize_t *idx);
extern errno_t memcmp_s(const void *s1, rsize_t s1max, const void *s2, rsize_t s2max, int *diff);
extern errno_t memrchr_s(const void *s, rsize_t smax, int c, rsize_t *idx);
extern errno_t memmem_s(const void *big, rsize_t bigmax, const void *little, rsize_t littlemax, void **result);
extern errno_t memmoveup_s(void *dest, rsize_t destmax, const void *src, rsize_t length);
extern errno_t memmovedown_s(void *dest, rsize_t destmax, const void *src, rsize_t length);
extern errno_t memcpy_smax(void *dest, rsize_t destmax, const void *src, rsize_t length);

#endif /* !_MEMORY_H */