/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:44:24 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/15 13:12:45 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <charon.h>

/**
 * @brief Creates a new queue.
 *
 * @return A pointer to the newly created queue.
 */
queue_t *queue_create(void) {
    queue_t *queue = kmalloc(sizeof(queue_t));

    if (queue == NULL) {
        return (NULL);
    }

    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;

    return (queue);
}

/**
 * @brief Destroys a queue and frees the allocated memory.
 *
 * This function destroys the given queue and frees the memory allocated for it.
 *
 * @param queue The queue to be destroyed.
 */
void queue_destroy(queue_t *queue) {
    if (queue == NULL) {
        return;
    }
    kfree(queue);
}

/**
 * @brief Adds an element to the back of the queue.
 *
 * This function adds the specified data to the back of the queue.
 *
 * @param queue The queue to add the element to.
 * @param data The data to be added to the queue.
 */
void queue_enqueue(queue_t *queue, void *data) {
    if (queue == NULL) {
        return;
    } else {
        queue->data[queue->tail] = data;
        queue->tail = (queue->tail + 1) % QUEUE_MAX_SIZE;
        queue->size += 1;
    }
}

/**
 * @brief Removes and returns the front element from the queue.
 *
 * This function removes the front element from the specified queue and returns it.
 *
 * @param queue A pointer to the queue from which to dequeue the element.
 * @return A pointer to the element that was dequeued from the queue, or NULL if the queue is empty.
 */
void *queue_dequeue(queue_t *queue) {
    void *data = NULL;

    if (queue == NULL) {
        return (NULL);
    } else {
        data = queue->data[queue->head];
        queue->head = (queue->head + 1) % QUEUE_MAX_SIZE;
        queue->size -= 1;
    }
    return (data);
}

/**
 * @brief Retrieves the front element of the queue without removing it.
 *
 * This function returns a pointer to the front element of the queue without modifying the queue itself.
 *
 * @param queue A pointer to the queue.
 * @return A pointer to the front element of the queue, or NULL if the queue is empty.
 */
void *queue_peek(queue_t *queue) {
    void *data = NULL;

    if (queue == NULL) {
        return (NULL);
    } else {
        data = queue->data[queue->head];
    }
    return (data);
}

/**
 * @brief Retrieves the number of elements in the queue.
 *
 * This function returns the number of elements currently in the queue.
 *
 * @param queue A pointer to the queue.
 * @return The number of elements in the queue.
 */
int queue_get_size(queue_t *queue) {
    if (queue == NULL) {
        return (0);
    } else {
        return (queue->size);
    }
}
