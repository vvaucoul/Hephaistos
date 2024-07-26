/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snprintk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 23:57:41 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/26 20:07:01 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNPRINTK_H
#define SNPRINTK_H

#include <stddef.h>

extern int snprintk(char *str, uint32_t size, const char *format, ...);

#endif /* !SNPRINTK_H */