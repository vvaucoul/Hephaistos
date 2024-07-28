/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsprintk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:02:13 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 10:11:04 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VSPRINTK_H
#define VSPRINTK_H

#include <stdarg.h>

int vsprintk(char *str, const char *format, va_list args);

#endif /* !VSPRINTK_H */