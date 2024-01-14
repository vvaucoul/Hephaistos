/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:46:01 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/14 17:08:06 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <libs/stddef/stddef.h>

/**
 * @file hashtable.h
 * @brief This file contains the declaration of a hashtable data structure.
 *
 * A hashtable is a data structure that allows efficient insertion, deletion, and retrieval of key-value pairs.
 * It uses a hash function to map keys to indices in an array, where the values are stored.
 * In case of collisions, where multiple keys map to the same index, a linked list is used to handle collisions.
 *
 * The hashtable.h file declares the necessary structures and functions to work with a hashtable.
 * It defines the HTEntry structure, which represents an entry in the hashtable, containing a key, a value, and a pointer to the next entry in case of collisions.
 * It also defines the HashTable structure, which represents the hashtable itself, containing the size of the hashtable and a pointer to an array of HTEntry pointers.
 *
 * The hashtable.h file provides functions to create a hashtable, delete a hashtable, insert key-value pairs, delete key-value pairs, and retrieve values based on keys.
 *
 * @see hashtable.c
 */

#define HASHTABLE_SIZE 0x400 // Define the size of the hashtable

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
extern Hashtable *hashtable_create(void);
extern void hashtable_delete(Hashtable *table);
extern uint32_t hashtable_fn(const char *key);
extern void hashtable_insert(Hashtable *table, const char *key, void *value);
extern void *hashtable_get(Hashtable *table, const char *key);
extern void hashtable_remove(Hashtable *table, const char *key);
extern int hashtable_contains_key(Hashtable *table, const char *key);

#endif /* HASHTABLE_H */