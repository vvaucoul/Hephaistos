/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:47:12 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/26 22:15:11 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHARON_H
#define _CHARON_H

#pragma once

/*
** Hephaistos CHARON:
** Passing functions prototypes from KronOS to Hephaistos library
*/

#ifndef __HEPHAISTOS__
#define __HEPHAISTOS__
#include <drivers/vga.h>
// #include <kernel.h>
#include <memory/memory.h>
// #include <system/pit.h>

#define IS_MEMORY_AVAILABLE (kheap != NULL)

#endif

#endif /* !_CHARON_H */