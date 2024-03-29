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
    unsigned int i = 0;

    if (*list == NULL)
        return (NULL);
    while (i < index && tmp->next != NULL) {
        prev = tmp;
        tmp = tmp->next;
        i++;
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

void *ll_get_front(linkedlist_t *list)
{
    if (list == NULL)
        return (NULL);
    return (list->data);
}

void *ll_get_back(linkedlist_t *list)
{
    if (list == NULL)
        return (NULL);
    while (list->next != NULL)
        list = list->next;
    return (list->data);
}

void *ll_get(linkedlist_t *list, unsigned int index)
{
    unsigned int i = 0;

    if (list == NULL)
        return (NULL);
    while (list->next != NULL && i < index) {
        list = list->next;
        i++;
    }
    if (i != index)
        return (NULL);
    return (list->data);
}

unsigned int ll_size(linkedlist_t *list)
{
    unsigned int size = 0;

    while (list != NULL) {
        list = list->next;
        size++;
    }
    return (size);
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

void ll_free_all(linkedlist_t *list)
{
    linkedlist_t *tmp = list;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp->data);
        free(tmp);
    }
}
