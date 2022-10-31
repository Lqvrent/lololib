#include <criterion/criterion.h>
#include "../includes/lolo/linkedlist.h"

Test(linkedlist, ll_push_front)
{
    linkedlist_t *list = NULL;
    int data = 42;
    void *data_ptr = &data;

    ll_push_front(&list, data_ptr);
    cr_assert_eq(list->data, data_ptr);
    cr_assert_eq(list->next, NULL);
    if (list != NULL)
        ll_free(list);
}

Test(linkedlist, ll_push_front_a_lot)
{
    linkedlist_t *list = NULL;
    linkedlist_t **tmp = &list;
    int data = 42;
    void *data_ptr = &data;

    for (int i = 0; i < 100; i++)
        ll_push_front(&list, data_ptr);
    cr_assert_eq(list->data, data_ptr);
    while ((*tmp)->next != NULL)
        *tmp = (*tmp)->next;
    cr_assert_eq((*tmp)->data, data_ptr);
    cr_assert_eq((*tmp)->next, NULL);
    if (list != NULL)
        ll_free(list);
}

Test(linkedlist, ll_push_back_empty)
{
    linkedlist_t *list = NULL;
    int data = 42;
    void *data_ptr = &data;

    ll_push_back(&list, data_ptr);
    cr_assert_eq(list->data, data_ptr);
    cr_assert_eq(list->next, NULL);
    if (list != NULL)
        ll_free(list);
}

Test(linkedlist, ll_push_back_a_lot)
{
    linkedlist_t *list = NULL;
    linkedlist_t **tmp = &list;
    int data = 42;
    void *data_ptr = &data;

    for (int i = 0; i < 100; i++)
        ll_push_back(&list, data_ptr);
    cr_assert_eq(list->data, data_ptr);
    while ((*tmp)->next != NULL)
        *tmp = (*tmp)->next;
    cr_assert_eq((*tmp)->data, data_ptr);
    cr_assert_eq((*tmp)->next, NULL);
    if (list != NULL)
        ll_free(list);
}
