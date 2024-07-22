/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:46:01 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/22 11:43:37 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <libs/stddef/stddef.h>

#define HASHTABLE_SIZE 1024 // Define the size of the hashtable

// Define the structure for hashtable entries
typedef struct HashEntry {
    char *key;
    void *value;
    struct HashEntry *next;
} HashEntry;

// Define the hashtable structure
typedef struct {
    HashEntry **buckets; // Array of pointers to HashEntry
} Hashtable;

// Function prototypes
Hashtable *hashtable_create(void);
void hashtable_delete(Hashtable *table);
uint32_t hashtable_fn(const char *key);
void hashtable_insert(Hashtable *table, const char *key, void *value);
void *hashtable_get(Hashtable *table, const char *key);
void hashtable_remove(Hashtable *table, const char *key);
int hashtable_contains_key(Hashtable *table, const char *key);

#endif /* HASHTABLE_H */