#include <criterion/criterion.h>
#include <stdio.h>
#include "../includes/lolo/hashmap.h"
#include "../includes/lolo/string.h"
#define DATASET_SIZE 50

Test(hashmap, put_one)
{
    hashmap_t *map = NULL;

    hm_put(&map, "key", "value");
    cr_assert_not_null(map);
    cr_assert_str_eq(map->key, "key");
    cr_assert_str_eq(map->data, "value");
}

Test(hashmap, put_a_lot)
{
    hashmap_t *map = NULL;
    char key[DATASET_SIZE];
    char value[] = "value";
    int i = 0;
    int containsKey = 0;

    for (; i < DATASET_SIZE; i++) {
        sprintf(key, "key%d", i);
        hm_put(&map, key, value);
    }
    cr_assert_not_null(map);
    for (hashmap_t *tmp = map; tmp != NULL; tmp = tmp->next) {
        containsKey = string_includes(tmp->key, "key");
        cr_assert_eq(containsKey, 1);
        cr_assert_str_eq(tmp->data, value);
    }
}
