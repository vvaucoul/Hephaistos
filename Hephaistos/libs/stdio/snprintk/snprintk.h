/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snprintk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 23:57:41 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/21 11:16:32 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNPRINTK_H
#define SNPRINTK_H

#include <libs/ctype/ctype.h>
#include <libs/stdarg/stdarg.h>
#include <libs/stdbool/stdbool.h>
#include <libs/stddef/stddef.h>
#include <libs/stdio/stdio.h>
#include <libs/string/string.h>

extern int snprintk(char *str, uint32_t size, const char *format, ...);

#endif /* !SNPRINTK_H */