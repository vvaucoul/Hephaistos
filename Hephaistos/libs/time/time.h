/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:10:07 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/21 14:14:41 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TIME_H
#define _TIME_H

#include <libs/stddef/stddef.h>

typedef struct s_counter
{
    uint32_t start;
    uint32_t end;
} counter_t;

extern void counter_start(counter_t *counter);
extern void counter_end(counter_t *counter);
extern uint32_t counter_get_start(counter_t *counter);
extern uint32_t counter_get_end(counter_t *counter);
extern uint32_t counter_get_time(counter_t *counter);

#endif /* !_TIME_H */