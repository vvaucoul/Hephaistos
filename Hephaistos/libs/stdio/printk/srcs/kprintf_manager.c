/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kprintf_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:54:20 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/20 23:05:52 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libs/stdio/printk/printk.h>
#include <libs/memory/memory.h>

size_t __kpf_manage_mod(const char *format, size_t i)
{
    __kpf_manage_space_front(1);
    --i;
    if (format[i + 1] != __DEL_MOD)
        putchar(__DEL_MOD);
    ++i;
    __kpf_manage_space_back(1);
    return (i);
}

void __kpf_manage_char()
{
    char c = va_arg(_g_printk.args, int);

    __kpf_manage_space_front(1);
    putchar(c);
    __kpf_manage_space_back(1);
}
void __kpf_manage_nbr()
{
    int nbr = va_arg(_g_printk.args, int);

    __kpf_manage_space_front(nbrlen(nbr));
    putnbr(nbr);
    __kpf_manage_space_back(nbrlen(nbr));
}

void __kpf_manage_str()
{
    char *str = va_arg(_g_printk.args, char *);

    if (str == NULL)
    {
        char __str[7];

        bzero(__str, 7);
        memcpy(__str, "(null)", 6);
        __kpf_manage_space_front(strlen(__str));
        putstr(__str);
        __kpf_manage_space_back(strlen(__str));
    }
    else
    {
        __kpf_manage_space_front(strlen(str));
        putstr(str);
        __kpf_manage_space_back(strlen(str));
    }
}

void __kpf_manage_ptr()
{
    void *ptr = va_arg(_g_printk.args, void *);
    __kpf_manage_space_front(__kptrlen(ptr));
    putptr(ptr);
    __kpf_manage_space_back(__kptrlen(ptr));
}

void __kpf_manage_hexa()
{
    hex_t nbr = va_arg(_g_printk.args, hex_t);
    __kpf_manage_space_front(nbrlen_base(nbr, 16));
    putunbr_hex(nbr);
    __kpf_manage_space_back(nbrlen_base(nbr, 16));
}

void __kpf_manage_unsigned()
{
    uint32_t nbr = va_arg(_g_printk.args, uint32_t);
    __kpf_manage_space_front(nbrlen(nbr));
    putunbr(nbr);
    __kpf_manage_space_back(nbrlen(nbr));
}

void __kpf_manage_float()
{
    double nbr = va_arg(_g_printk.args, double);
    __kpf_manage_space_front(nbrlen(nbr));
    putf(nbr);
    __kpf_manage_space_back(nbrlen(nbr));
}