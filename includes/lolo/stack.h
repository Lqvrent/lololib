#ifndef __STACK_H__
    #define __STACK_H__
    #ifndef NULL
        /**
         * @brief Represents a null pointer.
         */
        #define NULL (void *)0
    #endif /* !NULL */

/**
 * @brief Stack node structure
*/
typedef struct stack_node_s {
    /**
     * @brief Pointer to the actual data
     */
    void *data;
    /**
     * @brief Pointer to the next element (NULL if last)
     */
    struct stack_node_s *next;
} stack_node_t;

/**
 * @brief Stack container structure
 */
typedef struct stack_s {
    /**
     * @brief We hold the data in a linked list
     */
    stack_node_t *data;
    /**
     * @brief Pointer to the first element of the stack
     */
    stack_node_t *head;
} stackc_t;

/**
 * @brief Add an element to the stack
 * @param stack The address of the stack to add the element to
 * @param data The data to add to the stack
 */
void stack_push(stackc_t **stack, void *data);

/**
 * @brief Remove the top element from the stack
 * @param stack The address of the stack to remove the element from
 * @return The data of the removed element
 */
void *stack_pop(stackc_t **stack);

/**
 * @brief Get the top element of the stack
 * @param stack The stack to get the element from
 * @return The data of the top element in the stack
 */
void *stack_peek(stackc_t *stack);

/**
 * @brief Get the size of the stack
 * @param stack The stack to get the size of
 * @return The size of the stack
 */
unsigned int stack_size(stackc_t *stack);

/**
 * @brief Free the stack (use it if you will NOT use the inserted data anymore)
 *
 * @param stack The stack to free
 * @warning @warning The data of each node is NOT freed, you have to do it yourself before calling this function, or call stack_free_all()
 */
void stack_free(stackc_t *stack);

/**
 * @brief Free the stack and all the data it contains (use it if you will use the inserted data anymore)
 * @param queue The stack to free
 * @warning The void pointer passed when queueing MUST be a pointer to a malloc'd memory
 */
void stack_free_all(stackc_t *stack);

#endif /* !__STACK_H__ */
