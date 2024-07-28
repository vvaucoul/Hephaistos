/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 01:58:36 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 02:01:33 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

/**
 * @brief Create a complex number
 * @param real The real part of the complex number
 * @param imag The imaginary part of the complex number
 * @return The created complex number
 */
Complex complex_create(float real, float imag) {
	Complex c;
	c.real = real;
	c.imag = imag;
	return c;
}

/**
 * @brief Add two complex numbers
 * @param a The first complex number
 * @param b The second complex number
 * @return The sum of the two complex numbers
 */
Complex complex_add(Complex a, Complex b) {
	Complex result;
	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return result;
}

/**
 * @brief Subtract one complex number from another
 * @param a The first complex number
 * @param b The second complex number
 * @return The difference of the two complex numbers
 */
Complex complex_sub(Complex a, Complex b) {
	Complex result;
	result.real = a.real - b.real;
	result.imag = a.imag - b.imag;
	return result;
}

/**
 * @brief Multiply two complex numbers
 * @param a The first complex number
 * @param b The second complex number
 * @return The product of the two complex numbers
 */
Complex complex_mul(Complex a, Complex b) {
	Complex result;
	result.real = a.real * b.real - a.imag * b.imag;
	result.imag = a.real * b.imag + a.imag * b.real;
	return result;
}

/**
 * @brief Divide one complex number by another
 * @param a The numerator complex number
 * @param b The denominator complex number
 * @return The quotient of the two complex numbers
 */
Complex complex_div(Complex a, Complex b) {
	Complex result;
	float denominator = b.real * b.real + b.imag * b.imag;
	result.real = (a.real * b.real + a.imag * b.imag) / denominator;
	result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
	return result;
}

/**
 * @brief Calculate the conjugate of a complex number
 * @param a The complex number
 * @return The conjugate of the complex number
 */
Complex complex_conj(Complex a) {
	Complex result;
	result.real = a.real;
	result.imag = -a.imag;
	return result;
}