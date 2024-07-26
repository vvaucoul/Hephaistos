/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:44:27 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/21 13:51:30 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio/printk.h>
#include <convert.h>

static void __vsprintk(const char *str, void (*write)(const char), const char *format, uint32_t *pos, va_list arg)
{
    for (size_t i = 0; str[i]; i++)
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 's')
            {
                const char *s = va_arg(arg, const char *);
                __vsprintk(s, write, format, pos, arg);
            }
            else if (str[i] == 'd')
            {
                char buffer[__ITOA_BUFFER_LENGTH__];
                int d = va_arg(arg, int);
                itoa(d, buffer);
                char *s = buffer;
                __vsprintk(s, write, format, pos, arg);
            }
            else if (str[i] == 'c')
            {
                char c = va_arg(arg, int);
                write(c);
            }
            else if (str[i] == 'x')
            {
                char buffer[__ITOA_BUFFER_LENGTH__];
                int d = va_arg(arg, int);
                itoa_base(d, 16, buffer);
                char *s = buffer;
                __vsprintk(s, write, format, pos, arg);
            }
            else if (str[i] == 'p')
            {
                char buffer[__ITOA_BUFFER_LENGTH__];
                int d = va_arg(arg, int);
                itoa_base(d, 16, buffer);
                char *s = buffer;
                __vsprintk(s, write, format, pos, arg);
            }
            else if (str[i] == 'u')
            {
                char buffer[__ITOA_BUFFER_LENGTH__];
                int d = va_arg(arg, uint32_t);
                itoa_base(d, 10, buffer);
                char *s = buffer;
                __vsprintk(s, write, format, pos, arg);
            }
            else if (str[i] == '%')
            {
                write('%');
            }
        }
        else
        {
            write(str[i]);
        }
    }
}

void vsprintk(const char *str, void (*write)(const char), const char *format, va_list arg)
{
    uint32_t pos = 0;
    __vsprintk(str, write, format, &pos, arg);
}