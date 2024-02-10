/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:49:31 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/15 15:04:48 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include <charon.h>

/**
 * @brief Creates a new hashtable.
 *
 * This function creates a new hashtable and returns a pointer to it.
 *
 * @return A pointer to the newly created hashtable.
 */
Hashtable *hashtable_create(void) {
    Hashtable *table = kmalloc(sizeof(Hashtable));

    if (table == NULL) {
        return (NULL);
    }

    table->buckets = kmalloc(sizeof(HashEntry *) * HASHTABLE_SIZE);

    if (table->buckets == NULL) {
        kfree(table);
        return (NULL);
    }

    memset(table->buckets, 0, sizeof(HashEntry *) * HASHTABLE_SIZE);
    return (table);
}

/**
 * @brief Destroys a hashtable and frees the allocated memory.
 *
 * This function destroys the given hashtable and frees the memory allocated for it.
 *
 * @param table The hashtable to be destroyed.
 */
void hashtable_delete(Hashtable *table) {
    if (table == NULL) {
        return;
    }

    for (int i = 0; i < HASHTABLE_SIZE; i++) {
        HashEntry *entry = table->buckets[i];

        while (entry != NULL) {
            HashEntry *next = entry->next;
            kfree(entry->key);
            kfree(entry);
            entry = next;
        }
    }

    kfree(table->buckets);
    kfree(table);
}

/**
 * @brief Hash function for the hashtable.
 *
 * This function is used to hash the given key and return the hash value.
 *
 * @param key The key to be hashed.
 * @return The hash value of the given key.
 */
uint32_t hashtable_fn(const char *key) {
    uint32_t hash = 0;

    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash << 5) + hash + key[i];
    }

    return (hash % HASHTABLE_SIZE);
}

/**
 * @brief Inserts a key-value pair into the hashtable.
 *
 * This function inserts the given key-value pair into the hashtable.
 * If the key already exists in the hashtable, the value is updated.
 *
 * @param table The hashtable to insert the key-value pair into.
 * @param key The key to be inserted.
 * @param value The value to be inserted.
 */
void hashtable_insert(Hashtable *table, const char *key, void *value) {
    if (table == NULL || key == NULL) {
        return;
    }

    uint32_t hash = hashtable_fn(key);
    HashEntry *entry = table->buckets[hash];

    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value;
            return;
        }

        entry = entry->next;
    }

    entry = kmalloc(sizeof(HashEntry));

    if (entry == NULL) {
        return;
    }

    entry->key = strdup(key);

    if (entry->key == NULL) {
        kfree(entry);
        return;
    }

    entry->value = value;
    entry->next = table->buckets[hash];
    table->buckets[hash] = entry;
}

/**
 * @brief Retrieves a value from the hashtable based on the given key.
 *
 * This function retrieves the value from the hashtable based on the given key.
 * If the key does not exist in the hashtable, NULL is returned.
 *
 * @param table The hashtable to retrieve the value from.
 * @param key The key to be retrieved.
 * @return The value associated with the given key, or NULL if the key does not exist in the hashtable.
 */
void *hashtable_get(Hashtable *table, const char *key) {
    if (table == NULL || key == NULL) {
        return (NULL);
    }

    uint32_t hash = hashtable_fn(key);
    HashEntry *entry = table->buckets[hash];

    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return (entry->value);
        }

        entry = entry->next;
    }

    return (NULL);
}

/**
 * @brief Removes a key-value pair from the hashtable.
 *
 * This function removes the key-value pair from the hashtable based on the given key.
 * If the key does not exist in the hashtable, nothing is done.
 *
 * @param table The hashtable to remove the key-value pair from.
 * @param key The key to be removed.
 */
void hashtable_remove(Hashtable *table, const char *key) {
    if (table == NULL || key == NULL) {
        return;
    }

    uint32_t hash = hashtable_fn(key);
    HashEntry *entry = table->buckets[hash];
    HashEntry *prev = NULL;

    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            if (prev == NULL) {
                table->buckets[hash] = entry->next;
            } else {
                prev->next = entry->next;
            }

            kfree(entry->key);
            kfree(entry);
            return;
        }

        prev = entry;
        entry = entry->next;
    }
}

/**
 * @brief Checks if the hashtable contains the given key.
 *
 * This function checks if the hashtable contains the given key.
 *
 * @param table The hashtable to check.
 * @param key The key to check.
 * @return 1 if the hashtable contains the key, 0 otherwise.
 */
int hashtable_contains_key(Hashtable *table, const char *key) {
    if (table == NULL || key == NULL) {
        return (0);
    }

    uint32_t hash = hashtable_fn(key);
    HashEntry *entry = table->buckets[hash];

    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return (1);
        }

        entry = entry->next;
    }

    return (0);
}
