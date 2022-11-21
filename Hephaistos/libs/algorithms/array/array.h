/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:56:55 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/21 21:04:09 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <libs/stddef/stddef.h>

typedef void __array_data_t;

typedef struct s_array
{
    __array_data_t **data; // Array of data
    uint32_t size;         // Max size of the array
    uint32_t length;       // Current length of the array

    uint32_t __first_free_index; // Index of the first free space
    uint32_t __last_free_index;  // Index of the last free space
} array_t;

extern array_t *array_create(uint32_t size);
extern void array_add(array_t *array, __array_data_t *data);
extern void array_remove(array_t *array, uint32_t index);
extern void array_clear(array_t *array);
extern void array_resize(array_t *array, uint32_t size);
extern void array_insert(array_t *array, __array_data_t *data, uint32_t index);
extern __array_data_t *array_get(array_t *array, uint32_t index);
extern uint32_t array_size(array_t *array);
extern uint32_t array_length(array_t *array);

extern void array_size_ref(array_t *array, uint32_t *size);
extern void array_length_ref(array_t *array, uint32_t *length);

#endif /* !ARRAY_H */