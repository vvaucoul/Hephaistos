/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:11:09 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/23 13:53:53 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"
#include <charon.h>

/**
 * @brief Starts the time counter by recording the current timer ticks as the start time.
 *
 * @param counter Pointer to the counter structure to be started.
 */
void counter_start(counter_t *counter) {
    assert(counter != NULL);
    counter->start = pit_get_ticks();
}

/**
 * @brief Stops the time counter by recording the current timer ticks as the end time.
 *
 * @param counter Pointer to the counter structure to be stopped.
 */
void counter_stop(counter_t *counter) {
    assert(counter != NULL);
    counter->end = pit_get_ticks();
}

/**
 * @brief Retrieves the start time of the counter.
 *
 * @param counter Pointer to the counter structure.
 * @return The start time of the counter.
 */
uint32_t counter_get_start(counter_t *counter) {
    assert(counter != NULL);
    return counter->start;
}

/**
 * @brief Retrieves the end time of the counter.
 *
 * @param counter Pointer to the counter structure.
 * @return The end time of the counter.
 */
uint32_t counter_get_end(counter_t *counter) {
    assert(counter != NULL);
    return counter->end;
}

/**
 * @brief Calculates the elapsed time between the start and end of the counter.
 *
 * @param counter Pointer to the counter structure.
 * @return The elapsed time between the start and end times of the counter.
 */
uint32_t counter_get_time(counter_t *counter) {
    assert(counter != NULL);
    return counter->end - counter->start;
}