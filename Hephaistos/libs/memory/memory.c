/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:25:42 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/20 13:27:42 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void *memset(void *ptr, int value, uint32_t length)
{
    uint32_t i;

    i = 0;
    while (i < length)
    {
        ((uchar_t *)ptr)[i] = (uchar_t)value;
        ++i;
    }
    return (ptr);
}

void *memcpy(void *dest, const void *src, uint32_t length)
{
    uint32_t i;

    i = 0;
    while (i < length)
    {
        ((uchar_t *)dest)[i] = ((uchar_t *)src)[i];
        ++i;
    }
    return (dest);
}

void *memmove(void *dest, const void *src, uint32_t length)
{
    uint32_t i;

    i = 0;
    if (src < dest)
    {
        while (length--)
            ((uchar_t *)dest)[length] = ((uchar_t *)src)[length];
    }
    else
    {
        while (i < length)
        {
            ((uchar_t *)dest)[i] = ((uchar_t *)src)[i];
            ++i;
        }
    }
    return (dest);
}

void *memchr(const void *s, int c, uint32_t n)
{
    uint32_t i;

    i = 0;
    while (i < n)
    {
        if (((uchar_t *)s)[i] == (uchar_t)c)
            return ((uchar_t *)s + i);
        ++i;
    }
    return (NULL);
}

int memcmp(const void *s1, const void *s2, uint32_t n)
{
    uint32_t i;

    i = 0;
    while (i < n)
    {
        if (((uchar_t *)s1)[i] != ((uchar_t *)s2)[i])
            return (((uchar_t *)s1)[i] - ((uchar_t *)s2)[i]);
        ++i;
    }
    return (0);
}

void *memjoin(void *s1, const void *s2, uint32_t n1, uint32_t n2)
{
    uint32_t i;

    i = 0;
    while (i < n2)
    {
        ((uchar_t *)s1)[n1 + i] = ((uchar_t *)s2)[i];
        ++i;
    }
    return (s1);
}

void *bzero(void *ptr, uint32_t len)
{
    uint32_t i;

    i = 0;
    while (i < len)
    {
        ((uchar_t *)ptr)[i] = 0;
        ++i;
    }
    return (ptr);
}
