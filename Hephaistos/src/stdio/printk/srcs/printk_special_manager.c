/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printk_special_manager.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:59:37 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 01:12:20 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio/printk.h>
#include <stdbool.h>

void __kpf_manage_space_front(const int arg_len) {
    if (_g_printk.space - arg_len > 0) {
        if (_g_printk.is_neg_space == false) {
            for (int i = 0; i < _g_printk.space - arg_len; i++) {
                if (_g_printk.use_zero == true)
                    putchar('0');
                else
                    putchar(' ');
            }
            _g_printk.space = 0;
        }
    }
}

void __kpf_manage_space_back(const int arg_len) {
    if (_g_printk.space - arg_len > 0) {
        if (_g_printk.is_neg_space == true) {
            for (int i = 0; i < _g_printk.space - arg_len; i++) {
                if (_g_printk.use_zero == true)
                    putchar('0');
                else
                    putchar(' ');
            }
            _g_printk.space = 0;
        }
    }
}
