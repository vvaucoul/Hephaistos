/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:56:53 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/15 12:05:23 by vvaucoul         ###   ########.fr       */
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
extern __assert_t __assert_msg(__assert_t condition, const char *file, const char *function, int line, const char *msg);

#define assert(condition) __assert(((__assert_t)(condition)), __FILE__, __FUNCTION__, __LINE__)
#define assert_msg(condition, msg) __assert_msg(((__assert_t)(condition)), __FILE__, __FUNCTION__, __LINE__, msg)

#endif /* !_ASSERT_H */