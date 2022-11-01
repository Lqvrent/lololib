#ifndef __QUEUE_H__
    #define __QUEUE_H__

/**
 * @brief Queue node structure
*/
typedef struct queue_node_s {
    /**
     * @brief Pointer to the actual data
     */
    void *data;
    /**
     * @brief Pointer to the next element (NULL if last)
     */
    struct queue_node_s *next;
} queue_node_t;

/**
 * @brief Queue structure
 */
typedef struct queue_s {
    /**
     * @brief We hold the data in a linked list
     */
    queue_node_t *data;
    /**
     * @brief Pointer to the first element of the queue
     */
    queue_node_t *head;
    /**
     * @brief Pointer to the last element of the queue
     */
    queue_node_t *tail;
} queue_t;

/**
 * @brief Add an element to the queue
 * @param queue The address of the queue to add the element to
 * @param data The data to add to the queue
 */
void queue_enqueue(queue_t **queue, void *data);

/**
 * @brief Remove an element from the queue
 * @param queue The address of the queue to remove the element from
 * @return The data of the removed element
 */
void *queue_dequeue(queue_t **queue);

/**
 * @brief Get the first element of the queue
 * @param queue The queue to get the element from
 * @return The data of the first element in the queue
 */
void *queue_peek(queue_t *queue);

/**
 * @brief Get the size of the queue
 * @param queue The queue to get the size from
 * @return The size of the queue
 */
unsigned int queue_size(queue_t *queue);

/**
 * @brief Free the queue (use it if you will NOT use the inserted data anymore)
 * @param queue The queue to free
 * @warning The data of each node is NOT freed, you have to do it yourself before calling this function, or call queue_free_all()
 */
void queue_free(queue_t *queue);

/**
 * @brief Free the queue and all the data it contains (use it if you will use the inserted data anymore)
 * @param queue The queue to free
 * @warning The void pointer passed when queueing MUST be a pointer to a malloc'd memory
 */
void queue_free_all(queue_t *queue);

#endif /* !__QUEUE_H__ */
