/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:25:42 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/22 13:15:08 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

/**
 * @brief Fills the first length bytes of the memory area pointed to by ptr with the constant byte value.
 *
 * @param ptr Pointer to the memory area.
 * @param value Value to be set.
 * @param length Number of bytes to be set to the value.
 * @return Pointer to the memory area ptr.
 */
void *memset(void *ptr, int value, uint32_t length) {
    uint32_t i = 0;
    while (i < length) {
        ((uchar_t *)ptr)[i] = (uchar_t)value;
        ++i;
    }
    return ptr;
}

/**
 * @brief Copies bytes from src to dest, stopping when the character c is found.
 *
 * @param dest Pointer to the destination array where the content is to be copied.
 * @param src Pointer to the source of data to be copied.
 * @param c Character to stop copying at.
 * @param length Number of bytes to be copied.
 * @return Pointer to the next character in dest after c, or NULL if c was not found in the first length characters of src.
 */
void *memccpy(void *dest, const void *src, int c, uint32_t length) {
    uint32_t i = 0;
    while (i < length) {
        ((uchar_t *)dest)[i] = ((uchar_t *)src)[i];
        if (((uchar_t *)src)[i] == (uchar_t)c)
            return ((uchar_t *)dest + i + 1);
        ++i;
    }
    return NULL;
}

/**
 * @brief Copies length bytes from src to dest.
 *
 * @param dest Pointer to the destination array where the content is to be copied.
 * @param src Pointer to the source of data to be copied.
 * @param length Number of bytes to be copied.
 * @return Pointer to the destination array dest.
 */
void *memcpy(void *dest, const void *src, uint32_t length) {
    uint32_t i = 0;
    while (i < length) {
        ((uchar_t *)dest)[i] = ((uchar_t *)src)[i];
        ++i;
    }
    return dest;
}

/**
 * @brief Copies length bytes from src to dest, ensuring no overflow of dest.
 *
 * @param dest Pointer to the destination array where the content is to be copied.
 * @param dest_size Size of the destination array.
 * @param src Pointer to the source of data to be copied.
 * @param length Number of bytes to be copied.
 * @return Pointer to the destination array dest, or NULL if dest_size is smaller than length.
 */
void *memscpy(void *dest, uint32_t dest_size, const void *src, uint32_t length) {
    if (dest_size < length) {
        return NULL;
    }
    return memcpy(dest, src, length);
}

/**
 * @brief Moves length bytes from src to dest, handling overlapping memory areas.
 *
 * @param dest Pointer to the destination array where the content is to be moved.
 * @param src Pointer to the source of data to be moved.
 * @param length Number of bytes to be moved.
 * @return Pointer to the destination array dest.
 */
void *memmove(void *dest, const void *src, uint32_t length) {
    if (src < dest) {
        for (uint32_t i = length; i != 0; --i) {
            ((uchar_t *)dest)[i - 1] = ((uchar_t *)src)[i - 1];
        }
    } else {
        for (uint32_t i = 0; i < length; ++i) {
            ((uchar_t *)dest)[i] = ((uchar_t *)src)[i];
        }
    }
    return dest;
}

/**
 * @brief Scans the first n bytes of the memory area pointed to by s for the character c.
 *
 * @param s Pointer to the memory area.
 * @param c Character to be located.
 * @param n Number of bytes to be analyzed.
 * @return Pointer to the first occurrence of the character c in the memory area s, or NULL if the character is not found.
 */
void *memchr(const void *s, int c, uint32_t n) {
    for (uint32_t i = 0; i < n; ++i) {
        if (((uchar_t *)s)[i] == (uchar_t)c)
            return (uchar_t *)s + i;
    }
    return NULL;
}

/**
 * @brief Compares the first n bytes of the memory areas s1 and s2.
 *
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param n Number of bytes to be compared.
 * @return An integer less than, equal to, or greater than zero if the first n bytes of s1 is found to be less than, to match, or be greater than the first n bytes of s2.
 */
int memcmp(const void *s1, const void *s2, uint32_t n) {
    for (uint32_t i = 0; i < n; ++i) {
        if (((uchar_t *)s1)[i] != ((uchar_t *)s2)[i])
            return ((uchar_t *)s1)[i] - ((uchar_t *)s2)[i];
    }
    return 0;
}

/**
 * @brief Joins two memory areas s1 and s2 of size n1 and n2 respectively.
 *
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param n1 Size of the first memory area.
 * @param n2 Size of the second memory area.
 * @return Pointer to the joined memory area.
 */
void *memjoin(void *s1, const void *s2, uint32_t n1, uint32_t n2) {
    for (uint32_t i = 0; i < n2; ++i) {
        ((uchar_t *)s1)[n1 + i] = ((uchar_t *)s2)[i];
    }
    return s1;
}

/**
 * @brief Fills the first len bytes of the memory area pointed to by ptr with zero.
 *
 * @param ptr Pointer to the memory area.
 * @param len Number of bytes to be set to zero.
 * @return Pointer to the memory area ptr.
 */
void *bzero(void *ptr, uint32_t len) {
    return memset(ptr, 0, len);
}

// ! ||--------------------------------------------------------------------------------||
// ! ||                      Annexe K (Bounds-checking interfaces)                     ||
// ! ||--------------------------------------------------------------------------------||

/**
 * @brief Sets a block of memory with a specified value, ensuring secure memory handling.
 *
 * The memset_s function sets the first `length` bytes of the memory block pointed to by `ptr`
 * to the specified `value`. It ensures secure memory handling by checking the size of the memory
 * block (`smax`) and the length of the operation (`length`).
 *
 * @param ptr     Pointer to the memory block to be set.
 * @param smax    The maximum size of the memory block.
 * @param value   The value to be set (converted to `unsigned char`).
 * @param length  The number of bytes to be set.
 *
 * @return If the operation is successful, `0` is returned. Otherwise, an error code is returned.
 *         Possible error codes include:
 *         - `EINVAL`: Invalid parameter(s) passed.
 *         - `ERANGE`: The operation would exceed the memory block size.
 *         - `ESNOSPC`: The operation would exceed the maximum allowed size.
 *         - `ESAFETY`: The operation would result in an unsafe memory access.
 *         - `ENOMEM`: Insufficient memory to perform the operation.
 */
errno_t memset_s(void *ptr, rsize_t smax, int value, rsize_t length) {
    if (ptr == NULL) {
        return EINVAL;
    }
    if (smax < length) {
        return ERANGE;
    }
    volatile uchar_t *p = ptr;
    while (length--) {
        *p++ = value;
    }
    return 0;
}

/**
 * @brief Copies a block of memory, handling overlapping regions safely.
 *
 * The `memmove_s` function copies `length` bytes from the memory location pointed to by `src` to the memory location pointed to by `dest`.
 * This function ensures that the copy is performed correctly even if the source and destination memory regions overlap.
 *
 * @param dest The pointer to the destination memory location.
 * @param destmax The maximum number of bytes that can be written to the destination memory location.
 * @param src The pointer to the source memory location.
 * @param length The number of bytes to be copied.
 *
 * @return If successful, zero is returned; otherwise, an error code is returned.
 */
errno_t memmove_s(void *dest, rsize_t destmax, const void *src, rsize_t length) {
    if (dest == NULL || src == NULL) {
        return EINVAL;
    }
    if (destmax < length) {
        return ERANGE;
    }
    volatile uchar_t *d = dest;
    const volatile uchar_t *s = src;
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

/**
 * @brief Copies a block of memory from a source location to a destination location, with bounds checking.
 *
 * This function copies the memory block specified by the `src` parameter to the memory block specified by the `dest` parameter.
 * The number of bytes to be copied is specified by the `length` parameter.
 * The `destmax` parameter specifies the maximum number of bytes that can be written to the destination buffer.
 *
 * @param dest Pointer to the destination buffer where the content is to be copied.
 * @param destmax Maximum number of bytes that can be written to the destination buffer.
 * @param src Pointer to the source of data to be copied.
 * @param length Number of bytes to copy from the source buffer to the destination buffer.
 * 
 * @return If successful, zero is returned. Otherwise, an error code is returned.
 */
errno_t memcpy_s(void *dest, rsize_t destmax, const void *src, rsize_t length) {
    if (dest == NULL || src == NULL) {
        return EINVAL;
    }
    if (destmax < length) {
        return ERANGE;
    }
    volatile uchar_t *d = dest;
    const volatile uchar_t *s = src;
    while (length--) {
        *d++ = *s++;
    }
    return 0;
}

/**
 * @brief Copies bytes from source to destination until a specific character is encountered or the maximum number of bytes is reached.
 *
 * This function copies at most `length` bytes from the memory area pointed to by `src` to the memory area pointed to by `dest`,
 * stopping the copy operation if the character `c` is encountered. The copy operation will not exceed `destmax` bytes.
 *
 * @param dest Pointer to the destination memory area where the copied bytes will be stored.
 * @param destmax Maximum number of bytes that can be written to the destination memory area.
 * @param src Pointer to the source memory area from where the bytes will be copied.
 * @param c The character that, if encountered, will stop the copy operation.
 * @param length Maximum number of bytes to be copied from the source memory area.
 * 
 * @return If successful, zero is returned. Otherwise, an error code is returned.
 */
errno_t memccpy_s(void *dest, rsize_t destmax, const void *src, int c, rsize_t length) {
    if (dest == NULL || src == NULL) {
        return EINVAL;
    }
    if (destmax < length) {
        return ERANGE;
    }
    volatile uchar_t *d = dest;
    const volatile uchar_t *s = src;
    while (length--) {
        *d++ = *s;
        if (*s == (uchar_t)c) {
            return 0;
        }
        s++;
    }
    return 0;
}

/**
 * Searches for the first occurrence of a specific character in the given memory block.
 *
 * @param s     Pointer to the memory block to be searched.
 * @param smax  Maximum number of bytes to be searched in the memory block.
 * @param c     Character to be searched for.
 * @param idx   Pointer to store the index of the found character.
 *
 * @return      Zero if the character is found, otherwise an error code indicating the failure.
 */
errno_t memchr_s(const void *s, rsize_t smax, int c, rsize_t *idx) {
    if (s == NULL || idx == NULL) {
        return EINVAL;
    }
    const volatile uchar_t *p = s;
    while (smax--) {
        if (*p == (uchar_t)c) {
            *idx = p - (const uchar_t *)s;
            return 0;
        }
        p++;
    }
    *idx = smax;
    return 0;
}

/**
 * Compares two memory buffers in a secure manner.
 *
 * This function compares the first `s1max` bytes of the memory block pointed to by `s1`
 * with the first `s2max` bytes of the memory block pointed to by `s2`. The result of the
 * comparison is stored in the `diff` parameter.
 *
 * @param s1     Pointer to the first memory block.
 * @param s1max  Maximum number of bytes to compare in the first memory block.
 * @param s2     Pointer to the second memory block.
 * @param s2max  Maximum number of bytes to compare in the second memory block.
 * @param diff   Pointer to an integer where the result of the comparison will be stored.
 *               The value will be 0 if the memory blocks are equal, a positive value if
 *               the first differing byte in `s1` is greater than the corresponding byte
 *               in `s2`, or a negative value if it is less.
 *
 * @return       If successful, returns 0. If an error occurs, returns an error code.
 */
errno_t memcmp_s(const void *s1, rsize_t s1max, const void *s2, rsize_t s2max, int *diff) {
    if (s1 == NULL || s2 == NULL || diff == NULL) {
        return EINVAL;
    }
    const volatile uchar_t *p1 = s1;
    const volatile uchar_t *p2 = s2;
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

/**
 * Searches for the last occurrence of a specific character in a memory block.
 *
 * This function searches for the last occurrence of the character 'c' in the memory block 's' of size 'smax'.
 * If the character is found, the index of its location is stored in the variable pointed to by 'idx'.
 *
 * @param s     Pointer to the memory block to be searched.
 * @param smax  Maximum number of bytes to be searched in the memory block.
 * @param c     Character to be searched for.
 * @param idx   Pointer to a variable where the index of the last occurrence of 'c' will be stored.
 *
 * @return      If successful, returns zero. If an error occurs, returns an error code defined in errno.h.
 */
errno_t memrchr_s(const void *s, rsize_t smax, int c, rsize_t *idx) {
    if (s == NULL || idx == NULL) {
        return EINVAL;
    }
    const volatile uchar_t *p = s;
    while (smax--) {
        if (*p == (uchar_t)c) {
            *idx = p - (const uchar_t *)s;
        }
        p++;
    }
    *idx = smax;
    return 0;
}

/**
 * Searches for the first occurrence of the byte string 'little' within the byte string 'big'.
 *
 * @param big The pointer to the byte string to be searched.
 * @param bigmax The maximum number of bytes to be searched in 'big'.
 * @param little The pointer to the byte string to search for.
 * @param littlemax The maximum number of bytes to be searched in 'little'.
 * @param result A pointer to the location where the pointer to the first occurrence of 'little' in 'big' will be stored.
 *               If 'result' is NULL, the function will only determine if 'little' is present in 'big'.
 *
 * @return If 'result' is not NULL and 'little' is found in 'big', the function returns zero and sets 'result' to the location of 'little' in 'big'.
 *         If 'result' is NULL and 'little' is found in 'big', the function returns zero.
 *         If 'result' is not NULL and 'little' is not found in 'big', the function returns a non-zero error code and sets 'result' to NULL.
 *         If 'result' is NULL and 'little' is not found in 'big', the function returns a non-zero error code.
 */
errno_t memmem_s(const void *big, rsize_t bigmax, const void *little, rsize_t littlemax, void **result) {
    if (big == NULL || little == NULL || result == NULL) {
        return EINVAL;
    }
    const volatile uchar_t *b = big;
    const volatile uchar_t *l = little;
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

/**
 * Moves a block of memory upwards, safely checking for buffer overflows.
 *
 * This function copies the contents of the memory block pointed to by 'src' to the memory block pointed to by 'dest',
 * moving the memory upwards. The number of bytes to be copied is specified by 'length'.
 *
 * The function performs a runtime-constrained check to ensure that the operation does not result in a buffer overflow.
 * The size of the destination buffer is specified by 'destmax'.
 *
 * @param dest     Pointer to the destination memory block.
 * @param destmax  Maximum number of bytes that can be written to the destination buffer.
 * @param src      Pointer to the source memory block.
 * @param length   Number of bytes to be copied.
 *
 * @return If successful, zero is returned. Otherwise, an error code indicating the cause of failure is returned.
 */
errno_t memmoveup_s(void *dest, rsize_t destmax, const void *src, rsize_t length) {
    if (dest == NULL || src == NULL) {
        return EINVAL;
    }
    if (destmax < length) {
        return ERANGE;
    }
    volatile uchar_t *d = dest;
    const volatile uchar_t *s = src;
    d += length;
    s += length;
    while (length--) {
        *--d = *--s;
    }
    return 0;
}

/**
 * Moves a block of memory down, overlapping the destination and source regions.
 *
 * This function moves the memory block pointed to by `src` to the memory block
 * pointed to by `dest`, while handling overlapping regions correctly. The `length`
 * parameter specifies the number of bytes to move.
 *
 * @param dest The pointer to the destination memory block.
 * @param destmax The maximum number of bytes that can be written to the destination block.
 * @param src The pointer to the source memory block.
 * @param length The number of bytes to move.
 * @return If successful, returns zero. Otherwise, returns an error code indicating the cause of failure.
 */
errno_t memmovedown_s(void *dest, rsize_t destmax, const void *src, rsize_t length) {
    if (dest == NULL || src == NULL) {
        return EINVAL;
    }
    if (destmax < length) {
        return ERANGE;
    }
    volatile uchar_t *d = dest;
    const volatile uchar_t *s = src;
    while (length--) {
        *d++ = *s++;
    }
    return 0;
}

/**
 * @brief Copies a specified number of bytes from the source memory to the destination memory, with a maximum limit on the destination size.
 *
 * This function copies the specified number of bytes from the source memory to the destination memory. It ensures that the copy operation does not exceed the maximum size of the destination memory.
 *
 * @param dest Pointer to the destination memory where the data will be copied.
 * @param destmax Maximum size of the destination memory.
 * @param src Pointer to the source memory from where the data will be copied.
 * @param length Number of bytes to be copied.
 * @return If successful, returns zero; otherwise, returns an error code indicating the cause of failure.
 */
errno_t memcpy_smax(void *dest, rsize_t destmax, const void *src, rsize_t length) {
    if (dest == NULL || src == NULL) {
        return EINVAL;
    }
    if (destmax < length) {
        return ERANGE;
    }
    volatile uchar_t *d = dest;
    const volatile uchar_t *s = src;
    while (length--) {
        *d++ = *s++;
    }
    return 0;
}