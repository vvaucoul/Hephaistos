/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:31:06 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 12:27:41 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STRING_H
#define _STRING_H

#include <errno.h>
#include <stdint.h>

// ! ||--------------------------------------------------------------------------------||
// ! ||                                  ASM FUNCTIONS                                 ||
// ! ||--------------------------------------------------------------------------------||

#define USE_ASM_STRING_FUNCTIONS 0

extern uint32_t __strlen(const char *str);
extern uint32_t __nbrlen(int32_t nbr);
extern uint32_t __nbrlen_base(int32_t nbr, const uint8_t base);
extern int32_t __strcmp(const char *s1, const char *s2);
extern int32_t __strncmp(const char *s1, const char *s2, uint32_t n);

// ! ||--------------------------------------------------------------------------------||
// ! ||                                   C FUNCTIONS                                  ||
// ! ||--------------------------------------------------------------------------------||

#if USE_ASM_STRING_FUNCTIONS == 1

inline uint32_t nbrlen(int32_t nbr) {
	return (__nbrlen(nbr));
}

inline uint32_t unbrlen(uint32_t nbr) {
	return (__nbrlen((uint32_t)nbr));
}

inline uint32_t strlen(const char *str) {
	return (__strlen(str));
}

inline uint32_t nbrlen_base(const int32_t nbr, const uint8_t base) {
	return (__nbrlen_base(nbr, base));
}

inline uint32_t unbrlen_base(const uint32_t nbr, const uint8_t base) {
	return (__nbrlen_base((uint32_t)nbr, base));
}

inline int32_t strcmp(const char *s1, const char *s2) {
	return (__strcmp(s1, s2));
}

inline int32_t strncmp(const char *s1, const char *s2, uint32_t n) {
	return (__strncmp(s1, s2, n));
}

#else

uint32_t nbrlen(int32_t nbr);
uint32_t unbrlen(uint32_t nbr);
uint32_t strlen(const char *str);
uint32_t nbrlen_base(const int32_t nbr, const uint8_t base);
uint32_t unbrlen_base(const uint32_t nbr, const uint8_t base);
int32_t strcmp(const char *s1, const char *s2);
int32_t strncmp(const char *s1, const char *s2, uint32_t n);

#endif

char *strtrtc(const char *str, const char c);
char *strclr(char *new_str, char *str);
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, uint32_t n);
char *strcat(char *dest, const char *src);
char *strjoin(char *s1, char *s2);
char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);
char *strdup(const char *s);
char *strndup(const char *s, uint32_t n);
char *strtrim(char const *s);
char *strsub(char const *s, unsigned int start, uint32_t len);
char **strsplit(char const *s, char c);
char *strtok(char *str, const char *delim);
char *strstr(const char *haystack, const char *needle);
char *strpbrk(const char *s, const char *accept);
char *strrev(char *str);
char *strrevp(char *str, uint32_t start, uint32_t end);

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

#endif /* !_STRING_H */