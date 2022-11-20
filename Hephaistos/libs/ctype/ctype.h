/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:59:09 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/20 16:53:59 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CTYPE_H
# define _CTYPE_H

#include <libs/stdbool/stdbool.h>
#include <libs/stddef/stddef.h>

extern bool isalnum(uchar_t c);
extern bool isalpha(uchar_t c);
extern bool isblank(uchar_t c);
extern bool iscntrl(uchar_t c);
extern bool isdigit(uchar_t c);
extern bool isgraph(uchar_t c);
extern bool islower(uchar_t c);
extern bool isprint(uchar_t c);
extern bool ispunct(uchar_t c);
extern bool isupper(uchar_t c);
extern bool isxdigit(uchar_t c);
extern bool isascii(uchar_t c);

extern uchar_t toascii(uchar_t c);
extern uchar_t tolower(uchar_t c);
extern uchar_t toupper(uchar_t c);

#endif /* !_CTYPE_H */