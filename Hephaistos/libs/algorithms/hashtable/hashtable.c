/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:49:31 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/23 15:02:40 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include <charon.h>
/**
 * @brief Create a new hashtable
 *
 * @return A pointer to the newly created hashtable
 */
Hashtable *hashtable_create(uint8_t size) {
    Hashtable *table = (Hashtable *)kmalloc(sizeof(Hashtable));
    if (!table) {
        return NULL;
    }

    table->buckets = (HashEntry **)kmalloc(sizeof(HashEntry *) * size);
    if (!table->buckets) {
        kfree(table);
        return NULL;
    }

    for (uint32_t i = 0; i < size; ++i) {
        table->buckets[i] = NULL;
    }

    table->size = size;

    return table;
}

/**
 * @brief Free a hashtable entry
 *
 * @param entry The hashtable entry to free
 */
static void hashtable_free_entry(HashEntry *entry) {
    if (entry) {
        kfree(entry->key);
        kfree(entry);
    }
}

/**
 * @brief Delete a hashtable
 *
 * @param table The hashtable to delete
 */
void hashtable_delete(Hashtable *table) {
    if (table) {
        for (uint32_t i = 0; i < table->size; ++i) {
            HashEntry *entry = table->buckets[i];
            while (entry) {
                HashEntry *next = entry->next;
                hashtable_free_entry(entry);
                entry = next;
            }
        }
        kfree(table->buckets);
        kfree(table);
    }
}

/**
 * @brief Hash function to generate an index for a given key
 *
 * @param key The key to hash
 * @return The index in the hashtable
 */
uint32_t hashtable_fn(const char *key, uint8_t size) {
    uint32_t hash = 0;
    while (*key) {
        hash = (hash << 5) + *key++;
    }
    return hash % size;
}

/**
 * @brief Insert a key-value pair into the hashtable
 *
 * @param table The hashtable to insert into
 * @param key The key to insert
 * @param value The value to insert
 */
void hashtable_insert(Hashtable *table, const char *key, void *value) {
    uint32_t index = hashtable_fn(key, table->size);
    HashEntry *entry = table->buckets[index];

    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value;
            return;
        }
        entry = entry->next;
    }

    entry = (HashEntry *)kmalloc(sizeof(HashEntry));
    if (!entry)
        return;

    entry->key = (char *)kmalloc(strlen(key) + 1);
    if (!entry->key) {
        kfree(entry);
        return;
    }
    strcpy(entry->key, key);
    entry->value = value;
    entry->next = table->buckets[index];
    table->buckets[index] = entry;
}

/**
 * @brief Retrieve a value from the hashtable
 *
 * @param table The hashtable to retrieve from
 * @param key The key to retrieve
 * @return The value associated with the key, or NULL if not found
 */
void *hashtable_get(Hashtable *table, const char *key) {
    uint32_t index = hashtable_fn(key, table->size);
    HashEntry *entry = table->buckets[index];

    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return NULL;
}

/**
 * @brief Remove a key-value pair from the hashtable
 *
 * @param table The hashtable to remove from
 * @param key The key to remove
 */
void hashtable_remove(Hashtable *table, const char *key) {
    uint32_t index = hashtable_fn(key, table->size);
    HashEntry *entry = table->buckets[index];
    HashEntry *prev = NULL;

    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            if (prev) {
                prev->next = entry->next;
            } else {
                table->buckets[index] = entry->next;
            }
            hashtable_free_entry(entry);
            return;
        }
        prev = entry;
        entry = entry->next;
    }
}

/**
 * @brief Check if a key exists in the hashtable
 *
 * @param table The hashtable to check
 * @param key The key to check
 * @return 1 if the key exists, 0 otherwise
 */
int hashtable_contains_key(Hashtable *table, const char *key) {
    return hashtable_get(table, key) != NULL;
}