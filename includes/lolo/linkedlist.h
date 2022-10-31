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
 * @return The data of the removed node
 */
void *ll_pop_front(linkedlist_t **list);

/**
 * @brief Remove the last node of the list
 * @param list The list to remove the node from
 * @return The data of the removed node
 */
void *ll_pop_back(linkedlist_t **list);

/**
 * @brief Get the data of the first node of the list
 * @param list The list to get the data from
 * @return The data of the first node of the list
 */
void *ll_peek_front(linkedlist_t *list);

/**
 * @brief Get the data of the last node of the list
 * @param list The list to get the data from
 * @return The data of the last node of the list
 */
void *ll_peek_back(linkedlist_t *list);

/**
 * @brief Get the data of the n node of the list
 * @param list The list to get the size from
 * @param index The index of the node to get the data from
 * @return The data of the n node of the list
 */
void *ll_peek(linkedlist_t *list, int index);

/**
 * @brief Get the size of the list
 * @param list The list to get the size from
 * @return The size of the list
 */
int ll_size(linkedlist_t *list);

/**
 * @brief Free the list
 * @param list The list to free
 * @warning The data of each node is NOT freed, you have to do it yourself before calling this function
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
