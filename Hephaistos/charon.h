/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:47:12 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/02/08 22:10:02 by vvaucoul         ###   ########.fr       */
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
#include <kernel.h>
#include <drivers/vga.h>
#include <memory/kheap.h>
#include <system/pit.h>
#endif

#endif /* !_CHARON_H */