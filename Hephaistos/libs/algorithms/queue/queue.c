/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:44:24 by vvaucoul          #+#    #+#             */
/*   Updated: 2023/02/15 17:55:17 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <charon.h>

/*******************************************************************************
 *                               QUEUE FUNCTIONS                               *
 ******************************************************************************/

static queue_t *__queue_create(void)
{
    queue_t *queue = (queue_t *)kmalloc(sizeof(queue_t));
    queue->first = NULL;
    queue->last = NULL;
    queue->size = 0;
    return (queue);
}

static void __queue_enqueue(queue_t *queue, __queue_data_t *data)
{
    queue_node_t *node = (queue_node_t *)kmalloc(sizeof(queue_node_t));
    node->data = data;
    node->next = NULL;
    if (queue->size == 0)
    {
        queue->first = node;
        queue->last = node;
    }
    else
    {
        queue->last->next = node;
        queue->last = node;
    }
    queue->size++;
}

static __queue_data_t *__queue_dequeue(queue_t *queue)
{
    if (queue->size == 0)
        return (NULL);
    queue_node_t *node = queue->first;
    __queue_data_t *data = node->data;
    queue->first = node->next;
    kfree(node);
    queue->size--;
    return (data);
}

static __queue_data_t *__queue_peek(queue_t *queue)
{
    if (queue->size == 0)
        return (NULL);
    return (queue->first->data);
}

static void __queue_destroy(queue_t *queue)
{
    while (queue->size > 0)
        queue_dequeue(queue);
    kfree(queue);
}

static void __queue_destroy_with_data(queue_t *queue)
{
    while (queue->size > 0)
        kfree(queue_dequeue(queue));
    kfree(queue);
}

/*******************************************************************************
 *                             INTERFACE FUNCTIONS                             *
 ******************************************************************************/


queue_t *queue_create(void)
{
    return (__queue_create());
}

void queue_enqueue(queue_t *queue, __queue_data_t *data)
{
    __queue_enqueue(queue, data);
}

__queue_data_t *queue_dequeue(queue_t *queue)
{
    return (__queue_dequeue(queue));
}

__queue_data_t *queue_peek(queue_t *queue)
{
    return (__queue_peek(queue));
}

void queue_destroy_with_data(queue_t *queue)
{
    __queue_destroy_with_data(queue);
}

bool queue_is_empty(queue_t *queue)
{
    return (queue->size == 0);
}

uint32_t queue_size(queue_t *queue)
{
    return (queue->size);
}
