/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:41:39 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/15 13:03:06 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
#define QUEUE_H

#include <libs/stdbool/stdbool.h>
#include <libs/stddef/stddef.h>

#define QUEUE_MAX_SIZE 128

typedef struct queue {
    void *data[QUEUE_MAX_SIZE];
    int head;
    int tail;
    int size;
} queue_t;

extern queue_t *queue_create(void);
extern void queue_destroy(queue_t *queue);
extern void queue_enqueue(queue_t *queue, void *data);
extern void *queue_dequeue(queue_t *queue);
extern void *queue_peek(queue_t *queue);
extern int queue_get_size(queue_t *queue);

#endif /* !QUEUE_H */