/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:30:23 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/26 21:59:24 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

/**
 * @brief Calculate the natural logarithm of a number
 * @param x The number to calculate the natural logarithm for
 * @return The natural logarithm of x
 */
float ln(float x) {
    float result = 0.0;
    float term = (x - 1) / (x + 1);
    float term_squared = term * term;
    float current_term = term;
    int n;

    for (n = 1; n <= 100; n += 2) {
        result += current_term / n;
        current_term *= term_squared;
    }

    return 2 * result;
}

/**
 * @brief Calculate the sine of an angle in radians
 * @param x The angle in radians
 * @return The sine of the angle
 */
float sin(float x) {
    float result = x;
    float term = x;
    for (int n = 1; n <= 10; ++n) {
        term *= -x * x / (2 * n * (2 * n + 1));
        result += term;
    }
    return result;
}

/**
 * @brief Calculate the cosine of an angle in radians
 * @param x The angle in radians
 * @return The cosine of the angle
 */
float cos(float x) {
    float result = 1.0;
    float term = 1.0;
    for (int n = 1; n <= 10; ++n) {
        term *= -x * x / (2 * n * (2 * n - 1));
        result += term;
    }
    return result;
}


/**
 * @brief Calculate the exponential function of a number
 * @param x The number to calculate the exponential for
 * @return The exponential of x
 */
float exp(float x) {
    float result = 1.0;
    float term = 1.0;
    for (int n = 1; n <= 10; ++n) {
        term *= x / n;
        result += term;
    }
    return result;
}

/**
 * @brief Calculate the tangent of an angle in radians
 * @param x The angle in radians
 * @return The tangent of the angle
 */
float tan(float x) {
    return sin(x) / cos(x);
}

/**
 * @brief Clamp a value between a minimum and a maximum
 * @param value The value to clamp
 * @param min The minimum value
 * @param max The maximum value
 * @return The clamped value
 */
int clamp(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

/**
 * @brief Calculate the hypotenuse of a right-angled triangle
 * @param x The length of the first leg
 * @param y The length of the second leg
 * @return The length of the hypotenuse
 */
float hypot(float x, float y) {
    return sqrt(x * x + y * y);
}

/**
 * @brief Return the sign of a number
 * @param x The number
 * @return 1 if x is positive, -1 if x is negative, 0 if x is zero
 */
int signum(float x) {
    return (x > 0) - (x < 0);
}