/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:41:39 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/22 11:53:48 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
#define QUEUE_H

#include <libs/stdbool/stdbool.h>
#include <libs/stddef/stddef.h>

#define QUEUE_MAX_SIZE 128

// Queue structure
typedef struct queue {
    void *data[QUEUE_MAX_SIZE]; // Array of data pointers
    int head;                   // Index of the head
    int tail;                   // Index of the tail
    int size;                   // Current size of the queue
} queue_t;

queue_t *queue_create(void);
void queue_destroy(queue_t *queue);
bool queue_enqueue(queue_t *queue, void *data);
void *queue_dequeue(queue_t *queue);
void *queue_peek(queue_t *queue);
int queue_get_size(queue_t *queue);

#endif /* !QUEUE_H */