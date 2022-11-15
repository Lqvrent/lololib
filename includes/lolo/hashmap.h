/**
 * @file hashmap.h
 * @brief Hashmaps implementation
 */

#ifndef __HASHMAPS_H__
    #define __HASHMAPS_H__
    #ifndef NULL
        /**
         * @brief Represents a null pointer.
         */
        #define NULL (void *)0
    #endif /* !NULL */

/**
 * @brief Hashmap structure
 */
typedef struct hashmap_s {
    /**
     * @brief Pointer to the actual data
     */
    void *data;
    /**
     * @brief Pointer to the next element (NULL if last)
     */
    struct hashmap_s *next;
    /**
     * @brief Key of the element
     */
    char *key;
} hashmap_t;

/**
 * @brief Add an entry to the hashmap
 * @param list The list to add the entry to
 * @param data The data to add to the list
 * @param key The key of the element
 * @note If the key already exists, the data will be replaced
 * @note All entries are sorted by key
 */
void *hm_put(hashmap_t **map, char *key, void *data);

/**
 * @brief Get an entry from the hashmap by its key
 * @param list The list to get the entry from
 * @param key The key of the element
 * @return The data of the element (NULL if not found)
 */
void *hm_get(hashmap_t **map, char *key);

/**
 * @brief Remove an entry from the hashmap
 * @param list The list to remove the entry from
 * @param key The key of the element
 * @return The data of the removed element (NULL if not found)
 */
void *hm_remove(hashmap_t **map, char *key);

/**
 * @brief Get the size of the hashmap
 * @param list The list to get the size from
 * @return The size of the hashmap
 */
int hm_size(hashmap_t **map);

/**
 * @brief Get the keys of the hashmap
 * @param list The list to get the keys from
 * @return The keys of the hashmap
 * @note You should use the function string_array_free() to free the returned array
 */
char **hm_keys(hashmap_t **map);

/**
 * @brief Destroy the hashmap
 *
 * @param map The hashmap to destroy
 * @note This function will free all the entries and their keys, but not the values
 */
void hm_destroy(hashmap_t **map);

/**
 * @brief Destroy the hashmap and its values
 *
 * @param map The hashmap to destroy
 * @note This function will free all the entries, their keys and their values
 */
void hm_destroyAll(hashmap_t **map);

#endif /* !__HASHMAPS_H__ */
