/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_algorithm_hashtable.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:54:21 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 13:28:27 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>

#include <algorithms/hashtable.h>
#include <assert.h>
#define HASHTABLE_DEBUG 0

// Helper function to print the hashtable
#if HASHTABLE_DEBUG == 1
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
#endif

// Test for creating the hashtable
void test_hashtable_create() {
	Hashtable *table = hashtable_create(1);
	assert_msg(table != NULL, "Hashtable should not be NULL");
	hashtable_delete(table);
}

// Test for inserting and retrieving values
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

// Test for removing values
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

// Test for deleting the hashtable
void test_hashtable_delete() {
	Hashtable *table = hashtable_create(1);
	hashtable_insert(table, "key1", "value1");
	hashtable_delete(table);
}

// Test for the hash function
void test_hashtable_fn() {
	assert_msg(hashtable_fn("test", 1) >= 0, "Hashtable function should return a positive or zero value for a non-empty string");
}

// Test for checking the existence of a key
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

// Test for edge cases
void test_hashtable_edge_cases() {
	Hashtable *table = hashtable_create(10);

	// Insertion and removal of many keys
	for (int i = 0; i < 1000; i++) {
		char key[20];
		char value[20];
		// Format strings without snprintf
		int j = 0;
		int temp = i;
		char reverse_key[20];
		char reverse_value[20];

		// Format the key
		strcpy(key, "key");
		while (temp > 0) {
			reverse_key[j++] = (temp % 10) + '0';
			temp /= 10;
		}
		for (int k = j - 1; k >= 0; k--) {
			key[3 + j - 1 - k] = reverse_key[k];
		}
		key[3 + j] = '\0';

		// Format the value
		temp = i;
		j = 0;
		strcpy(value, "value");
		while (temp > 0) {
			reverse_value[j++] = (temp % 10) + '0';
			temp /= 10;
		}
		for (int k = j - 1; k >= 0; k--) {
			value[5 + j - 1 - k] = reverse_value[k];
		}
		value[5 + j] = '\0';

		hashtable_insert(table, key, strdup(value));
	}

	for (int i = 0; i < 1000; i++) {
		char key[20];
		char expected_value[20];
		int j = 0;
		int temp = i;
		char reverse_key[20];
		char reverse_value[20];

		// Format the key
		strcpy(key, "key");
		while (temp > 0) {
			reverse_key[j++] = (temp % 10) + '0';
			temp /= 10;
		}
		for (int k = j - 1; k >= 0; k--) {
			key[3 + j - 1 - k] = reverse_key[k];
		}
		key[3 + j] = '\0';

		// Format the expected value
		temp = i;
		j = 0;
		strcpy(expected_value, "value");
		while (temp > 0) {
			reverse_value[j++] = (temp % 10) + '0';
			temp /= 10;
		}
		for (int k = j - 1; k >= 0; k--) {
			expected_value[5 + j - 1 - k] = reverse_value[k];
		}
		expected_value[5 + j] = '\0';

		char *value = (char *)hashtable_get(table, key);
		assert_msg(strcmp(value, expected_value) == 0, "Hashtable should contain the correct value");
		kfree(value); // Assuming strdup was used for insertion
	}

	// Removal of keys
	for (int i = 0; i < 1000; i++) {
		char key[20];
		int j = 0;
		int temp = i;
		char reverse_key[20];

		// Format the key
		strcpy(key, "key");
		while (temp > 0) {
			reverse_key[j++] = (temp % 10) + '0';
			temp /= 10;
		}
		for (int k = j - 1; k >= 0; k--) {
			key[3 + j - 1 - k] = reverse_key[k];
		}
		key[3 + j] = '\0';

		hashtable_remove(table, key);
		assert_msg(hashtable_contains_key(table, key) == 0, "Hashtable should not contain removed key");
	}

	hashtable_delete(table);
}

int workflow_hephaistos_a_hashtable(void) {
	test_hashtable_create();
	test_hashtable_insert_get();
	test_hashtable_remove();
	test_hashtable_delete();
	test_hashtable_fn();
	test_hashtable_contains_key();
	test_hashtable_edge_cases();
	return (0);
}