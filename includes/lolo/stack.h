/**
 * @file stack.h
 * @brief Stack implementation
 */

#ifndef __STACK_H__
    #define __STACK_H__
    #ifndef NULL
        /**
         * @brief Represents a null pointer.
         */
        #define NULL (void *)0
    #endif /* !NULL */

/**
 * @brief Stack structure
 */
typedef struct sstack_s {
    /**
     * @brief Pointer to the actual data
     */
    void *data;
    /**
     * @brief Pointer to the next element (NULL if last)
     */
    struct sstack_s *next;
} sstack_t;

/**
 * @brief Add an element to the stack
 * @param stack The address of the stack to add the element to
 * @param data The data to add to the stack
 */
void stack_push(sstack_t **stack, void *data);

/**
 * @brief Remove the top element from the stack
 * @param stack The address of the stack to remove the element from
 * @return The data of the removed element
 */
void *stack_pop(sstack_t **stack);

/**
 * @brief Get the top element of the stack
 * @param stack The stack to get the element from
 * @return The data of the top element in the stack
 */
void *stack_peek(sstack_t *stack);

/**
 * @brief Get the size of the stack
 * @param stack The stack to get the size of
 * @return The size of the stack
 */
unsigned int stack_size(sstack_t *stack);

/**
 * @brief Free the stack (use it if you will NOT use the inserted data anymore)
 *
 * @param stack The stack to free
 * @warning @warning The data of each node is NOT freed, you have to do it yourself before calling this function, or call stack_free_all()
 */
void stack_free(sstack_t *stack);

/**
 * @brief Free the stack and all the data it contains (use it if you will use the inserted data anymore)
 * @param queue The stack to free
 * @warning The void pointer passed when queueing MUST be a pointer to a malloc'd memory
 */
void stack_free_all(sstack_t *stack);

#endif /* !__STACK_H__ */
