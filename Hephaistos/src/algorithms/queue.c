/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:44:24 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/26 22:05:39 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/queue.h>
#include <charon.h>

/**
 * Creates a new queue.
 *
 * @return A pointer to the newly created queue, or NULL if memory allocation failed.
 */
queue_t *queue_create(void) {
    queue_t *queue = (queue_t *)kmalloc(sizeof(queue_t));
    if (!queue) {
        return NULL; // Memory allocation failed
    }
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    return queue;
}

/**
 * Destroys a queue and frees the associated memory.
 *
 * @param queue The queue to destroy.
 */
void queue_destroy(queue_t *queue) {
    if (queue) {
        kfree(queue);
    }
}

/**
 * Enqueues an element into the queue.
 *
 * @param queue The queue to enqueue the element into.
 * @param data The element to enqueue.
 * @return true if the element was successfully enqueued, false if the queue is full or NULL.
 */
bool queue_enqueue(queue_t *queue, void *data) {
    if (!queue || queue->size >= QUEUE_MAX_SIZE) {
        return false; // Queue is full or NULL
    }
    queue->data[queue->tail] = data;
    queue->tail = (queue->tail + 1) % QUEUE_MAX_SIZE;
    queue->size++;
    return true;
}

/**
 * Dequeues an element from the queue.
 *
 * @param queue The queue to dequeue the element from.
 * @return A pointer to the dequeued element, or NULL if the queue is empty or NULL.
 */
void *queue_dequeue(queue_t *queue) {
    if (!queue || queue->size == 0) {
        return NULL; // Queue is empty or NULL
    }
    void *data = queue->data[queue->head];
    queue->head = (queue->head + 1) % QUEUE_MAX_SIZE;
    queue->size--;
    return data;
}

/**
 * Retrieves the element at the front of the queue without removing it.
 *
 * @param queue The queue to peek the element from.
 * @return A pointer to the element at the front of the queue, or NULL if the queue is empty or NULL.
 */
void *queue_peek(queue_t *queue) {
    if (!queue || queue->size == 0) {
        return NULL; // Queue is empty or NULL
    }
    return queue->data[queue->head];
}

/**
 * Retrieves the size of the queue.
 *
 * @param queue The queue to get the size of.
 * @return The size of the queue, or -1 if the queue is NULL.
 */
int queue_get_size(queue_t *queue) {
    if (!queue) {
        return -1; // Queue is NULL
    }
    return queue->size;
}