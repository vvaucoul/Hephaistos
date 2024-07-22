/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:25:46 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/22 13:09:02 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MEMORY_H
#define _MEMORY_H

#include <libs/errno/errno.h>
#include <libs/stddef/stddef.h>

typedef uint32_t rsize_t;

/* Standard memory functions */
void *memset(void *ptr, int value, uint32_t length);
void *memccpy(void *dest, const void *src, int c, uint32_t length);
void *memcpy(void *dest, const void *src, uint32_t length);
void *memscpy(void *dest, uint32_t dest_size, const void *src, uint32_t length);
void *memmove(void *dest, const void *src, uint32_t length);
void *memchr(const void *s, int c, uint32_t n);
int memcmp(const void *s1, const void *s2, uint32_t n);
void *memjoin(void *s1, const void *s2, uint32_t n1, uint32_t n2);
void *bzero(void *ptr, uint32_t len);

/* Hex dump function */
void khexdump(uint32_t addr, int limit);

/* Annex K (Bounds-checking interfaces) */
errno_t memset_s(void *ptr, rsize_t smax, int value, rsize_t length);
errno_t memmove_s(void *dest, rsize_t destmax, const void *src, rsize_t length);
errno_t memcpy_s(void *dest, rsize_t destmax, const void *src, rsize_t length);
errno_t memccpy_s(void *dest, rsize_t destmax, const void *src, int c, rsize_t length);
errno_t memchr_s(const void *s, rsize_t smax, int c, rsize_t *idx);
errno_t memcmp_s(const void *s1, rsize_t s1max, const void *s2, rsize_t s2max, int *diff);
errno_t memrchr_s(const void *s, rsize_t smax, int c, rsize_t *idx);
errno_t memmem_s(const void *big, rsize_t bigmax, const void *little, rsize_t littlemax, void **result);
errno_t memmoveup_s(void *dest, rsize_t destmax, const void *src, rsize_t length);
errno_t memmovedown_s(void *dest, rsize_t destmax, const void *src, rsize_t length);
errno_t memcpy_smax(void *dest, rsize_t destmax, const void *src, rsize_t length);

#endif /* !_MEMORY_H */