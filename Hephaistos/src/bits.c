/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:30:59 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/10/24 10:31:42 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits.h>

/**
 * @brief Counts the number of set bits (1s) in a given byte.
 *
 * This function takes an 8-bit unsigned integer (uint8_t) as input and
 * returns the number of bits that are set to 1 in its binary representation.
 *
 * @param byte The 8-bit unsigned integer whose set bits are to be counted.
 * @return The number of set bits in the input byte.
 */
uint32_t count_set_bits(uint8_t byte) {
	uint32_t count = 0;
	while (byte) {
		count += byte & 1;
		byte >>= 1;
	}
	return count;
}