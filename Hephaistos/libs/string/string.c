/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:55:48 by vvaucoul          #+#    #+#             */
/*   Updated: 2023/02/12 11:35:31 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include <libs/memory/memory.h>

#include <charon.h>

char *strcpy(char *dest, const char *src)
{
    if (dest == NULL || src == NULL)
        return (NULL);

    uint32_t i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *strncpy(char *dest, const char *src, size_t n)
{
    if (dest == NULL || src == NULL)
        return (NULL);

    uint32_t i = 0;
    while (src[i] && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

/**
 * @brief Truncate a string at the first occurence of a char
 *
 * @param str
 * @param c
 * @return char*
 */
char *strtrtc(const char *str, const char c)
{
    if (str == NULL)
        return (NULL);

    char *new_str = kmalloc(sizeof(char) * strlen(str) + 1);
    if (new_str == NULL)
        return (NULL);

    bzero(new_str, strlen(str) + 1);

    uint32_t i = 0;
    while (str[i] && str[i] != c)
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}

/**
 * @brief Clear all spaces in a string
 *
 * @param new_str
 * @param str
 * @return char*
 */
char *strclr(char *new_str, char *str)
{
    if (str == NULL)
        return (NULL);
    bzero(new_str, strlen(new_str));

    uint32_t i = 0;
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