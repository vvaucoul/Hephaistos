/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:59:09 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/26 22:12:15 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CTYPE_H
#define _CTYPE_H

#include <stdbool.h>

extern bool isalnum(int c);
extern bool isalpha(int c);
extern bool isblank(int c);
extern bool iscntrl(int c);
extern bool isdigit(int c);
extern bool isgraph(int c);
extern bool islower(int c);
extern bool isprint(int c);
extern bool ispunct(int c);
extern bool isupper(int c);
extern bool isxdigit(int c);
extern bool isascii(int c);
extern bool isspace(int c);

extern int toascii(int c);
extern int tolower(int c);
extern int toupper(int c);

#endif /* !_CTYPE_H */