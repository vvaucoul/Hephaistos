/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:56:46 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/21 10:21:03 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assert.h"

__assert_t __assert(__assert_t condition, const char *file, const char *function, int line)
{
    if (condition == false)
    {
        printk(_RED "Asssertion failed: " _END "%s: - ["_RED
                    ".%u"_END
                    "]: "_RED
                    "%s"
                    "" _END "\n",
               file, line, function);
        pause();
        return (__ASSERT_FAILED);
    }
    return (__ASSERT_SUCCESS);
}