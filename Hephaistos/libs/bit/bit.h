/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:11:32 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/22 12:46:22 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIT_H
#define BIT_H

typedef unsigned char byte_t;

/**
 * @brief Macro to create a bitmask with the bit at position x set.
 *
 * @param x Position of the bit to be set (0-indexed).
 * @return Bitmask with the bit at position x set.
 */
#define BIT(x) (1U << (x))

/**
 * @brief Macro to set the bit(s) specified by the bitmask y in the variable x.
 *
 * @param x Variable in which to set the bit(s).
 * @param y Bitmask specifying the bit(s) to set.
 */
#define BIT_SET(x, y) ((x) |= (y))

/**
 * @brief Macro to clear the bit(s) specified by the bitmask y in the variable x.
 *
 * @param x Variable in which to clear the bit(s).
 * @param y Bitmask specifying the bit(s) to clear.
 */
#define BIT_CLEAR(x, y) ((x) &= ~(y))

/**
 * @brief Macro to flip the bit(s) specified by the bitmask y in the variable x.
 *
 * @param x Variable in which to flip the bit(s).
 * @param y Bitmask specifying the bit(s) to flip.
 */
#define BIT_FLIP(x, y) ((x) ^= (y))

/**
 * @brief Macro to check if the bit(s) specified by the bitmask y are set in the variable x.
 *
 * @param x Variable in which to check the bit(s).
 * @param y Bitmask specifying the bit(s) to check.
 * @return Non-zero value if any bit specified by the bitmask y is set in x, zero otherwise.
 */
#define BIT_CHECK(x, y) ((x) & (y))

/**
 * @brief Macro to set all bits in the variable x.
 *
 * @param x Variable in which to set all bits.
 */
#define BIT_SET_ALL(x) ((x) = ~0U)

/**
 * @brief Macro to clear all bits in the variable x.
 *
 * @param x Variable in which to clear all bits.
 */
#define BIT_CLEAR_ALL(x) ((x) = 0U)

/**
 * @brief Macro to flip all bits in the variable x.
 *
 * @param x Variable in which to flip all bits.
 */
#define BIT_FLIP_ALL(x) ((x) = ~(x))

/**
 * @brief Macro to check if all bits in the variable x are set.
 *
 * @param x Variable in which to check all bits.
 * @return Non-zero value if all bits are set, zero otherwise.
 */
#define BIT_CHECK_ALL(x) ((x) == ~0U)

/**
 * @brief Macro to perform a bitwise AND operation between x and y.
 *
 * @param x First operand.
 * @param y Second operand.
 * @return Result of the bitwise AND operation.
 */
#define BIT_AND(x, y) ((x) & (y))

/**
 * @brief Macro to perform a bitwise OR operation between x and y.
 *
 * @param x First operand.
 * @param y Second operand.
 * @return Result of the bitwise OR operation.
 */
#define BIT_OR(x, y) ((x) | (y))

/**
 * @brief Macro to perform a bitwise XOR operation between x and y.
 *
 * @param x First operand.
 * @param y Second operand.
 * @return Result of the bitwise XOR operation.
 */
#define BIT_XOR(x, y) ((x) ^ (y))

/**
 * @brief Macro to perform a bitwise NAND operation between x and y.
 *
 * @param x First operand.
 * @param y Second operand.
 * @return Result of the bitwise NAND operation.
 */
#define BIT_NAND(x, y) (~(x) & (y))

/**
 * @brief Macro to perform a bitwise NOR operation between x and y.
 *
 * @param x First operand.
 * @param y Second operand.
 * @return Result of the bitwise NOR operation.
 */
#define BIT_NOR(x, y) (~(x) | (y))

/**
 * @brief Macro to perform a bitwise XNOR operation between x and y.
 *
 * @param x First operand.
 * @param y Second operand.
 * @return Result of the bitwise XNOR operation.
 */
#define BIT_XNOR(x, y) (~(x) ^ (y))

/**
 * @brief Macro to shift the bits in x to the left by y positions.
 *
 * @param x Variable to shift.
 * @param y Number of positions to shift.
 * @return Result of the left bit shift operation.
 */
#define BIT_SHIFT_LEFT(x, y) ((x) << (y))

/**
 * @brief Macro to shift the bits in x to the right by y positions.
 *
 * @param x Variable to shift.
 * @param y Number of positions to shift.
 * @return Result of the right bit shift operation.
 */
#define BIT_SHIFT_RIGHT(x, y) ((x) >> (y))

#endif /* BIT_H */
