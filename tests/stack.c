#include <criterion/criterion.h>
#include <stdlib.h>
#include "../includes/lolo/stack.h"
#define DATASET_SIZE 50

Test(stack, push)
{
    sstack_t *stack = NULL;
    int data = 42;

    stack_push(&stack, &data);
    cr_assert_eq(stack->data, &data);
    cr_assert_eq(stack->next, NULL);
}

Test(stack, pop)
{
    sstack_t *stack = NULL;
    int data = 42;

    stack_push(&stack, &data);
    cr_assert_eq(stack_pop(&stack), &data);
    cr_assert_eq(stack, NULL);
}

Test(stack, pop_empty)
{
    sstack_t *stack = NULL;

    cr_assert_eq(stack_pop(NULL), NULL); // Error handling
    cr_assert_eq(stack_pop(&stack), NULL);
    stack = malloc(sizeof(sstack_t));
    stack->data = NULL;
    stack->next = NULL;
    cr_assert_eq(stack_pop(&stack), NULL);
    free(stack);
}

Test(stack, peek)
{
    sstack_t *stack = NULL;
    int data = 42;

    stack_push(&stack, &data);
    cr_assert_eq(stack_peek(stack), &data);
    cr_assert_eq(stack->data, &data);
    cr_assert_eq(stack->next, NULL);
}

Test(stack, peek_empty)
{
    sstack_t *stack = NULL;

    cr_assert_eq(stack_peek(stack), NULL);
    cr_assert_eq(stack, NULL);
}

Test(stack, size)
{
    sstack_t *stack = NULL;
    int data = 42;

    stack_push(&stack, &data);
    cr_assert_eq(stack_size(stack), 1);
}

Test(stack, size_empty)
{
    sstack_t *stack = NULL;

    cr_assert_eq(stack_size(stack), 0);
}

Test(stack, size_a_lot)
{
    sstack_t *stack = NULL;
    int dataset[DATASET_SIZE];

    for (int i = 0; i < DATASET_SIZE; i++) {
        dataset[i] = i;
        stack_push(&stack, &dataset[i]);
    }
    cr_assert_eq(stack_size(stack), DATASET_SIZE);
}

Test(stack, free)
{
    sstack_t *stack = NULL;
    int data = 42;

    stack_push(&stack, &data);
    stack_free(stack);
}

Test(stack, free_empty)
{
    sstack_t *stack = NULL;

    stack_free(stack);
}

Test(stack, free_a_lot)
{
    sstack_t *stack = NULL;
    int dataset[DATASET_SIZE];

    for (int i = 0; i < DATASET_SIZE; i++) {
        dataset[i] = i;
        stack_push(&stack, &dataset[i]);
    }
    stack_free(stack);
}

Test(stack, free_all)
{
    sstack_t *stack = NULL;
    int *data = malloc(sizeof(int));

    *data = 42;
    stack_push(&stack, data);
    cr_assert_eq(stack->data, data);
    cr_assert_eq(stack->next, NULL);
    stack_free_all(stack);
}

Test(stack, free_all_empty)
{
    sstack_t *stack = NULL;

    stack_free_all(stack);
}

Test(stack, free_all_a_lot)
{
    sstack_t *stack = NULL;
    int *dataset[DATASET_SIZE];

    for (int i = 0; i < DATASET_SIZE; i++) {
        dataset[i] = malloc(sizeof(int));
        *dataset[i] = i;
        stack_push(&stack, dataset[i]);
    }
    stack_free_all(stack);
}
