/**
 * @file linkedlist.h
 * @brief Linked list implementation
 */

#ifndef __LINKEDLIST_H__
    #define __LINKEDLIST_H__

typedef struct ll_node_s {
    void *data;
    struct ll_node_s *next;
} ll_node_t;

typedef struct {
    ll_node_t *head;
    ll_node_t *tail;
    int size;
} linkedlist_t;

/**
 * @brief Create a new linked list
 * @return A pointer to the new linked list
 */
linkedlist_t *ll_create();

/**
 * @brief Add a new node at the beginning of the list
 * @param list The list to add the node to
 * @param data The data to add to the list
 */
void ll_push_front(linkedlist_t *list, void *data);

/**
 * @brief Add a new node at the end of the list
 * @param list The list to add the node to
 * @param data The data to add to the list
 */
void ll_push_back(linkedlist_t *list, void *data);

/**
 * @brief Remove the first node of the list
 * @param list The list to remove the node from
 * @return The data of the removed node
 */
void *ll_pop_front(linkedlist_t *list);

/**
 * @brief Remove the last node of the list
 * @param list The list to remove the node from
 * @return The data of the removed node
 */
void *ll_pop_back(linkedlist_t *list);

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
 * @param n The index of the node to get the data from
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
 */
void ll_free(linkedlist_t *list);

#endif /* __LINKEDLIST_H__ */
