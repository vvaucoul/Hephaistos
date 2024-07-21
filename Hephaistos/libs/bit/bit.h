/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:11:32 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/22 00:05:48 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIT_H
#define BIT_H

typedef unsigned char byte_t;

/* Bit manipulation macros */
#define BIT(x) (1U << (x))
#define BIT_SET(x, y) ((x) |= (y))
#define BIT_CLEAR(x, y) ((x) &= ~(y))
#define BIT_FLIP(x, y) ((x) ^= (y))
#define BIT_CHECK(x, y) ((x) & (y))

#define BIT_SET_ALL(x) ((x) = ~0U)
#define BIT_CLEAR_ALL(x) ((x) = 0U)
#define BIT_FLIP_ALL(x) ((x) = ~(x))
#define BIT_CHECK_ALL(x) ((x) == ~0U)

#define BIT_AND(x, y) ((x) & (y))
#define BIT_OR(x, y) ((x) | (y))
#define BIT_XOR(x, y) ((x) ^ (y))
#define BIT_NAND(x, y) (~(x) & (y))
#define BIT_NOR(x, y) (~(x) | (y))
#define BIT_XNOR(x, y) (~(x) ^ (y))

#define BIT_SHIFT_LEFT(x, y) ((x) << (y))
#define BIT_SHIFT_RIGHT(x, y) ((x) >> (y))

#endif /* BIT_H */