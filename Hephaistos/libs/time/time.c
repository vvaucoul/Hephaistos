/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:11:09 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/21 14:14:38 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"
#include <passenger.h>

void counter_start(counter_t *counter)
{
    counter->start = timer_ticks;
}

void counter_end(counter_t *counter)
{
    counter->end = timer_ticks;
}

uint32_t counter_get_start(counter_t *counter)
{
    return (counter->start);
}

uint32_t counter_get_end(counter_t *counter)
{
    return (counter->end);
}

uint32_t counter_get_time(counter_t *counter)
{
    return (counter->end - counter->start);
}

