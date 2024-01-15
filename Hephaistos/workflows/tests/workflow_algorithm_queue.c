/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithm_queue.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:03:38 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/15 13:26:08 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <hephaistos.h>

static int __data[] = {0, 1, 2, 3, 4, 5};

int test_queue_create(void) {
    queue_t *queue = queue_create();
    assert_msg(queue != NULL, "Queue creation failed");
    queue_destroy(queue);
    return 0;
}

int test_queue_destroy(void) {
    queue_t *queue = queue_create();
    queue_destroy(queue);
    return 0;
}

int test_queue_enqueue_dequeue(void) {
    queue_t *queue = queue_create();

    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, (int *)&(__data[i]));
    }

    for (int i = 0; i < 5; i++) {
        void *data = queue_dequeue(queue);
        assert_msg(*(int *)data == i, "Queue dequeue returned incorrect data");
    }

    queue_destroy(queue);
    return 0;
}

int test_queue_peek(void) {
    queue_t *queue = queue_create();

    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, (int *)&(__data[i]));
    }

    for (int i = 0; i < 5; i++) {
        void *data = queue_peek(queue);
        assert_msg(*(int *)data == i, "Queue peek returned incorrect data");
        queue_dequeue(queue);
    }

    queue_destroy(queue);
    return 0;
}

int test_queue_get_size(void) {
    queue_t *queue = queue_create();

    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, (int *)&(__data[i]));
    }

    for (int i = 0; i < 5; i++) {
        assert_msg(queue_get_size(queue) == 5 - i, "Queue size is incorrect");
        queue_dequeue(queue);
    }

    queue_destroy(queue);
    return 0;
}

int workflow_hephaistos_a_queue(void) {
    test_queue_create();
    test_queue_destroy();
    test_queue_enqueue_dequeue();
    test_queue_peek();
    test_queue_get_size();
    return 0;
}