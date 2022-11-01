#include "lolo/queue.h"
#include <stdlib.h>

void queue_enqueue(queue_t **queue, void *data)
{
    queue_node_t *node = NULL;

    if (*queue == NULL) {
        *queue = malloc(sizeof(queue_t));
        if (*queue == NULL)
            return;
        (*queue)->data = NULL;
        (*queue)->head = NULL;
        (*queue)->tail = NULL;
    }
    node = malloc(sizeof(queue_node_t));
    if (node == NULL)
        return;
    node->data = data;
    node->next = NULL;
    if ((*queue)->data == NULL) {
        (*queue)->data = node;
        (*queue)->head = node;
        (*queue)->tail = node;
    } else {
        (*queue)->tail->next = node;
        (*queue)->tail = node;
    }
}

void *queue_dequeue(queue_t **queue)
{
    queue_node_t *node = NULL;
    void *data = NULL;

    if (queue == NULL || *queue == NULL || (*queue)->data == NULL)
        return (NULL);
    node = (*queue)->data;
    data = node->data;
    (*queue)->data = node->next;
    if ((*queue)->data == NULL) {
        (*queue)->head = NULL;
        (*queue)->tail = NULL;
    }
    free(node);
    return data;
}

void *queue_peek(queue_t *queue)
{
    if (queue == NULL || queue->data == NULL)
        return (NULL);
    return (queue->data->data);
}

unsigned int queue_size(queue_t *queue)
{
    unsigned int size = 0;
    queue_node_t *tmp = NULL;

    if (queue == NULL || queue->data == NULL)
        return (0);
    tmp = queue->data;
    while (tmp != NULL) {
        size++;
        tmp = tmp->next;
    }
    return (size);
}

void queue_free(queue_t *queue)
{
    queue_node_t *tmp = NULL;

    if (queue == NULL)
        return;
    while (queue->data != NULL) {
        tmp = queue->data;
        queue->data = queue->data->next;
        free(tmp);
    }
    free(queue);
}

void queue_free_all(queue_t *queue)
{
    queue_node_t *tmp = NULL;

    if (queue == NULL)
        return;
    while (queue->data != NULL) {
        tmp = queue->data;
        queue->data = queue->data->next;
        free(tmp->data);
        free(tmp);
    }
}
