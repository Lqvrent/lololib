/**
 * @file linkedlist.h
 * @brief Linked list implementation
 */

#ifndef __LINKEDLIST_H__
    #define __LINKEDLIST_H__
    #ifndef NULL
        /**
         * @brief Represents a null pointer.
         */
        #define NULL (void *)0
    #endif /* !NULL */

/**
 * @brief Linked list structure
 */
typedef struct linkedlist_s {
    /**
     * @brief Pointer to the actual data
     */
    void *data;
    /**
     * @brief Pointer to the next element (NULL if last)
     */
    struct linkedlist_s *next;
} linkedlist_t;

/**
 * @brief Add a new node at the beginning of the list
 * @param list The list to add the node to
 * @param data The data to add to the list
 */
void ll_push_front(linkedlist_t **list, void *data);

/**
 * @brief Add a new node at the end of the list
 * @param list The list to add the node to
 * @param data The data to add to the list
 */
void ll_push_back(linkedlist_t **list, void *data);

/**
 * @brief Remove the first node of the list
 * @param list The list to remove the node from
 * @return The data of the removed node (NULL if the list is empty)
 */
void *ll_pop_front(linkedlist_t **list);

/**
 * @brief Remove the last node of the list
 * @param list The list to remove the node from
 * @return The data of the removed node (NULL if the list is empty)
 */
void *ll_pop_back(linkedlist_t **list);

/**
 * @brief Remove a node of the list
 * @param list The list to remove the node from
 * @param data The data of the node to remove
 * @return The data of the removed node (NULL if the list is empty or the node is not found)
 */
void *ll_pop(linkedlist_t **list, void *data);

/**
 * @brief Remove a node of the list at a specific index
 * @param list The list to get the size of
 * @param index The index of the node to remove
 * @return The data of the removed node (NULL if the list is empty or if the index is out of range)
 */
void *ll_pop_at(linkedlist_t **list, unsigned int index);

/**
 * @brief Get the data of the first node of the list
 * @param list The list to get the data from
 * @return The data of the first node of the list (NULL if the list is empty)
 */
void *ll_get_front(linkedlist_t *list);

/**
 * @brief Get the data of the last node of the list
 * @param list The list to get the data from
 * @return The data of the last node of the list (NULL if the list is empty)
 */
void *ll_get_back(linkedlist_t *list);

/**
 * @brief Get the data of the n node of the list
 * @param list The list to get the size from
 * @param index The index of the node to get the data from
 * @return The data of the n node of the list (NULL if the list is empty or if the index is out of range)
 */
void *ll_get(linkedlist_t *list, unsigned int index);

/**
 * @brief Get the size of the list
 * @param list The list to get the size from
 * @return The size of the list
 */
unsigned int ll_size(linkedlist_t *list);

/**
 * @brief Free the list
 * @param list The list to free
 * @warning The data of each node is NOT freed, you have to do it yourself before calling this function, or call ll_free_all()
 */
void ll_free(linkedlist_t *list);

/**
 * @brief Same as ll_free, but also free the data of each node
 *
 * @param list The list to free
 * @warning The void pointer passed on a push MUST be a pointer to a malloc'd memory
 */
void ll_free_all(linkedlist_t *list);

#endif /* __LINKEDLIST_H__ */
