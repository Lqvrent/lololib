#include <criterion/criterion.h>
#include <stdlib.h>
#include "../includes/lolo/queue.h"
#define DATASET_SIZE 50

Test(queue, enqueue)
{
    queue_t *queue = NULL;
    int data = 42;

    queue_enqueue(&queue, &data);
    cr_assert_eq(queue->data->data, &data);
    cr_assert_eq(queue->head->data, &data);
    cr_assert_eq(queue->tail->data, &data);
    if (queue != NULL)
        queue_free(queue);
}

Test(queue, enqueue_a_lot)
{
    queue_t *queue = NULL;
    int data[DATASET_SIZE];

    for (int i = 0; i < DATASET_SIZE; i++) {
        data[i] = i;
        queue_enqueue(&queue, &data[i]);
    }
    for (int i = 0; i < DATASET_SIZE; i++) {
        cr_assert_eq(queue->data->data, &data[i]);
        queue_dequeue(&queue);
    }
    if (queue != NULL)
        queue_free(queue);
}

Test(queue, dequeue)
{
    queue_t *queue = NULL;
    int data = 42;

    queue_enqueue(&queue, &data);
    cr_assert_eq(queue_dequeue(&queue), &data);
    if (queue != NULL)
        queue_free(queue);
}

Test(queue, dequeue_a_lot)
{
    queue_t *queue = NULL;
    int data[DATASET_SIZE];

    for (int i = 0; i < DATASET_SIZE; i++) {
        data[i] = i;
        queue_enqueue(&queue, &data[i]);
    }
    for (int i = 0; i < DATASET_SIZE; i++) {
        cr_assert_eq(queue_dequeue(&queue), &data[i]);
    }
    if (queue != NULL)
        queue_free(queue);
}

Test(queue, dequeue_empty)
{
    queue_t *queue = NULL;

    cr_assert_eq(queue_dequeue(NULL), NULL);
    cr_assert_eq(queue_dequeue(&queue), NULL);
    queue = malloc(sizeof(queue_t));
    queue->data = NULL;
    queue->head = NULL;
    queue->tail = NULL;
    cr_assert_eq(queue_dequeue(&queue), NULL);
    if (queue != NULL)
        queue_free(queue);
}

Test(queue, peek)
{
    queue_t *queue = NULL;
    int data = 42;

    queue_enqueue(&queue, &data);
    cr_assert_eq(queue_peek(queue), &data);
    if (queue != NULL)
        queue_free(queue);
}

Test(queue, peek_empty)
{
    queue_t *queue = NULL;

    cr_assert_eq(queue_peek(NULL), NULL);
    cr_assert_eq(queue_peek(queue), NULL);
    queue = malloc(sizeof(queue_t));
    queue->data = NULL;
    queue->head = NULL;
    queue->tail = NULL;
    cr_assert_eq(queue_peek(queue), NULL);
    if (queue != NULL)
        queue_free(queue);
}

Test(queue, size)
{
    queue_t *queue = NULL;
    int data = 42;

    cr_assert_eq(queue_size(NULL), 0);
    cr_assert_eq(queue_size(queue), 0);
    queue = malloc(sizeof(queue_t));
    queue->data = NULL;
    queue->head = NULL;
    queue->tail = NULL;
    cr_assert_eq(queue_size(queue), 0);
    queue_enqueue(&queue, &data);
    cr_assert_eq(queue_size(queue), 1);
    if (queue != NULL)
        queue_free(queue);
}

Test(queue, size_a_lot)
{
    queue_t *queue = NULL;
    int data[DATASET_SIZE];

    cr_assert_eq(queue_size(queue), 0);
    for (int i = 0; i < DATASET_SIZE; i++) {
        data[i] = i;
        queue_enqueue(&queue, &data[i]);
        cr_assert_eq(queue_size(queue), i + 1);
    }
    cr_assert_eq(queue_size(queue), DATASET_SIZE);
    for (int i = 0; i < DATASET_SIZE; i++) {
        queue_dequeue(&queue);
        cr_assert_eq(queue_size(queue), DATASET_SIZE - i - 1);
    }
    if (queue != NULL)
        queue_free(queue);
}

Test(queue, free)
{
    queue_t *queue = malloc(sizeof(queue_t));
    int data = 42;

    queue->data = NULL;
    queue->head = NULL;
    queue->tail = NULL;
    queue_free(queue);
    queue = NULL;
    queue_enqueue(&queue, &data);
    queue_free(queue);
    queue = NULL;
    queue_enqueue(&queue, &data);
    queue_enqueue(&queue, &data);
    queue_enqueue(&queue, &data);
    queue_enqueue(&queue, &data);
    queue_enqueue(&queue, &data);
    queue_enqueue(&queue, &data);
    queue_dequeue(&queue);
    queue_free(queue);
    queue_free(NULL);
}

Test(queue, free_all)
{
    queue_t *queue = NULL;
    int *tmp = NULL;

    for (int i = 0; i < DATASET_SIZE; i++) {
        tmp = malloc(sizeof(int));
        *tmp = i;
        queue_enqueue(&queue, tmp);
    }
    queue_free_all(queue);
    queue_free_all(NULL);
}
