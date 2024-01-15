/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithm_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:20:25 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/15 15:07:07 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <hephaistos.h>

static int __data[] = {0, 1, 2, 3, 4, 5};

static void sum_data(void *data) {
    int *num = (int *)data;
    (*num) += 1;
}

static int compare_data(const void *a, const void *b) {
    int num_a = *(const int *)a;
    int num_b = *(const int *)b;

    if (num_a < num_b) {
        return -1;
    } else if (num_a > num_b) {
        return 1;
    } else {
        return 0;
    }
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
    list_add_back(list, (void *)1);
    list_add_back(list, (void *)2);
    list_destroy(list);
    // list and its elements should be freed here
}

void test_list_add_back(void) {
    list_t *list = list_create();
    list_add_back(list, (void *)1);
    list_add_back(list, (void *)2);
    assert(list_size(list) == 2);
    assert(!list_is_empty(list));
    assert(list_get(list, 0) == (void *)1);
    assert(list_get(list, 1) == (void *)2);
    list_destroy(list);
}

void test_list_add_front(void) {
    list_t *list = list_create();
    list_add_front(list, (void *)1);
    list_add_front(list, (void *)2);
    assert(list_size(list) == 2);
    assert(!list_is_empty(list));
    assert(list_get(list, 0) == (void *)2);
    assert(list_get(list, 1) == (void *)1);
    list_destroy(list);
}

void test_list_remove(void) {
    list_t *list = list_create();
    list_add_back(list, (void *)1);
    list_add_back(list, (void *)2);
    list_remove(list, (void *)1);
    assert(list_size(list) == 1);
    assert(!list_is_empty(list));
    assert(list_get(list, 0) == (void *)2);
    list_destroy(list);
}

void test_list_clear(void) {
    list_t *list = list_create();
    list_add_back(list, (void *)1);
    list_add_back(list, (void *)2);
    list_clear(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);
}

void test_list_insert(void) {
    list_t *list = list_create();
    list_add_back(list, (void *)1);
    list_add_back(list, (void *)3);
    list_insert(list, (void *)2, 1);
    assert(list_size(list) == 3);
    assert(!list_is_empty(list));
    assert(list_get(list, 0) == (void *)1);
    assert(list_get(list, 1) == (void *)2);
    assert(list_get(list, 2) == (void *)3);
    list_destroy(list);
}

void test_list_get(void) {
    list_t *list = list_create();
    list_add_back(list, (void *)1);
    list_add_back(list, (void *)2);
    assert(list_get(list, 0) == (void *)1);
    assert(list_get(list, 1) == (void *)2);
    list_destroy(list);
}

void test_list_iterate(void) {
    list_t *list = list_create();

    int i = 0;
    int i2 = 1;
    int i3 = 2;

    list_add_back(list, (void *)&i);
    list_add_back(list, (void *)&i2);
    list_add_back(list, (void *)&i3);
    list_iterate(list, (void (*)(void *))sum_data);
    assert(*(int *)list_get(list, 2) == 3);
    list_destroy(list);
}

void test_list_sort(void) {
    list_t *list = list_create();

    int i = 0;
    int i2 = 1;
    int i3 = 2;
    
    list_add_back(list, (void *)&i3);
    list_add_back(list, (void *)&i2);
    list_add_back(list, (void *)&i);

    list_sort(list, (int (*)(const void *, const void *))compare_data);
    
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
