/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:46:01 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/23 15:03:01 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <libs/stddef/stddef.h>

// Define the structure for hashtable entries
typedef struct HashEntry {
    char *key;
    void *value;
    struct HashEntry *next;
} HashEntry;

// Define the hashtable structure
typedef struct {
    HashEntry **buckets; // Array of pointers to HashEntry
    uint8_t size;        // Hashtable max size
} Hashtable;

// Function prototypes
Hashtable *hashtable_create(uint8_t size);
void hashtable_delete(Hashtable *table);
uint32_t hashtable_fn(const char *key, uint8_t size);
void hashtable_insert(Hashtable *table, const char *key, void *value);
void *hashtable_get(Hashtable *table, const char *key);
void hashtable_remove(Hashtable *table, const char *key);
int hashtable_contains_key(Hashtable *table, const char *key);

#endif /* HASHTABLE_H */