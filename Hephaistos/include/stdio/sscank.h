/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sscank.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:06:05 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/31 02:02:25 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSCANK_H
#define SSCANK_H

#include <stddef.h>
#include <stdbool.h>

extern int sscank(const char *str, const char *format, ...);

int read_int(const char **str);
void read_string(const char **str, char *buffer, int max_len);
void read_float(const char **str, float *value);
void read_double(const char **str, double *value);
void read_unsigned(const char **str, unsigned int *value);
void read_hexa(const char **str, unsigned int *value);
void read_ptr(const char **str, void **value);
void read_char(const char **str, char *value);
void read_bool(const char **str, bool *value);
void read_null(const char **str, void **value);
void read_long(const char **str, long *value);
void read_long_long(const char **str, long long *value);
void read_unsigned_long(const char **str, unsigned long *value);
void read_unsigned_long_long(const char **str, unsigned long long *value);

#endif /* !SSCANK_H */