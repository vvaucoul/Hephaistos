/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:24:25 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/14 12:34:34 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctype.h"

bool isalnum(uchar_t c) {
    return (isalpha(c) || isdigit(c));
}

bool isalpha(uchar_t c) {
    return (islower(c) || isupper(c));
}

bool isblank(uchar_t c) {
    return (c == ' ' || c == '\t');
}

bool iscntrl(uchar_t c) {
    return (c >= 0 && c <= 31) || c == 127;
}

bool isdigit(uchar_t c) {
    return (c >= '0' && c <= '9');
}

bool isgraph(uchar_t c) {
    return (c >= 33 && c <= 126);
}

bool islower(uchar_t c) {
    return (c >= 'a' && c <= 'z');
}

bool isprint(uchar_t c) {
    return (c >= 32 && c <= 126);
}

bool ispunct(uchar_t c) {
    return (isgraph(c) && !isalnum(c));
}

bool isupper(uchar_t c) {
    return (c >= 'A' && c <= 'Z');
}

bool isxdigit(uchar_t c) {
    return (isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

bool isascii(uchar_t c) {
    return (c >= 0 && c <= 127);
}

uchar_t toascii(uchar_t c) {
    return (c & 0x7F);
}

uchar_t tolower(uchar_t c) {
    return (isupper(c) ? c + 32 : c);
}

uchar_t toupper(uchar_t c) {
    return (islower(c) ? c - 32 : c);
}