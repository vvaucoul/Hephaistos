/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:59:13 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/20 23:03:50 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include <libs/memory/memory.h>

static uint32_t __get_nbr_base_length(uint32_t nbr, uint32_t base)
{
    uint32_t length = 0;
    while (nbr > 0)
    {
        nbr /= base;
        length++;
    }
    return (length);
}

uint32_t uitoa_base(uint32_t nbr, int base, char str[__ITOA_BUFFER_LENGTH__])
{
    int i;
    int size;

    size = __get_nbr_base_length(nbr, base);
    if (str == NULL)
        return (1);
    else
    {
        bzero(str, __ITOA_BUFFER_LENGTH__);
        for (uint8_t i = 0; i < 8; ++i)
            str[i] = '0';
    }
    i = 1;
    while (size - i >= 0)
    {
        str[size - i] = __ASCII_BASE__[nbr % base];
        nbr /= base;
        ++i;
    }
    return (0);
}

int itoa_base(int nbr, int base, char str[__ITOA_BUFFER_LENGTH__])
{
    int i;
    int size;
    int isneg;

    size = __get_nbr_base_length(nbr, base);
    if (!str)
        return (1);
    if ((isneg = ((nbr >= -2147483647 && nbr < 0) ? 1 : 0)) == 1)
        nbr *= -1;
    i = (isneg ? 1 : 1);
    while (size - i >= 0)
    {
        str[size - i] = __ASCII_BASE__[nbr % base];
        nbr /= base;
        ++i;
    }
    if (isneg)
        str[0] = '-';
    str[size] = '\0';
    return (0);
}

int atoi(const char *str)
{
    int res = 0;
    int sign = 1;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    while (*str)
    {
        res = res * 10 + (*str - '0');
        str++;
    }
    return (res * sign);
}

/*******************************************************************************
 *                             EXTERN C FUNCTIONS                              *
 ******************************************************************************/

int itoa(int nbr, char str[__ITOA_BUFFER_LENGTH__])
{
    int i;
    bool is_neg;

    if (!str)
        return (1);
    is_neg = ((nbr >= -2147483647 && nbr < 0) ? 1 : 0);
    if (is_neg)
        nbr *= -1;
    i = (is_neg ? 1 : 1);
    while (nbr)
    {
        str[__ITOA_BUFFER_LENGTH__ - i] = nbr % 10 + 48;
        nbr /= 10;
        ++i;
    }
    if (is_neg)
        str[0] = '-';
    str[__ITOA_BUFFER_LENGTH__ - i] = '\0';
    return (0);
}

int uitoa(uint32_t nbr, char str[__ITOA_BUFFER_LENGTH__])
{
    int i = 1;
    int size = 0;

    if (str == NULL)
        return (1);
    else
    {
        uint32_t __tmp_nbr = nbr;
        while (__tmp_nbr)
        {
            __tmp_nbr /= 10;
            ++size;
        }
    }
    while (nbr)
    {
        str[size - i] = nbr % 10 + 48;
        nbr /= 10;
        ++i;
    }
    str[size] = '\0';
    return (0);
}