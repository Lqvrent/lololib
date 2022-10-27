#include <criterion/criterion.h>
#include "string.h"

Test(string, string_is_empty_w_null)
{
    cr_assert_eq(string_is_empty(NULL), 1);
}

Test(string, string_is_empty_w_empty)
{
    cr_assert_eq(string_is_empty(""), 1);
}

Test(string, string_is_empty_w_filled)
{
    cr_assert_eq(string_is_empty("lololib"), 0);
}

Test(string, string_is_alpha_w_lowalpha)
{
    cr_assert_eq(string_is_alpha("abcdefghijklmnopqrstuvwxyz"), 1);
}

Test(string, string_is_alpha_w_upalpha)
{
    cr_assert_eq(string_is_alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), 1);
}

Test(string, string_is_alpha_w_mixedalpha)
{
    cr_assert_eq(string_is_alpha("AbCdEfGhIjKlMnOpQrSTuVWxYz"), 1);
}

Test(string, string_is_alpha_w_numalpha)
{
    cr_assert_eq(string_is_alpha("AbCdEfGhIjKlMn0pQrSTuVWxYz"), 0);
}

Test(string, string_is_numeric_w_alpha)
{
    cr_assert_eq(string_is_numeric("a"), 0);
}

Test(string, string_is_numeric_w_num)
{
    cr_assert_eq(string_is_numeric("0"), 1);
}

Test(string, string_is_numeric_w_badnum)
{
    cr_assert_eq(string_is_numeric("123456789O"), 0);
}

Test(string, string_is_alphanum_w_alpha)
{
    cr_assert_eq(string_is_alphanum("abc"), 1);
}

Test(string, string_is_alphanum_w_num)
{
    cr_assert_eq(string_is_alphanum("123"), 1);
}

Test(string, string_is_alphanum_w_alphanum)
{
    cr_assert_eq(string_is_alphanum("123456789O"), 1);
}

Test(string, string_is_alphanum_w_alphanumspaces)
{
    cr_assert_eq(string_is_alphanum("123 456789O"), 0);
}

Test(string, string_is_alphanum_w_invalid)
{
    cr_assert_eq(string_is_alphanum("123456789O!"), 0);
}

Test(string, string_is_printable_w_alpha)
{
    cr_assert_eq(string_is_printable("abc"), 1);
}

Test(string, string_is_printable_w_num)
{
    cr_assert_eq(string_is_printable("123"), 1);
}

Test(string, string_is_printable_w_alphanum)
{
    cr_assert_eq(string_is_printable("123456789O"), 1);
}

Test(string, string_is_printable_w_alphanumspaces)
{
    cr_assert_eq(string_is_printable("123 456789O"), 1);
}

Test(string, string_is_printable_w_invalid)
{
    cr_assert_eq(string_is_printable("123456789O!"), 0);
}

Test(string, string_to_upper_w_empty)
{
    char str[] = "";

    string_to_upper(str);
    cr_assert_str_eq(str, "");
}

Test(string, string_to_upper_w_lower)
{
    char str[] = "lqvrent";

    string_to_upper(str);
    cr_assert_str_eq(str, "LQVRENT");
}

Test(string, string_to_upper_w_mixed)
{
    char str[] = "lQvReNt";

    string_to_upper(str);
    cr_assert_str_eq(str, "LQVRENT");
}


Test(string, string_to_lower_w_empty)
{
    char str[] = "";

    string_to_lower(str);
    cr_assert_str_eq(str, "");
}

Test(string, string_to_lower_w_upper)
{
    char str[] = "LQVRENT";

    string_to_lower(str);
    cr_assert_str_eq(str, "lqvrent");
}

Test(string, string_to_lower_w_mixed)
{
    char str[] = "lQvReNt";

    string_to_lower(str);
    cr_assert_str_eq(str, "lqvrent");
}

Test(string, string_capitalize_w_empty)
{
    char str[] = "";

    string_capitalize(str);
    cr_assert_str_eq(str, "");
}

Test(string, string_capitalize_w_oneword)
{
    char str[] = "hello";

    string_capitalize(str);
    cr_assert_str_eq(str, "Hello");
}

Test(string, string_capitalize_w_multiplewords)
{
    char str[] = "hello world !";

    string_capitalize(str);
    cr_assert_str_eq(str, "Hello World !");
}

Test(string, string_capitalize_w_somuchwords)
{
    char str[] = "hello world,how are you doing today ?lol";

    string_capitalize(str);
    cr_assert_str_eq(str, "Hello World,How Are You Doing Today ?Lol");
}

Test(string, string_capitalize_w_wordstofix)
{
    char str[] = "hElLo WOrlD,hOw aRe you DoiNg tOdAy ?lOl";

    string_capitalize(str);
    cr_assert_str_eq(str, "Hello World,How Are You Doing Today ?Lol");
}

Test(string, string_length_w_empty)
{
    cr_assert_eq(string_length(""), 0);
}

Test(string, string_length_w_valid)
{
    cr_assert_eq(string_length("abc"), 3);
}

Test(string, string_reverse_w_empty)
{
    char str[] = "";

    string_reverse(str);
    cr_assert_str_eq(str, "");
}

Test(string, string_reverse_w_valid3)
{
    char str[] = "abc";

    string_reverse(str);
    cr_assert_str_eq(str, "cba");
}

Test(string, string_reverse_w_valid6)
{
    char str[] = "abcdef";

    string_reverse(str);
    cr_assert_str_eq(str, "fedcba");
}

Test(string, string_includes_w_invalid)
{
    cr_assert_eq(string_includes("Hello world !", "It's me ! Mario!!"), 0);
}

Test(string, string_includes_w_valid)
{
    cr_assert_eq(string_includes("Hello world !", "world"), 1);
}

Test(string, string_starts_with_w_invalid1)
{
    cr_assert_eq(string_starts_with("Hello world !", "world !"), 0);
}

Test(string, string_starts_with_w_invalid2)
{
    cr_assert_eq(string_starts_with("Hello", "Hello world !"), 0);
}

Test(string, string_starts_with_w_valid)
{
    cr_assert_eq(string_starts_with("Hello world !", "Hello"), 1);
}

Test(string, string_ends_with_w_invalid1)
{
    cr_assert_eq(string_ends_with("Hello world", "Hello"), 0);
}

Test(string, string_ends_with_w_valid)
{
    cr_assert_eq(string_ends_with("Hello world", "world"), 1);
}

Test(string, string_count_with_nooccurence)
{
    cr_assert_eq(string_count("Hello world is just a simple sentence I think.", "Lqvrent"), 0);
}

Test(string, string_count_with_valid1)
{
    cr_assert_eq(string_count("Hello world is just a simple sentence I think.", "world"), 1);
}

Test(string, string_count_with_valid2)
{
    cr_assert_eq(string_count("Hello world is just a simple world I think.", "world"), 2);
}

Test(string, string_repeat_empty)
{
    char *str = string_repeat("", 42);

    cr_assert_str_eq(str, "");
    if (str != NULL)
        free(str);
}

Test(string, string_repeat_zero)
{
    char *str = string_repeat("abc", 0);

    cr_assert_null(str);
    if (str != NULL)
        free(str);
}

Test(string, string_repeat_valid)
{
    char *str = string_repeat("abc", 3);

    cr_assert_str_eq(str, "abcabcabc");
    if (str != NULL)
        free(str);
}

Test(string, string_repeat_valid1)
{
    char *str = string_repeat("abc", 1);

    cr_assert_str_eq(str, "abc");
    if (str != NULL)
        free(str);
}

Test(string, string_slice_valid)
{
    char *str = string_slice("Hello world !", 6, 11);

    cr_assert_str_eq(str, "world");
    if (str != NULL)
        free(str);
}

Test(string, string_split_valid1)
{
    char **arr = string_split("Hello world !", " ");

    cr_assert_str_eq(arr[0], "Hello");
    cr_assert_str_eq(arr[1], "world");
    cr_assert_str_eq(arr[2], "!");
    cr_assert_null(arr[3]);
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}

Test(string, string_split_valid2)
{
    char **arr = string_split("Hello my world !", " my ");

    cr_assert_str_eq(arr[0], "Hello");
    cr_assert_str_eq(arr[1], "world !");
    cr_assert_null(arr[2]);
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}

Test(string, string_split_valid_hard1)
{
    char **arr = string_split("   Hello world  !     ", " ");

    cr_assert_str_eq(arr[0], "Hello");
    cr_assert_str_eq(arr[1], "world");
    cr_assert_str_eq(arr[2], "!");
    cr_assert_null(arr[3]);
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}

Test(string, string_split_valid_hard2)
{
    char **arr = string_split("abcabcdefabcabc", "abc");

    cr_assert_str_eq(arr[0], "def");
    cr_assert_null(arr[1]);
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}

Test(string, string_array_free)
{
    char **arr = malloc(sizeof(char *) * 2);
    arr[0] = malloc(string_length("Hello") + 1);
    arr[0][0] = 'H';
    arr[0][1] = 'e';
    arr[0][2] = 'l';
    arr[0][3] = 'l';
    arr[0][4] = 'o';
    arr[0][5] = '\0';
    arr[1] = NULL;

    string_array_free(arr);
}
