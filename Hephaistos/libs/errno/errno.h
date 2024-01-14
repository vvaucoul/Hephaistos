/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:57:31 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/14 12:06:38 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ERRNO_H
#define _ERRNO_H

typedef int errno_t;

#define EINVAL 1 // Invalid argument
#define ERANGE 2 // Result too large
#define EDOM   3 // Domain error
#define EILSEQ 4 // Illegal byte sequence
#define ENOENT 5 // No such file or directory
#define EIO    6 // Error input/output
#define ENOMEM 7 // Not enough memory
#define EACCES 8 // Permission denied
#define EBUSY  9 // Device or resource busy
#define EEXIST 10 // File exists

#endif /* !_ERRNO_H */