/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:56:55 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/20 23:16:06 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <libs/stddef/stddef.h>

typedef void *__array_data_t;

typedef struct s_array
{
    __array_data_t *data;
    uint32_t size;
} array_t;

extern array_t *array_create(uint32_t size);
extern void array_destroy(array_t *array);
extern void array_add(array_t *array, __array_data_t *data);
extern void array_remove(array_t *array, uint32_t index);
extern void array_clear(array_t *array);
extern void array_resize(array_t *array, uint32_t size);
extern void array_set(array_t *array, uint32_t index, __array_data_t *data);
extern __array_data_t array_get(array_t *array, uint32_t index);
extern uint32_t array_size(array_t *array);

#endif /* !ARRAY_H */