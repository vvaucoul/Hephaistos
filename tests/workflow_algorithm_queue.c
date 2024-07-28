/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithm_queue.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:03:38 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 13:18:07 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>

#include <algorithms/queue.h>
#include <assert.h>

static int __data[QUEUE_MAX_SIZE];

static void initialize_data() {
    for (int i = 0; i < QUEUE_MAX_SIZE; i++) {
        __data[i] = i;
    }
}

void test_queue_create_and_destroy() {
    queue_t *queue = queue_create();
    assert(queue != NULL);
    assert(queue_get_size(queue) == 0);
    queue_destroy(queue);
}

void test_queue_enqueue_dequeue() {
    queue_t *queue = queue_create();
    assert(queue != NULL);

    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, (int *)&(__data[i]));
    }

    for (int i = 0; i < 5; i++) {
        void *data = queue_dequeue(queue);
        assert(data != NULL);
        assert(*(int *)data == i);
    }

    assert(queue_get_size(queue) == 0);
    queue_destroy(queue);
}

void test_queue_peek() {
    queue_t *queue = queue_create();
    assert(queue != NULL);

    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, (int *)&(__data[i]));
    }

    for (int i = 0; i < 5; i++) {
        void *data = queue_peek(queue);
        assert(data != NULL);
        assert(*(int *)data == i);
        queue_dequeue(queue);
    }

    queue_destroy(queue);
}

void test_queue_get_size() {
    queue_t *queue = queue_create();
    assert(queue != NULL);

    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, (int *)&(__data[i]));
    }

    for (int i = 0; i < 5; i++) {
        assert(queue_get_size(queue) == 5 - i);
        queue_dequeue(queue);
    }

    queue_destroy(queue);
}

void test_queue_is_empty_and_is_full() {
    queue_t *queue = queue_create();
    assert(queue != NULL);

    assert(queue_get_size(queue) == 0);

    for (int i = 0; i < QUEUE_MAX_SIZE; i++) {
        queue_enqueue(queue, (int *)&(__data[i]));
    }

    assert(queue_get_size(queue) == QUEUE_MAX_SIZE);
    queue_dequeue(queue);
    assert(queue_get_size(queue) == QUEUE_MAX_SIZE - 1);

    for (int i = 0; i < QUEUE_MAX_SIZE - 1; i++) {
        queue_dequeue(queue);
    }

    assert(queue_get_size(queue) == 0);
    queue_destroy(queue);
}

void test_queue_edge_cases() {
    queue_t *queue = queue_create();
    assert(queue != NULL);

    // Enqueue plus d'éléments que la taille maximale
    for (int i = 0; i < QUEUE_MAX_SIZE + 10; i++) {
        if (i < QUEUE_MAX_SIZE) {
            assert(queue_enqueue(queue, (int *)&(__data[i])) == true);
        } else {
            // La file d'attente ne doit pas permettre d'ajouter au-delà de la taille maximale
            assert(queue_enqueue(queue, (int *)&(__data[0])) == false);
            assert(queue_get_size(queue) == QUEUE_MAX_SIZE);
        }
    }

    // Déqueue avec une file vide
    for (int i = 0; i < QUEUE_MAX_SIZE; i++) {
        queue_dequeue(queue);
    }
    assert(queue_dequeue(queue) == NULL);

    // Peek avec une file vide
    assert(queue_peek(queue) == NULL);

    queue_destroy(queue);
}

int workflow_hephaistos_a_queue(void) {
    initialize_data();

    test_queue_create_and_destroy();
    test_queue_enqueue_dequeue();
    test_queue_peek();
    test_queue_get_size();
    test_queue_is_empty_and_is_full();
    test_queue_edge_cases();

    return (0);
}