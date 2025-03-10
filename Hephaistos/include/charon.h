/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:47:12 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/10/23 18:32:12 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHARON_H
#define _CHARON_H

/*
** Hephaistos CHARON:
** Passing functions prototypes from KronOS to Hephaistos library
*/

#ifndef __HEPHAISTOS__
#define __HEPHAISTOS__
#include <drivers/tty.h>
// #include <kernel.h>
#include <mm/kheap.h>
#include <mm/mm.h>
#include <system/pit.h>

#define IS_MEMORY_AVAILABLE (kheap != NULL)

#endif

#endif /* !_CHARON_H */