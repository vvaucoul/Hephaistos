/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:55:48 by vvaucoul          #+#    #+#             */
/*   Updated: 2023/02/17 09:08:58 by vvaucoul         ###   ########.fr       */
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

char *strcat(char *dest, const char *src)
{
    if (dest == NULL || src == NULL)
        return (NULL);

    uint32_t i = 0;
    uint32_t j = 0;
    while (dest[i])
        i++;
    while (src[j])
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}

char *strjoin(char *s1, char *s2)
{
    if (s1 == NULL || s2 == NULL)
        return (NULL);

    char *new_str = kmalloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
    if (new_str == NULL)
        return (NULL);

    bzero(new_str, strlen(s1) + strlen(s2) + 1);

    strcpy(new_str, s1);
    strcat(new_str, s2);
    return (new_str);
}

char *strchr(const char *s, int c)
{
    if (s == NULL)
        return (NULL);

    uint32_t i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return ((char *)&s[i]);
        i++;
    }
    return (NULL);
}

char *strrchr(const char *s, int c)
{
    if (s == NULL)
        return (NULL);

    uint32_t i = strlen(s);
    while (i > 0)
    {
        if (s[i] == c)
            return ((char *)&s[i]);
        i--;
    }
    return (NULL);
}

char *strdup(const char *s)
{
    if (s == NULL)
        return (NULL);

    char *new_str = kmalloc(sizeof(char) * strlen(s) + 1);
    if (new_str == NULL)
        return (NULL);

    bzero(new_str, strlen(s) + 1);

    strcpy(new_str, s);
    return (new_str);
}

char *strndup(const char *s, size_t n)
{
    if (s == NULL)
        return (NULL);

    char *new_str = kmalloc(sizeof(char) * n + 1);
    if (new_str == NULL)
        return (NULL);

    bzero(new_str, n + 1);

    strncpy(new_str, s, n);
    return (new_str);
}

char *strtrim(char const *s)
{
    if (s == NULL)
        return (NULL);

    char *new_str = kmalloc(sizeof(char) * strlen(s) + 1);
    if (new_str == NULL)
        return (NULL);

    bzero(new_str, strlen(s) + 1);

    strclr(new_str, (char *)s);
    return (new_str);
}

char *strsub(char const *s, unsigned int start, size_t len)
{
    if (s == NULL)
        return (NULL);

    char *new_str = kmalloc(sizeof(char) * len + 1);
    if (new_str == NULL)
        return (NULL);

    bzero(new_str, len + 1);

    strncpy(new_str, &s[start], len);
    return (new_str);
}

char **strsplit(char const *s, char c)
{
    if (s == NULL)
        return (NULL);

    char *new_str = strtrim(s);
    if (new_str == NULL)
        return (NULL);

    uint32_t i = 0;
    uint32_t j = 0;
    uint32_t k = 0;
    uint32_t nb_words = 0;

    while (new_str[i])
    {
        if (new_str[i] == c)
            nb_words++;
        i++;
    }
    nb_words++;

    char **tab = kmalloc(sizeof(char *) * (nb_words + 1));
    if (tab == NULL)
        return (NULL);

    i = 0;
    while (new_str[i])
    {
        if (new_str[i] == c)
        {
            tab[j] = strsub(new_str, k, i - k);
            j++;
            k = i + 1;
        }
        i++;
    }
    tab[j] = strsub(new_str, k, i - k);
    tab[j + 1] = NULL;
    kfree(new_str);
    return (tab);
}

char *strtok(char *str, const char *delim)
{
    static char *last;
    char *token;

    if (str == NULL)
        str = last;

    str += strspn(str, delim);
    if (*str == '\0')
        return (NULL);

    token = str;
    str = strpbrk(token, delim);
    if (str == NULL)
        last = NULL;
    else
    {
        *str = '\0';
        last = str + 1;
    }
    return (token);
}
