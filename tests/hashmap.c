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

Test(hashmap, get_one)
{
    hashmap_t *map = NULL;
    char *value = NULL;

    hm_put(&map, "key", "value");
    value = hm_get(&map, "key");
    cr_assert_not_null(value);
    cr_assert_str_eq(value, "value");
}

Test(hashmap, get_not_found)
{
    hashmap_t *map = NULL;
    char *value = NULL;

    hm_put(&map, "key", "value");
    value = hm_get(&map, "key2");
    cr_assert_null(value);
}

Test(hashmap, get_a_lot)
{
    hashmap_t *map = NULL;
    char key[DATASET_SIZE];
    char value[] = "value";
    char *data = NULL;
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
        data = hm_get(&map, tmp->key);
        cr_assert_not_null(data);
        cr_assert_str_eq(data, value);
    }
}

Test(hashmap, remove_one)
{
    hashmap_t *map = NULL;
    char *value = NULL;

    hm_put(&map, "key", "value");
    value = hm_remove(&map, "key");
    cr_assert_not_null(value);
    cr_assert_str_eq(value, "value");
    cr_assert_null(map);
}

Test(hashmap, remove_not_found)
{
    hashmap_t *map = NULL;
    char *value = NULL;

    hm_put(&map, "key", "value");
    value = hm_remove(&map, "key2");
    cr_assert_null(value);
    cr_assert_not_null(map);
}

Test(hashmap, remove_a_lot)
{
    hashmap_t *map = NULL;
    char key[DATASET_SIZE];
    char value[] = "value";
    char *data = NULL;
    int i = 0;
    int containsKey = 0;

    for (; i < DATASET_SIZE; i++) {
        sprintf(key, "key%d", i);
        hm_put(&map, key, value);
    }
    cr_assert_not_null(map);
    data = hm_remove(&map, "key42");
    cr_assert_not_null(data);
    cr_assert_str_eq(data, value);
}

Test(hashmap, size_empty)
{
    hashmap_t *map = NULL;
    int size = hm_size(&map);

    cr_assert_eq(size, 0);
}

Test(hashmap, size_one)
{
    hashmap_t *map = NULL;
    int size = 0;

    hm_put(&map, "key", "value");
    size = hm_size(&map);
    cr_assert_eq(size, 1);
}

Test(hashmap, size_a_lot)
{
    hashmap_t *map = NULL;
    char key[DATASET_SIZE];
    char value[] = "value";
    int i = 0;
    int size = 0;

    for (; i < DATASET_SIZE; i++) {
        sprintf(key, "key%d", i);
        hm_put(&map, key, value);
    }
    size = hm_size(&map);
    cr_assert_eq(size, DATASET_SIZE);
}
