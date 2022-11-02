#include "lolo/stack.h"
#include <stdlib.h>

void stack_push(sstack_t **stack, void *data)
{
    sstack_t *node = malloc(sizeof(sstack_t));

    node = malloc(sizeof(sstack_t));
    if (node == NULL)
        return;
    node->data = data;
    node->next = *stack;
    *stack = node;
}

void *stack_pop(sstack_t **stack)
{
    sstack_t *tmp = *stack;
    void *data = NULL;

    if (*stack == NULL)
        return (NULL);
    data = (*stack)->data;
    *stack = (*stack)->next;
    free(tmp);
    return (data);
}

void *stack_peek(sstack_t *stack)
{
    if (stack == NULL)
        return (NULL);
    return (stack->data);
}

unsigned int stack_size(sstack_t *stack)
{
    unsigned int size = 0;

    while (stack != NULL) {
        size++;
        stack = stack->next;
    }
    return (size);
}

void stack_free(sstack_t *stack)
{
    sstack_t *tmp = NULL;

    while (stack != NULL) {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}

void stack_free_all(sstack_t *stack)
{
    sstack_t *tmp = NULL;

    while (stack != NULL) {
        tmp = stack;
        stack = stack->next;
        free(tmp->data);
        free(tmp);
    }
}
