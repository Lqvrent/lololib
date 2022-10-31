#include "lolo/linkedlist.h"
#include <stdlib.h>

void ll_push_front(linkedlist_t **list, void *data)
{
    linkedlist_t *node = malloc(sizeof(linkedlist_t));

    if (node == NULL)
        return;
    node->data = data;
    node->next = *list;
    *list = node;
}

void ll_push_back(linkedlist_t **list, void *data)
{
    linkedlist_t *node = malloc(sizeof(linkedlist_t));
    linkedlist_t *tmp = *list;

    if (node == NULL)
        return;
    node->data = data;
    node->next = NULL;
    if (*list == NULL) {
        *list = node;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
}

void *ll_pop_front(linkedlist_t **list)
{
    linkedlist_t *tmp = *list;
    void *data = NULL;

    if (*list == NULL)
        return (NULL);
    data = (*list)->data;
    *list = (*list)->next;
    free(tmp);
    return (data);
}

void *ll_pop_back(linkedlist_t **list)
{
    linkedlist_t *tmp = *list;
    linkedlist_t *prev = NULL;
    void *data = NULL;

    if (*list == NULL)
        return (NULL);
    while (tmp->next != NULL) {
        prev = tmp;
        tmp = tmp->next;
    }
    data = tmp->data;
    if (prev != NULL)
        prev->next = NULL;
    else
        *list = NULL;
    free(tmp);
    return (data);
}

void *ll_pop(linkedlist_t **list, void *data)
{
    linkedlist_t *tmp = *list;
    linkedlist_t *prev = NULL;

    if (*list == NULL)
        return (NULL);
    while (tmp->data != data && tmp->next != NULL) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp->data != data)
        return (NULL);
    if (prev != NULL)
        prev->next = tmp->next;
    else
        *list = tmp->next;
    free(tmp);
    return (data);
}

void *ll_pop_at(linkedlist_t **list, unsigned int index)
{
    linkedlist_t *tmp = *list;
    linkedlist_t *prev = NULL;
    void *data = NULL;

    if (*list == NULL)
        return (NULL);
    for (unsigned int i = 0; i < index && tmp->next != NULL; i++) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp->next == NULL && index != 0)
        return (NULL);
    data = tmp->data;
    if (prev != NULL)
        prev->next = tmp->next;
    else
        *list = tmp->next;
    free(tmp);
    return (data);
}

void ll_free(linkedlist_t *list)
{
    linkedlist_t *tmp = list;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}
