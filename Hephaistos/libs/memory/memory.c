/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:25:42 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/02/10 12:04:22 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void *memset(void *ptr, int value, uint32_t length) {
    uint32_t i;

    i = 0;
    while (i < length) {
        ((uchar_t *)ptr)[i] = (uchar_t)value;
        ++i;
    }
    return (ptr);
}

void *memccpy(void *dest, const void *src, int c, uint32_t length) {
    uint32_t i;

    i = 0;
    while (i < length) {
        ((uchar_t *)dest)[i] = ((uchar_t *)src)[i];
        if (((uchar_t *)src)[i] == (uchar_t)c)
            return ((uchar_t *)dest + i);
        ++i;
    }
    return (NULL);
}

void *memcpy(void *dest, const void *src, uint32_t length) {
    uint32_t i;

    i = 0;
    while (i < length) {
        ((uchar_t *)dest)[i] = ((uchar_t *)src)[i];
        ++i;
    }
    return (dest);
}

void *memscpy(void *dest, uint32_t dest_size, const void *src, uint32_t length) {
    uint32_t i;

    i = 0;
    if (dest_size < length) {
        return (NULL);
    }
    for (uint32_t i = 0; i < dest_size; i++) {
        ((uchar_t *)dest)[i] = 0;
    }
    while (i < length) {
        ((uchar_t *)dest)[i] = ((uchar_t *)src)[i];
        ++i;
    }
    return (dest);
}

void *memmove(void *dest, const void *src, uint32_t length) {
    uint32_t i;

    i = 0;
    if (src < dest) {
        while (length--)
            ((uchar_t *)dest)[length] = ((uchar_t *)src)[length];
    } else {
        while (i < length) {
            ((uchar_t *)dest)[i] = ((uchar_t *)src)[i];
            ++i;
        }
    }
    return (dest);
}

void *memchr(const void *s, int c, uint32_t n) {
    uint32_t i;

    i = 0;
    while (i < n) {
        if (((uchar_t *)s)[i] == (uchar_t)c)
            return ((uchar_t *)s + i);
        ++i;
    }
    return (NULL);
}

int memcmp(const void *s1, const void *s2, uint32_t n) {
    uint32_t i;

    i = 0;
    while (i < n) {
        if (((uchar_t *)s1)[i] != ((uchar_t *)s2)[i])
            return (((uchar_t *)s1)[i] - ((uchar_t *)s2)[i]);
        ++i;
    }
    return (0);
}

void *memjoin(void *s1, const void *s2, uint32_t n1, uint32_t n2) {
    uint32_t i;

    i = 0;
    while (i < n2) {
        ((uchar_t *)s1)[n1 + i] = ((uchar_t *)s2)[i];
        ++i;
    }
    return (s1);
}

void *bzero(void *ptr, uint32_t len) {
    uint32_t i;

    i = 0;
    while (i < len) {
        ((uchar_t *)ptr)[i] = 0;
        ++i;
    }
    return (ptr);
}

// ! ||--------------------------------------------------------------------------------||
// ! ||                      Annexe K (Bounds-checking interfaces)                     ||
// ! ||--------------------------------------------------------------------------------||

errno_t memset_s(void *ptr, rsize_t smax, int value, rsize_t length) {
    if (ptr == NULL) {
        return EINVAL;
    }
    if (smax < length) {
        return ERANGE;
    }
    volatile unsigned char *p = ptr;
    while (length--) {
        *p++ = value;
    }
    return 0;
}

errno_t memmove_s(void *dest, rsize_t destmax, const void *src, rsize_t length) {
    if (dest == NULL || src == NULL) {
        return EINVAL;
    }
    if (destmax < length) {
        return ERANGE;
    }
    volatile unsigned char *d = dest;
    const volatile unsigned char *s = src;
    if (d < s) {
        while (length--) {
            *d++ = *s++;
        }
    } else {
        d += length;
        s += length;
        while (length--) {
            *--d = *--s;
        }
    }
    return 0;
}

errno_t memcpy_s(void *dest, rsize_t destmax, const void *src, rsize_t length) {
    if (dest == NULL || src == NULL) {
        return EINVAL;
    }
    if (destmax < length) {
        return ERANGE;
    }
    volatile unsigned char *d = dest;
    const volatile unsigned char *s = src;
    while (length--) {
        *d++ = *s++;
    }
    return 0;
}

errno_t memccpy_s(void *dest, rsize_t destmax, const void *src, int c, rsize_t length) {
    if (dest == NULL || src == NULL) {
        return EINVAL;
    }
    if (destmax < length) {
        return ERANGE;
    }
    volatile unsigned char *d = dest;
    const volatile unsigned char *s = src;
    while (length--) {
        *d++ = *s;
        if (*s == (unsigned char)c) {
            return 0;
        }
        s++;
    }
    return 0;
}

errno_t memchr_s(const void *s, rsize_t smax, int c, rsize_t *idx) {
    if (s == NULL || idx == NULL) {
        return EINVAL;
    }
    const volatile unsigned char *p = s;
    while (smax--) {
        if (*p == (unsigned char)c) {
            *idx = p - (const unsigned char *)s;
            return 0;
        }
        p++;
    }
    *idx = smax;
    return 0;
}

errno_t memcmp_s(const void *s1, rsize_t s1max, const void *s2, rsize_t s2max, int *diff) {
    if (s1 == NULL || s2 == NULL || diff == NULL) {
        return EINVAL;
    }
    const volatile unsigned char *p1 = s1;
    const volatile unsigned char *p2 = s2;
    while (s1max-- && s2max--) {
        if (*p1 != *p2) {
            *diff = *p1 - *p2;
            return 0;
        }
        p1++;
        p2++;
    }
    *diff = s1max - s2max;
    return 0;
}

errno_t memrchr_s(const void *s, rsize_t smax, int c, rsize_t *idx) {
    if (s == NULL || idx == NULL) {
        return EINVAL;
    }
    const volatile unsigned char *p = s;
    while (smax--) {
        if (*p == (unsigned char)c) {
            *idx = p - (const unsigned char *)s;
        }
        p++;
    }
    *idx = smax;
    return 0;
}

errno_t memmem_s(const void *big, rsize_t bigmax, const void *little, rsize_t littlemax, void **result) {
    if (big == NULL || little == NULL || result == NULL) {
        return EINVAL;
    }
    const volatile unsigned char *b = big;
    const volatile unsigned char *l = little;
    while (bigmax--) {
        if (*b == *l) {
            *result = (void *)b;
            return 0;
        }
        b++;
    }
    *result = NULL;
    return 0;
}

errno_t memmoveup_s(void *dest, rsize_t destmax, const void *src, rsize_t length) {
    if (dest == NULL || src == NULL) {
        return EINVAL;
    }
    if (destmax < length) {
        return ERANGE;
    }
    volatile unsigned char *d = dest;
    const volatile unsigned char *s = src;
    d += length;
    s += length;
    while (length--) {
        *--d = *--s;
    }
    return 0;
}

errno_t memmovedown_s(void *dest, rsize_t destmax, const void *src, rsize_t length) {
    if (dest == NULL || src == NULL) {
        return EINVAL;
    }
    if (destmax < length) {
        return ERANGE;
    }
    volatile unsigned char *d = dest;
    const volatile unsigned char *s = src;
    while (length--) {
        *d++ = *s++;
    }
    return 0;
}

errno_t memcpy_smax(void *dest, rsize_t destmax, const void *src, rsize_t length) {
    if (dest == NULL || src == NULL) {
        return EINVAL;
    }
    if (destmax < length) {
        return ERANGE;
    }
    volatile unsigned char *d = dest;
    const volatile unsigned char *s = src;
    while (length--) {
        *d++ = *s++;
    }
    return 0;
}
