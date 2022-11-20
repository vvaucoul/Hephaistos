/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:11:32 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/20 16:54:26 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BIT_H
# define _BIT_H

typedef unsigned char byte_t;

#define BIT(x) (1 << (x))
#define BIT_SET(x, y) ((x) |= (y))
#define BIT_CLEAR(x, y) ((x) &= ~(y))
#define BIT_FLIP(x, y) ((x) ^= (y))
#define BIT_CHECK(x, y) ((x) & (y))

#define BIT_SET_ALL(x) ((x) = ~0)
#define BIT_CLEAR_ALL(x) ((x) = 0)
#define BIT_FLIP_ALL(x) ((x) = ~(x))
#define BIT_CHECK_ALL(x) ((x) == ~0)

#define BIT_AND(x, y) ((x) & (y))
#define BIT_OR(x, y) ((x) | (y))
#define BIT_XOR(x, y) ((x) ^ (y))
#define BIT_NAND(x, y) (~(x) & (y))
#define BIT_NOR(x, y) (~(x) | (y))
#define BIT_XNOR(x, y) (~(x) ^ (y))

#define BIT_SHIFT_LEFT(x, y) ((x) << (y))
#define BIT_SHIFT_RIGHT(x, y) ((x) >> (y))

#endif /* !_BIT_H */