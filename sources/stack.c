#include "lolo/stack.h"
#include <stdlib.h>

void stack_push(stackc_t **stack, void *data)
{
    stack_node_t *node = NULL;

    if (*stack == NULL) {
        *stack = malloc(sizeof(stackc_t));
        if (*stack == NULL)
            return;
        (*stack)->data = NULL;
        (*stack)->head = NULL;
    }
    node = malloc(sizeof(stack_node_t));
    if (node == NULL)
        return;
    node->data = data;
    node->next = (*stack)->head;
    (*stack)->head = node;
}

void *stack_pop(stackc_t **stack)
{
    stack_node_t *node = NULL;
    void *data = NULL;

    if (*stack == NULL || *stack == NULL || (*stack)->data == NULL)
        return (NULL);
    node = (*stack)->head;
    data = node->data;
    (*stack)->head = node->next;
    free(node);
    return (data);
}

void *stack_peek(stackc_t *stack)
{
    if (stack == NULL || stack->data == NULL)
        return (NULL);
    return (stack->head->data);
}

void stack_free(stackc_t *stack)
{
    stack_node_t *tmp = NULL;

    if (stack == NULL)
        return;
    while (stack->head != NULL) {
        tmp = stack->head;
        stack->head = stack->head->next;
        free(tmp);
    }
    free(stack);
}

void stack_free_all(stackc_t *stack)
{
    stack_node_t *tmp = NULL;

    if (stack == NULL)
        return;
    while (stack->head != NULL) {
        tmp = stack->head;
        stack->head = stack->head->next;
        free(tmp->data);
        free(tmp);
    }
    free(stack);
}
