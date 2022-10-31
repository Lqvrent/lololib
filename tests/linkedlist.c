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

Test(linkedlist, ll_pop_front_empty)
{
    linkedlist_t *list = NULL;

    cr_assert_eq(ll_pop_front(&list), NULL);
}

Test(linkedlist, ll_pop_front)
{
    linkedlist_t *list = NULL;
    int data = 42;
    void *data_ptr = &data;

    ll_push_front(&list, data_ptr);
    cr_assert_eq(ll_pop_front(&list), data_ptr);
    cr_assert_eq(list, NULL);
}

Test(linkedlist, ll_pop_front_a_lot)
{
    linkedlist_t *list = NULL;
    int data = 42;
    void *data_ptr = &data;

    for (int i = 0; i < 100; i++)
        ll_push_front(&list, data_ptr);
    for (int i = 0; i < 100; i++)
        cr_assert_eq(ll_pop_front(&list), data_ptr);
    cr_assert_eq(list, NULL);
}

Test(linkedlist, ll_pop_back_empty)
{
    linkedlist_t *list = NULL;

    cr_assert_eq(ll_pop_back(&list), NULL);
}

Test(linkedlist, ll_pop_back)
{
    linkedlist_t *list = NULL;
    int data = 42;
    void *data_ptr = &data;

    ll_push_front(&list, data_ptr);
    cr_assert_eq(ll_pop_back(&list), data_ptr);
    cr_assert_eq(list, NULL);
}

Test(linkedlist, ll_pop_back_a_lot)
{
    linkedlist_t *list = NULL;
    int data = 42;
    void *data_ptr = &data;

    for (int i = 0; i < 100; i++)
        ll_push_front(&list, data_ptr);
    for (int i = 0; i < 100; i++)
        cr_assert_eq(ll_pop_back(&list), data_ptr);
    cr_assert_eq(list, NULL);
}

Test(linkedlist, ll_pop_empty)
{
    linkedlist_t *list = NULL;

    cr_assert_eq(ll_pop(&list, 0), NULL);
}

Test(linkedlist, ll_pop)
{
    linkedlist_t *list = NULL;
    int data = 42;
    void *data_ptr = &data;

    ll_push_front(&list, data_ptr);
    cr_assert_eq(ll_pop(&list, data_ptr), data_ptr);
    cr_assert_eq(list, NULL);
}

Test(linkedlist, ll_pop_not_found_solo)
{
    linkedlist_t *list = NULL;
    int data = 42;
    void *data_ptr = &data;

    ll_push_front(&list, data_ptr);
    cr_assert_eq(ll_pop(&list, NULL), NULL);
    cr_assert_eq(list->data, data_ptr);
    cr_assert_eq(list->next, NULL);
    if (list != NULL)
        ll_free(list);
}

Test(linkedlist, ll_pop_not_found)
{
    linkedlist_t *list = NULL;
    int data = 42;
    void *data_ptr = &data;

    ll_push_front(&list, data_ptr);
    ll_push_front(&list, data_ptr);
    ll_push_front(&list, data_ptr);
    cr_assert_eq(ll_pop(&list, NULL), NULL);
    cr_assert_eq(list->data, data_ptr);
    cr_assert_eq(list->next->data, data_ptr);
    cr_assert_eq(list->next->next->data, data_ptr);
    cr_assert_eq(list->next->next->next, NULL);
    if (list != NULL)
        ll_free(list);
}

Test(linkedlist, ll_pop_a_lot)
{
    linkedlist_t *list = NULL;
    int data = 42;
    int another_data = 24;
    void *data_ptr = &data;
    void *another_data_ptr = &another_data;

    for (int i = 0; i < 100; i++)
        if (i % 2 == 0)
            ll_push_front(&list, data_ptr);
        else
            ll_push_front(&list, another_data_ptr);
    for (int i = 0; i < 100; i++)
        if (i % 2 == 0)
            cr_assert_eq(ll_pop(&list, data_ptr), data_ptr);
        else
            cr_assert_eq(ll_pop(&list, another_data_ptr), another_data_ptr);
    cr_assert_eq(list, NULL);
}

Test(linkedlist, ll_pop_at_empty)
{
    linkedlist_t *list = NULL;

    cr_assert_eq(ll_pop_at(&list, 0), NULL);
}

Test(linkedlist, ll_pop_at)
{
    linkedlist_t *list = NULL;
    int data = 42;
    void *data_ptr = &data;

    ll_push_front(&list, data_ptr);
    cr_assert_eq(ll_pop_at(&list, 0), data_ptr);
    cr_assert_eq(list, NULL);
}

Test(linkedlist, ll_pop_at_not_found_solo)
{
    linkedlist_t *list = NULL;
    int data = 42;
    void *data_ptr = &data;

    ll_push_front(&list, data_ptr);
    cr_assert_eq(ll_pop_at(&list, 1), NULL);
    cr_assert_eq(list->data, data_ptr);
    cr_assert_eq(list->next, NULL);
    if (list != NULL)
        ll_free(list);
}

Test(linkedlist, ll_pop_at_not_found)
{
    linkedlist_t *list = NULL;
    int data = 42;
    void *data_ptr = &data;

    ll_push_front(&list, data_ptr);
    cr_assert_eq(ll_pop_at(&list, 1), NULL);
    cr_assert_eq(list->data, data_ptr);
    cr_assert_eq(list->next, NULL);
    if (list != NULL)
        ll_free(list);
}

Test(linkedlist, ll_pop_at_a_lot)
{
    linkedlist_t *list = NULL;
    int data = 42;
    int another_data = 24;
    void *data_ptr = &data;
    void *another_data_ptr = &another_data;

    for (int i = 0; i < 100; i++)
        if (i % 2 == 0)
            ll_push_back(&list, data_ptr);
        else
            ll_push_back(&list, another_data_ptr);
    cr_assert_eq(ll_pop_at(&list, 42), data_ptr);
    cr_assert_eq(ll_pop_at(&list, 42), another_data_ptr);
    if (list != NULL)
        ll_free(list);
}

Test(linkedlist, ll_pop_at_out_of_range)
{
    linkedlist_t *list = NULL;
    int data = 42;
    void *data_ptr = &data;

    ll_push_front(&list, data_ptr);
    cr_assert_eq(ll_pop_at(&list, 42), NULL);
    cr_assert_eq(list->data, data_ptr);
    cr_assert_eq(list->next, NULL);
    if (list != NULL)
        ll_free(list);
}
