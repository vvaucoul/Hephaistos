/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stddef.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:08:03 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/26 20:10:30 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STDDEF_H
#define _STDDEF_H

/* Define NULL */
#ifndef NULL
#define NULL ((void*)0)
#endif

/* Define size_t */
typedef unsigned long size_t;

/* Define ptrdiff_t */
typedef long ptrdiff_t;

/* Define wchar_t */
#ifndef __cplusplus
typedef unsigned short wchar_t;
#endif

/* Macro to compute the offset of a member in a structure */
#define offsetof(type, member) ((size_t)&(((type *)0)->member))

#endif /* !_STDDEF_H */