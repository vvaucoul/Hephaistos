/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:55:48 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/20 18:17:02 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include <libs/memory/memory.h>

uint32_t strlen(const char *str)
{
    uint32_t i = 0;

    while (str[i])
        ++i;
    return (i);
}

uint32_t nbrlen(int nbr)
{
    uint32_t i = 0;

    if (nbr < 0)
    {
        nbr *= -1;
        ++i;
    }
    while (nbr >= 10)
    {
        nbr /= 10;
        ++i;
    }
    return (i + 1);
}

uint32_t ptrlen(void *ptr)
{
    uint32_t len = 0;
    unsigned char *p = (unsigned char *)ptr;

    if (ptr == NULL)
        return (0);
    while (*p)
    {
        len++;
        p++;
    }
    return (len);
}

uint32_t nbrlen_base(const uint32_t nbr, const uint8_t base)
{
    uint32_t len;
    uint32_t n_nbr = nbr;

    len = 0;
    if (n_nbr == 0)
        return (1);
    while (n_nbr)
    {
        n_nbr /= base;
        ++len;
    }
    return (len);
}

uint32_t unbrlen(uint32_t nbr)
{
    uint32_t i = 0;

    while (nbr >= 10)
    {
        nbr /= 10;
        ++i;
    }
    return (i + 1);
}

int32_t strcmp(const char *s1, const char *s2)
{
    int i;

    if (s1 == NULL || s2 == NULL)
        return (-1);
    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int32_t strncmp(const char *s1, const char *s2, uint32_t n)
{
    unsigned long int i;

    if (n == 0 || s1 == NULL || s2 == NULL)
        return (0);
    i = 0;
    while (i < n && (unsigned char)s1[i] == (unsigned char)s2[i])
    {
        if (((unsigned char)s1[i] == 0 &&
             (unsigned char)s2[i] == 0) ||
            i == (n - 1))
            return (0);
        ++i;
    }
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char *strclr(char *new_str, char *str)
{
    if (str == NULL)
        return (NULL);
    bzero(new_str, strlen(new_str));

    size_t i = 0;
    /* Skip all firsts spaces */
    while (str[i] && str[i] == ' ')
        i++;

    size_t j = 0;

    /* Skip all spaces in the string */
    while (str[i])
    {
        if (str[i] == ' ')
        {
            while (str[i] && str[i] == ' ')
                i++;
            if (str[i] == '\0')
                break;
            new_str[j] = ' ';
            j++;
        }
        new_str[j] = str[i];
        i++;
        j++;
    }
    new_str[j] = '\0';
    return (new_str);
}