#include "lolo/hashmap.h"
#include <string.h>
#include <stdlib.h>

void *hm_put(hashmap_t **map, char *key, void *data)
{
    hashmap_t *new = malloc(sizeof(hashmap_t));
    hashmap_t *tmp = *map;

    new->key = strdup(key);
    new->data = data;
    new->next = NULL;
    if (*map == NULL) {
        *map = new;
        return (new);
    }
    while (tmp->next != NULL && strcmp(tmp->next->key, key) < 0) // insert by sorted key
        tmp = tmp->next;
    new->next = tmp->next;
    tmp->next = new;
    return (new);
}

void *hm_get(hashmap_t **map, char *key)
{
    hashmap_t *tmp = *map;

    while (tmp != NULL) {
        if (strcmp(tmp->key, key) == 0)
            return (tmp->data);
        tmp = tmp->next;
    }
    return (NULL);
}

void *hm_remove(hashmap_t **map, char *key)
{
    hashmap_t *tmp = *map;
    hashmap_t *prev = NULL;
    void *data = NULL;

    while (tmp != NULL) {
        if (strcmp(tmp->key, key) == 0) {
            data = tmp->data;
            if (prev == NULL)
                *map = tmp->next;
            else
                prev->next = tmp->next;
            free(tmp->key);
            free(tmp);
            return (data);
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return (NULL);
}

int hm_size(hashmap_t **map)
{
    hashmap_t *tmp = *map;
    int size = 0;

    while (tmp != NULL) {
        size++;
        tmp = tmp->next;
    }
    return (size);
}
