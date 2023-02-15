/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:41:39 by vvaucoul          #+#    #+#             */
/*   Updated: 2023/02/15 17:55:22 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
#define QUEUE_H

#include <libs/stdbool/stdbool.h>
#include <libs/stddef/stddef.h>

typedef void __queue_data_t;

typedef struct s_queue_node
{
    __queue_data_t *data;
    struct s_queue_node *next;
} queue_node_t;

typedef struct s_queue
{
    queue_node_t *first;
    queue_node_t *last;
    uint32_t size;
} queue_t;

extern queue_t *queue_create(void);
extern void queue_enqueue(queue_t *queue, __queue_data_t *data);
extern __queue_data_t *queue_dequeue(queue_t *queue);
extern __queue_data_t *queue_peek(queue_t *queue);
extern void queue_destroy_with_data(queue_t *queue);
extern bool queue_is_empty(queue_t *queue);
extern uint32_t queue_size(queue_t *queue);

#endif /* !QUEUE_H */