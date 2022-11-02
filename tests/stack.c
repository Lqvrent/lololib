#include <criterion/criterion.h>
#include <stdlib.h>
#include "../includes/lolo/stack.h"
#define DATASET_SIZE 50

Test(stack, push)
{
    stackc_t *stack = NULL;
    int data = 42;

    stack_push(&stack, &data);
    cr_assert(stack != NULL);
    cr_assert(stack->data == &data);
    cr_assert(stack->next == NULL);
    stack_free(&stack);
}

Test(stack, pop)
{
    stackc_t *stack = NULL;
    int data = 42;

    stack_push(&stack, &data);
    cr_assert(stack != NULL);
    cr_assert(stack->data == &data);
    cr_assert(stack->next == NULL);
    cr_assert(stack_pop(&stack) == &data);
    cr_assert(stack == NULL);
    stack_free(&stack);
}

Test(stack, push_pop)
{
    stackc_t *stack = NULL;
    int *dataset = malloc(sizeof(int) * DATASET_SIZE);

    for (int i = 0; i < DATASET_SIZE; i++) {
        dataset[i] = i;
        stack_push(&stack, &dataset[i]);
    }
    for (int i = DATASET_SIZE - 1; i >= 0; i--) {
        cr_assert(stack != NULL);
        cr_assert(stack->data == &dataset[i]);
        cr_assert(stack_pop(&stack) == &dataset[i]);
    }
    cr_assert(stack == NULL);
    stack_free(&stack);
    free(dataset);
}

Test(stack, peek)
{
    stackc_t *stack = NULL;
    int data = 42;

    stack_push(&stack, &data);
    cr_assert(stack != NULL);
    cr_assert(stack->data == &data);
    cr_assert(stack->next == NULL);
    cr_assert(stack_peek(stack) == &data);
    cr_assert(stack != NULL);
    stack_free(&stack);
}

Test(stack, peek_empty)
{
    stackc_t *stack = NULL;

    cr_assert(stack_peek(stack) == NULL);
}

Test(stack, get)
{
    stackc_t *stack = NULL;
    int data = 42;

    stack_push(&stack, &data);
    cr_assert(stack != NULL);
    cr_assert(stack->data == &data);
    cr_assert(stack->next == NULL);
    cr_assert(stack_get(stack, 0) == &data);
    cr_assert(stack != NULL);
    stack_free(&stack);
}

Test(stack, get_empty)
{
    stackc_t *stack = NULL;

    cr_assert(stack_get(stack, 0) == NULL);
}

Test(stack, get_out_of_range)
{
    stackc_t *stack = NULL;
    int data = 42;

    stack_push(&stack, &data);
    cr_assert(stack != NULL);
    cr_assert(stack->data == &data);
    cr_assert(stack->next == NULL);
    cr_assert(stack_get(stack, 1) == NULL);
    cr_assert(stack != NULL);
    stack_free(&stack);
}

Test(stack, free)
{
    stackc_t *stack = NULL;
    int data = 42;

    stack_push(&stack, &data);
    cr_assert(stack != NULL);
    cr_assert(stack->data == &data);
    cr_assert(stack->next == NULL);
    stack_free(&stack);
    cr_assert(stack == NULL);
}

Test(stack, free_empty)
{
    stackc_t *stack = NULL;

    stack_free(&stack);
    cr_assert(stack == NULL);
}

Test(stack, free_all)
{
    stackc_t *stack = NULL;
    int *tmp = NULL;

    for (int i = 0; i < DATASET_SIZE; i++) {
        tmp = malloc(sizeof(int));
        *tmp = i;
        stack_push(&stack, tmp);
    }
    stack_free_all(&stack);
    cr_assert(stack == NULL);
}
