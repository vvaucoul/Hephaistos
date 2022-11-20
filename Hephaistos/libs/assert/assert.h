/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:56:53 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/20 14:12:20 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ASSERT_H
#define _ASSERT_H

#include <libs/stdbool/stdbool.h>
#include <libs/stdio/stdio.h>
#include <libs/stddef/stddef.h>
#include <libs/macros/macros.h>

typedef unsigned short __assert_t;

#define __ASSERT_SUCCESS 0
#define __ASSERT_FAILED 1

extern __assert_t __assert(__assert_t condition, const char *file, const char *function, int line);
#define assert(condition) __assert(((__assert_t)(condition)), __FILE__, __FUNCTION__, __LINE__)

#endif /* !_ASSERT_H */