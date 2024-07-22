/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:42:53 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/22 11:55:46 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

#define STACK_MAX_SIZE 128

typedef struct s_stack {
    void *data[STACK_MAX_SIZE]; // array of data
    int size;                   // size of the stack
} stack_t;

stack_t *stack_create(void);
void stack_destroy(stack_t *stack);
void stack_push(stack_t *stack, void *data);
void *stack_pop(stack_t *stack);
void *stack_peek(stack_t *stack);
void *stack_get_element(stack_t *stack, int index);
int stack_is_empty(stack_t *stack);
int stack_is_full(stack_t *stack);
int stack_get_size(stack_t *stack);

#endif /* !STACK_H */