/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:10:07 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 01:55:15 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TIME_H
#define _TIME_H

#include <stdint.h>

typedef struct s_counter {
	uint32_t start;
    uint32_t end;
} counter_t;

extern int counter_start(counter_t *counter);
extern int counter_stop(counter_t *counter);
extern uint32_t counter_get_start(counter_t *counter);
extern uint32_t counter_get_end(counter_t *counter);
extern uint32_t counter_get_time(counter_t *counter);

#endif /* !_TIME_H */