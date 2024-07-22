/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:56:55 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/22 11:17:33 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <libs/stddef/stddef.h>

typedef struct Array {
    void **data;
    size_t size;
    size_t capacity;
} Array;

Array *array_create(size_t capacity);
void array_destroy(Array *array);

void array_resize(Array *array, size_t new_capacity);

void array_push(Array *array, void *data);
void *array_pop(Array *array);

void *array_get(Array *array, size_t index);

void array_set(Array *array, size_t index, void *data);
void array_insert(Array *array, size_t index, void *data);

void array_remove(Array *array, size_t index);

#endif /* !ARRAY_H */