/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithm_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:20:25 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/22 10:30:15 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <hephaistos.h>

static void sum_data(void *data) {
    int *num = (int *)data;
    (*num) += 1;
}

static int compare_data(const void *a, const void *b) {
    int num_a = *(const int *)a;
    int num_b = *(const int *)b;

    return (num_a - num_b);
}

void test_list_create(void) {
    list_t *list = list_create();
    assert(list != NULL);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);
}

void test_list_destroy(void) {
    list_t *list = list_create();
    int *data1 = kmalloc(sizeof(int));
    int *data2 = kmalloc(sizeof(int));
    *data1 = 1;
    *data2 = 2;
    list_add_back(list, data1);
    list_add_back(list, data2);
    list_destroy(list);
    // list and its elements should be freed here
}

void test_list_add_back(void) {
    list_t *list = list_create();
    int *data1 = kmalloc(sizeof(int));
    int *data2 = kmalloc(sizeof(int));
    *data1 = 1;
    *data2 = 2;
    list_add_back(list, data1);
    list_add_back(list, data2);
    assert(list_size(list) == 2);
    assert(!list_is_empty(list));
    assert(*(int *)list_get(list, 0) == 1);
    assert(*(int *)list_get(list, 1) == 2);
    list_destroy(list);
}

void test_list_add_front(void) {
    list_t *list = list_create();
    int *data1 = kmalloc(sizeof(int));
    int *data2 = kmalloc(sizeof(int));
    *data1 = 1;
    *data2 = 2;
    list_add_front(list, data1);
    list_add_front(list, data2);
    assert(list_size(list) == 2);
    assert(!list_is_empty(list));
    assert(*(int *)list_get(list, 0) == 2);
    assert(*(int *)list_get(list, 1) == 1);
    list_destroy(list);
}

void test_list_remove(void) {
    list_t *list = list_create();
    int *data1 = kmalloc(sizeof(int));
    int *data2 = kmalloc(sizeof(int));
    *data1 = 1;
    *data2 = 2;
    list_add_back(list, data1);
    list_add_back(list, data2);
    list_remove(list, data1);
    assert(list_size(list) == 1);
    assert(!list_is_empty(list));
    assert(*(int *)list_get(list, 0) == 2);
    list_destroy(list);
}

void test_list_clear(void) {
    list_t *list = list_create();
    int *data1 = kmalloc(sizeof(int));
    int *data2 = kmalloc(sizeof(int));
    *data1 = 1;
    *data2 = 2;
    list_add_back(list, data1);
    list_add_back(list, data2);
    list_clear(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);
}

void test_list_insert(void) {
    list_t *list = list_create();
    int *data1 = kmalloc(sizeof(int));
    int *data2 = kmalloc(sizeof(int));
    int *data3 = kmalloc(sizeof(int));
    *data1 = 1;
    *data2 = 3;
    *data3 = 2;
    list_add_back(list, data1);
    list_add_back(list, data2);
    list_insert(list, data3, 1);
    assert(list_size(list) == 3);
    assert(!list_is_empty(list));
    assert(*(int *)list_get(list, 0) == 1);
    assert(*(int *)list_get(list, 1) == 2);
    assert(*(int *)list_get(list, 2) == 3);
    list_destroy(list);
}

void test_list_get(void) {
    list_t *list = list_create();
    int *data1 = kmalloc(sizeof(int));
    int *data2 = kmalloc(sizeof(int));
    *data1 = 1;
    *data2 = 2;
    list_add_back(list, data1);
    list_add_back(list, data2);
    assert(*(int *)list_get(list, 0) == 1);
    assert(*(int *)list_get(list, 1) == 2);
    assert(list_get(list, 2) == NULL); // Test index out of bounds
    list_destroy(list);
}

void test_list_iterate(void) {
    list_t *list = list_create();
    int *data1 = kmalloc(sizeof(int));
    int *data2 = kmalloc(sizeof(int));
    int *data3 = kmalloc(sizeof(int));
    *data1 = 0;
    *data2 = 1;
    *data3 = 2;
    list_add_back(list, data1);
    list_add_back(list, data2);
    list_add_back(list, data3);
    list_iterate(list, sum_data);
    assert(*(int *)list_get(list, 0) == 1);
    assert(*(int *)list_get(list, 1) == 2);
    assert(*(int *)list_get(list, 2) == 3);
    list_destroy(list);
}

void test_list_sort(void) {
    list_t *list = list_create();
    int *data1 = kmalloc(sizeof(int));
    int *data2 = kmalloc(sizeof(int));
    int *data3 = kmalloc(sizeof(int));
    *data1 = 2;
    *data2 = 1;
    *data3 = 0;
    list_add_back(list, data1);
    list_add_back(list, data2);
    list_add_back(list, data3);
    list_sort(list, compare_data);
    assert(*(int *)list_get(list, 0) == 0);
    assert(*(int *)list_get(list, 1) == 1);
    assert(*(int *)list_get(list, 2) == 2);
    list_destroy(list);
}

int workflow_hephaistos_a_list(void) {
    test_list_create();
    test_list_destroy();
    test_list_add_back();
    test_list_add_front();
    test_list_remove();
    test_list_clear();
    test_list_insert();
    test_list_get();
    test_list_iterate();
    test_list_sort();

    return 0;
}