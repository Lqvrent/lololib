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
