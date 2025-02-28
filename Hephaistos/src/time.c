/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:11:09 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/10/20 16:56:26 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <charon.h>
#include <errno.h>
#include <time.h>

/**
 * @brief Starts the time counter by recording the current timer ticks as the start time.
 *
 * @param counter Pointer to the counter structure to be started.
 */
int counter_start(counter_t *counter) {
	if (counter == NULL) {
		return -EINVAL;
	}

	counter->start = pit_get_ticks();
	return 0;
}

/**
 * @brief Stops the time counter by recording the current timer ticks as the end time.
 *
 * @param counter Pointer to the counter structure to be stopped.
 */
int counter_stop(counter_t *counter) {
	if (counter == NULL) {
		return -EINVAL;
	}

	counter->end = pit_get_ticks();
	return 0;
}

/**
 * @brief Retrieves the start time of the counter.
 *
 * @param counter Pointer to the counter structure.
 * @return The start time of the counter.
 */
uint32_t counter_get_start(counter_t *counter) {
	if (counter == NULL) {
		return -EINVAL;
	}

	return counter->start;
}

/**
 * @brief Retrieves the end time of the counter.
 *
 * @param counter Pointer to the counter structure.
 * @return The end time of the counter.
 */
uint32_t counter_get_end(counter_t *counter) {
	if (counter == NULL) {
		return -EINVAL;
	}

	return counter->end;
}

/**
 * @brief Calculates the elapsed time between the start and end of the counter.
 *
 * @param counter Pointer to the counter structure.
 * @return The elapsed time between the start and end times of the counter.
 */
uint32_t counter_get_time(counter_t *counter) {
	if (counter == NULL) {
		return -EINVAL;
	}

	return counter->end - counter->start;
}