/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:06:11 by vvaucoul          #+#    #+#             */
/*   Updated: 2023/02/11 20:43:22 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libs/stdio/printk/printk.h>
#include <charon.h>

printk_t _g_printk;

static int check_special_strings(const char *str)
{
    if (strncmp(str, _CURSOR_MOVE_UP, strlen(_CURSOR_MOVE_UP)) == 0)
    {
        terminal_move_cursor_up();
        return (strlen(_CURSOR_MOVE_UP));
    }
    return (0);
}

static int check_colors(const char *str)
{
    if (strncmp(str, _END, strlen(_END)) == 0)
    {
        terminal_setcolor(VGA_COLOR_LIGHT_GREY);
        return (strlen(_END));
    }
    else if (strncmp(str, _RED, strlen(_RED)) == 0)
    {
        terminal_setcolor(VGA_COLOR_RED);
        return (strlen(_RED));
    }
    else if (strncmp(str, _GREEN, strlen(_GREEN)) == 0)
    {
        terminal_setcolor(VGA_COLOR_GREEN);
        return (strlen(_GREEN));
    }
    else if (strncmp(str, _BLUE, strlen(_BLUE)) == 0)
    {
        terminal_setcolor(VGA_COLOR_BLUE);
        return (strlen(_BLUE));
    }
    else if (strncmp(str, _YELLOW, strlen(_YELLOW)) == 0)
    {
        terminal_setcolor(VGA_COLOR_BROWN);
        return (strlen(_YELLOW));
    }
    else if (strncmp(str, _MAGENTA, strlen(_MAGENTA)) == 0)
    {
        terminal_setcolor(VGA_COLOR_MAGENTA);
        return (strlen(_MAGENTA));
    }
    else if (strncmp(str, _CYAN, strlen(_CYAN)) == 0)
    {
        terminal_setcolor(VGA_COLOR_CYAN);
        return (strlen(_CYAN));
    }
    return (0);
}

static int kprint_mod(const char *format, size_t i)
{

    /* CHECK SPECIAL DELIMITERS */

    // SPACES
    if (format[i] == __SPE_NEG)
    {
        _g_printk.is_neg_space = true;
        ++i;
    }
    else
        _g_printk.is_neg_space = false;

    if (format[i] == __SPE_ZERO)
    {
        _g_printk.use_zero = true;
        ++i;
    }
    else
        _g_printk.use_zero = false;

    int nbr = 0;
    while (isdigit(format[i]))
    {
        nbr = nbr * 10 + format[i] - 0x30;
        i++;
    }
    _g_printk.space = nbr;

    /* CHECK BASIC DELIMITERS */

    if (format[i] == __DEL_MOD)
        i = __kpf_manage_mod(format, i);
    else if (format[i] == __DEL_C)
        __kpf_manage_char();
    else if (format[i] == __DEL_D || format[i] == __DEL_I)
        __kpf_manage_nbr();
    else if (format[i] == __DEL_S)
        __kpf_manage_str();
    else if (format[i] == __DEL_P)
        __kpf_manage_ptr();
    else if (format[i] == __DEL_U)
        __kpf_manage_unsigned();
    else if (format[i] == __DEL_X)
        __kpf_manage_hexa();
    else if (format[i] == __DEL_F)
        __kpf_manage_float();
    return (i);
}

static int kprintf_loop(const char *format)
{
    size_t i = 0;
    int ret = 0;

    while (format[i])
    {
        if ((ret = (check_colors(format + i))) != 0)
        {
            i += ret;
            continue;
        }
        else if ((ret = (check_special_strings(format + i))) != 0)
        {
            i += ret;
            continue;
        }
        else
            ret = 0;
        if (format[i] == __DEL_MOD)
        {
            i++;
            i = kprint_mod(format, i);
        }
        else
        {
            terminal_putchar(format[i]);
        }
        ++i;
    }
    return (0);
}

uint32_t printk(const char *format, ...)
{
    int ret;

    _g_printk.is_neg_space = false;
    _g_printk.space = 0;
    _g_printk.use_zero = false;

    va_start(_g_printk.args, format);
    ret = kprintf_loop(format);
    va_end(_g_printk.args);
    UPDATE_CURSOR();
    return (ret);
}