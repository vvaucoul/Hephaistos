/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:21:41 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/10/21 10:29:47 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MATH_H
#define _MATH_H

/**
 * @file math.h
 * @brief Header file for mathematical operations.
 */

#include <stdint.h>

/**
 * @brief Return the absolute value of a number
 */
extern inline int abs(int nb) {
	return (nb < 0 ? -nb : nb);
}

/**
 * @brief Return the absolute value of a number
 */
extern inline float fabs(float nb) {
	return (nb < 0 ? -nb : nb);
}

/**
 * @brief Return the maximum of two numbers
 */
extern inline int max(int a, int b) {
	return (a > b ? a : b);
}

/**
 * @brief Return the minimum of two numbers
 */
extern inline int min(int a, int b) {
	return (a < b ? a : b);
}

/**
 * @brief Round a floating-point number to the nearest integer
 */
extern inline int round(float nb) {
	return (nb >= 0) ? (int)(nb + 0.5) : -(int)(nb - 0.5);
}

/**
 * @brief Calculate the power of a number
 */
extern inline float pow(float nb, float power) {
	float res = 1;

	for (uint32_t i = 0; i < (uint32_t)power; i++) {
		res *= nb;
	}
	return res;
}

/**
 * @brief Calculate the square root of a number
 */
extern inline float sqrt(float nb) {
	return pow(nb, 0.5);
}

extern float ln(float x);
extern float sin(float x);
extern float cos(float x);
extern float exp(float x);
extern float tan(float x);
extern int clamp(int value, int min, int max);
extern float hypot(float x, float y);
extern int signum(float x);

/**
 * @struct Complex
 * @brief Represents a complex number with real and imaginary parts.
 */
typedef struct {
	float real;
	float imag;
} Complex;

Complex complex_create(float real, float imag);
Complex complex_add(Complex a, Complex b);
Complex complex_sub(Complex a, Complex b);
Complex complex_mul(Complex a, Complex b);
Complex complex_div(Complex a, Complex b);
Complex complex_conj(Complex a);

#endif /* !_MATH_H */