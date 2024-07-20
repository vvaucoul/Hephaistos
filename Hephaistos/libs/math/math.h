/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:21:41 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/20 12:31:47 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATH_H
#define __MATH_H

#include <libs/stddef/stddef.h>

/**
 * @brief Return the absolute value of a number
 */
inline int abs(int nb) {
    return (nb < 0 ? -nb : nb);
}

/**
 * @brief Return the absolute value of a number
 */
inline float fabs(float nb) {
    return (nb < 0 ? -nb : nb);
}

/**
 * @brief Return the maximum of two numbers
 */
inline int max(int a, int b) {
    return (a > b ? a : b);
}

/**
 * @brief Return the minimum of two numbers
 */
inline int min(int a, int b) {
    return (a < b ? a : b);
}

/**
 * @brief Round a floating-point number to the nearest integer
 */
inline int round(float nb) {
    return (nb >= 0) ? (int)(nb + 0.5) : -(int)(nb - 0.5);
}

/**
 * @brief Calculate the power of a number
 */
inline float pow(float nb, float power) {
    float res = 1;

    for (uint32_t i = 0; i < (uint32_t)power; i++) {
        res *= nb;
    }
    return res;
}

/**
 * @brief Calculate the square root of a number
 */
inline float sqrt(float nb) {
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

#endif /* !__MATH_H */