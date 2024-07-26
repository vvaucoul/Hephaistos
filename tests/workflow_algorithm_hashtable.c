/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithm_hashtable.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:54:21 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/23 15:04:12 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <hephaistos.h>

// Helper function to print the hashtable
void print_hashtable(Hashtable *table) {
    if (table == NULL) {
        printk("NULL hashtable\n");
        return;
    }

    for (int i = 0; i < table->size; i++) {
        HashEntry *entry = table->buckets[i];

        while (entry != NULL) {
            printk("Key: %s, Value: %p\n", entry->key, entry->value);
            entry = entry->next;
        }
    }
}

// Test function for hashtable_create
void test_hashtable_create() {
    Hashtable *table = hashtable_create(1);
    assert_msg(table != NULL, "Hashtable should not be NULL");
    hashtable_delete(table);
}

// Test function for hashtable_insert and hashtable_get
void test_hashtable_insert_get() {
    Hashtable *table = hashtable_create(2);
    const char *key1 = "key1";
    const char *key2 = "key2";
    const char *value1 = "value1";
    const char *value2 = "value2";

    hashtable_insert(table, key1, (void *)value1);
    hashtable_insert(table, key2, (void *)value2);

    void *retrieved_value1 = hashtable_get(table, key1);
    void *retrieved_value2 = hashtable_get(table, key2);

    assert_msg(retrieved_value1 == (void *)value1, "Retrieved value1 should be value1");
    assert_msg(retrieved_value2 == (void *)value2, "Retrieved value2 should be value2");

    hashtable_delete(table);
}

// Test function for hashtable_remove
void test_hashtable_remove() {
    Hashtable *table = hashtable_create(2);
    const char *key1 = "key1";
    const char *key2 = "key2";
    const char *value1 = "value1";
    const char *value2 = "value2";

    hashtable_insert(table, key1, (void *)value1);
    hashtable_insert(table, key2, (void *)value2);

    hashtable_remove(table, key1);

    assert_msg(hashtable_contains_key(table, key1) == 0, "Hash table should not contain key1");

    hashtable_delete(table);
}

// Test function for hashtable_delete
void test_hashtable_delete() {
    Hashtable *table = hashtable_create(1);
    hashtable_insert(table, "key1", "value1");
    hashtable_delete(table);
}

// Test function for hashtable_fn
void test_hashtable_fn() {
    assert_msg(hashtable_fn("test", 1) > 0, "Hashtable function should return a positive value for a non-empty string");
}

// Test function for hashtable_contains_key
void test_hashtable_contains_key() {
    Hashtable *table = hashtable_create(2);
    const char *key1 = "key1";
    const char *key2 = "key2";
    const char *value1 = "value1";
    const char *value2 = "value2";
    hashtable_insert(table, key1, (void *)value1);
    hashtable_insert(table, key2, (void *)value2);
    assert_msg(hashtable_contains_key(table, key1) == 1, "Hashtable should contain key1");
    assert_msg(hashtable_contains_key(table, key2) == 1, "Hashtable should contain key2");
    assert_msg(hashtable_contains_key(table, "non-existent-key") == 0, "Hashtable should not contain non-existent-key");
    hashtable_delete(table);
}

int workflow_hephaistos_a_hashtable(void) {
    test_hashtable_create();
    test_hashtable_insert_get();
    test_hashtable_remove();
    test_hashtable_delete();
    test_hashtable_fn();
    test_hashtable_contains_key();
    return (0);
}
