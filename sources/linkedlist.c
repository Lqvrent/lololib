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

void ll_free(linkedlist_t *list)
{
    linkedlist_t *tmp = list;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}
