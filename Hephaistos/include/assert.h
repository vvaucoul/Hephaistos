/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:56:53 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/26 21:57:59 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ASSERT_H
#define _ASSERT_H

typedef unsigned short __assert_t;

#define __ASSERT_SUCCESS 0
#define __ASSERT_FAILED 1

#ifdef NDEBUG
    #define assert(condition) ((void)0)
    #define assert_msg(condition, msg) ((void)0)
#else
    #define assert(condition) __assert(((__assert_t)(condition)), __FILE__, __FUNCTION__, __LINE__)
    #define assert_msg(condition, msg) __assert_msg(((__assert_t)(condition)), __FILE__, __FUNCTION__, __LINE__, msg)
#endif

/**
 * @brief Assertion function used to check a condition and provide debugging information if the condition is false.
 *
 * @param condition The condition to be checked.
 * @param file The name of the source file where the assertion is located.
 * @param function The name of the function where the assertion is located.
 * @param line The line number where the assertion is located.
 * @return The value of the condition.
 */
extern __assert_t __assert(__assert_t condition, const char *file, const char *function, int line);

/**
 * @brief Assertion function with a message used to check a condition and provide debugging information if the condition is false.
 *
 * @param condition The condition to be checked.
 * @param file The name of the source file where the assertion is located.
 * @param function The name of the function where the assertion is located.
 * @param line The line number where the assertion is located.
 * @param msg The custom message to display if the assertion fails.
 * @return The value of the condition.
 */
extern __assert_t __assert_msg(__assert_t condition, const char *file, const char *function, int line, const char *msg);

#endif /* !_ASSERT_H */