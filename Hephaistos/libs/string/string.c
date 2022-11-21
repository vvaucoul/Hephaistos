/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:55:48 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/21 16:28:53 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include <libs/memory/memory.h>

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