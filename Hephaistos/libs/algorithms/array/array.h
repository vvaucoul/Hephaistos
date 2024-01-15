/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:56:55 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/15 20:40:27 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARRAY_H
#define _ARRAY_H

#include <libs/stddef/stddef.h>

typedef struct Array {
    void **data;
    size_t size;
    size_t capacity;
} Array;

extern Array *array_create(size_t capacity);
extern void array_destroy(Array *array);

extern void array_resize(Array *array, size_t new_capacity);

extern void array_push(Array *array, void *data);
extern void *array_pop(Array *array);

extern void *array_get(Array *array, size_t index);

extern void array_set(Array *array, size_t index, void *data);
extern void array_insert(Array *array, size_t index, void *data);

extern void array_remove(Array *array, size_t index);

#endif /* !_ARRAY_H */