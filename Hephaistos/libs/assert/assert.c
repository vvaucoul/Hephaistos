/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:56:46 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/15 12:04:37 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assert.h"

/**
 * @brief Assertion function used to check a condition and provide debugging information if the condition is false.
 *
 * @param condition The condition to be checked.
 * @param file The name of the source file where the assertion is located.
 * @param function The name of the function where the assertion is located.
 * @param line The line number where the assertion is located.
 * @return The value of the condition.
 */
__assert_t __assert(__assert_t condition, const char *file, const char *function, int line) {
    if (condition == false) {
        printk(_RED "Asssertion failed: " _END "%s: - ["_RED
                    ".%u"_END
                    "]: "_RED
                    "%s"
                    "" _END "\n",
               file, line, function);
        pause(); // Let's kernel continue to run
        return (__ASSERT_FAILED);
    }
    return (__ASSERT_SUCCESS);
}

__assert_t __assert_msg(__assert_t condition, const char *file, const char *function, int line, const char *msg) {
    if (condition == false) {
        printk(_RED "Asssertion failed: " _END "%s: - ["_RED
                    ".%u"_END
                    "]: "_RED
                    "%s"
                    "" _END "\n",
               file, line, function);
        printk(_RED "Message: " _END "%s\n", msg);
        pause(); // Let's kernel continue to run
        return (__ASSERT_FAILED);
    }
    return (__ASSERT_SUCCESS);
}
