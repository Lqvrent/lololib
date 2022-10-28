#include <criterion/criterion.h>
#include "../source/string.h"

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

Test(string, string_is_alpha_w_badminusascii)
{
    cr_assert_eq(string_is_alpha("AbCdEfGhIjKlMn+pQrSTuVWxYz"), 0);
}

Test(string, string_is_alpha_w_badplusascii)
{
    cr_assert_eq(string_is_alpha("AbCdEfGhIjKlMn~pQrSTuVWxYz"), 0);
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

Test(string, string_is_numeric_w_space)
{
    cr_assert_eq(string_is_numeric(" "), 0);
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
    cr_assert_eq(string_is_alphanum("123456789O~"), 0);
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

Test(string, string_is_printable_w_linebreak)
{
    cr_assert_eq(string_is_printable("123\n"), 0);
}

Test(string, string_is_printable_w_del)
{
    cr_assert_eq(string_is_printable("123\177"), 0);
}

Test(string, string_to_upper_w_empty)
{
    char str[] = "";

    string_to_upper(str);
    cr_assert_str_eq(str, "");
}

Test(string, string_to_upper_w_lower)
{
    char str[] = "abcdefghijklmnopqrstuvwxyz";

    string_to_upper(str);
    cr_assert_str_eq(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

Test(string, string_to_upper_w_mixed)
{
    char str[] = "AbCdEfGhIjKlMnOpQrSTuVWxYz";

    string_to_upper(str);
    cr_assert_str_eq(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

Test(string, string_to_upper_w_spaces)
{
    char str[] = "AbCd EfGh IjKl MnOp QrST uVWx Yz";

    string_to_upper(str);
    cr_assert_str_eq(str, "ABCD EFGH IJKL MNOP QRST UVWX YZ");
}

Test(string, string_to_upper_w_specials)
{
    char str[] = "AbCd!EfGh?IjKl;MnOp~QrST~uVWxYz";

    string_to_upper(str);
    cr_assert_str_eq(str, "ABCD!EFGH?IJKL;MNOP~QRST~UVWXYZ");
}

Test(string, string_to_lower_w_empty)
{
    char str[] = "";

    string_to_lower(str);
    cr_assert_str_eq(str, "");
}

Test(string, string_to_lower_w_upper)
{
    char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string_to_lower(str);
    cr_assert_str_eq(str, "abcdefghijklmnopqrstuvwxyz");
}

Test(string, string_to_lower_w_mixed)
{
    char str[] = "AbCdEfGhIjKlMnOpQrSTuVWxYz";

    string_to_lower(str);
    cr_assert_str_eq(str, "abcdefghijklmnopqrstuvwxyz");
}

Test(string, string_to_lower_w_spaces)
{
    char str[] = "AbCd EfGh IjKl MnOp QrST uVWx Yz";

    string_to_lower(str);
    cr_assert_str_eq(str, "abcd efgh ijkl mnop qrst uvwx yz");
}

Test(string, string_to_lower_w_specials)
{
    char str[] = "AbCd!EfGh?IjKl;MnOp~QrST~uVWxYz";

    string_to_lower(str);
    cr_assert_str_eq(str, "abcd!efgh?ijkl;mnop~qrst~uvwxyz");
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

Test(string, string_split_empty)
{
    char **arr = string_split("", "");

    cr_assert_null(arr[0]);
    if (arr != NULL) {
        free(arr[0]);
        free(arr);
    }
}

Test(string, string_split_empty_seps)
{
    char **arr = string_split("Hello world !", "");

    cr_assert_null(arr[0]);
    if (arr != NULL) {
        free(arr[0]);
        free(arr);
    }
}

Test(string, string_split_simple)
{
    char **arr = string_split("Hello world", " ");

    cr_assert_str_eq(arr[0], "Hello");
    cr_assert_str_eq(arr[1], "world");
    cr_assert_null(arr[2]);
    if (arr != NULL) {
        free(arr[0]);
        free(arr[1]);
        free(arr);
    }
}

Test(string, string_split_by_word)
{
    char **arr = string_split("Hello my world !", " my ");

    cr_assert_str_eq(arr[0], "Hello");
    cr_assert_str_eq(arr[1], "world !");
    cr_assert_null(arr[2]);
    if (arr != NULL) {
        free(arr[0]);
        free(arr[1]);
        free(arr);
    }
}

Test(string, string_split_valid_multiple_seps)
{
    char **arr = string_split("   Hello world  !     ", " ");

    cr_assert_str_eq(arr[0], "Hello");
    cr_assert_str_eq(arr[1], "world");
    cr_assert_str_eq(arr[2], "!");
    cr_assert_null(arr[3]);
    if (arr != NULL) {
        free(arr[0]);
        free(arr[1]);
        free(arr[2]);
        free(arr);
    }
}

Test(string, string_split_valid_multiple_seps_by_word)
{
    char **arr = string_split("abcabcabcdefabcabc", "abc");

    cr_assert_str_eq(arr[0], "def");
    cr_assert_null(arr[1]);
    if (arr != NULL) {
        free(arr[0]);
        free(arr);
    }
}

Test(string, string_split_by_tok_empty)
{
    char **arr = string_split_by_tok("", " ");

    cr_assert_null(arr[0]);
    if (arr != NULL) {
        free(arr[0]);
        free(arr);
    }
}

Test(string, string_split_by_tok_empty_delims)
{
    char **arr = string_split_by_tok("Hello world !", "");

    cr_assert_null(arr[0]);
    if (arr != NULL) {
        free(arr[0]);
        free(arr);
    }
}

Test(string, string_split_by_tok_valid)
{
    char **arr = string_split_by_tok("Hello world !", " ");

    cr_assert_str_eq(arr[0], "Hello");
    cr_assert_str_eq(arr[1], "world");
    cr_assert_str_eq(arr[2], "!");
    cr_assert_null(arr[3]);
    if (arr != NULL) {
        free(arr[0]);
        free(arr[1]);
        free(arr[2]);
        free(arr);
    }
}

Test(string, string_split_by_tok_valid_too)
{
    char **arr = string_split_by_tok("Hello world !", "o");

    cr_assert_str_eq(arr[0], "Hell");
    cr_assert_str_eq(arr[1], " w");
    cr_assert_str_eq(arr[2], "rld !");
    cr_assert_null(arr[3]);
    if (arr != NULL) {
        free(arr[0]);
        free(arr[1]);
        free(arr[2]);
        free(arr);
    }
}

Test(string, string_split_by_tok_stupid)
{
    char **arr = string_split_by_tok("Hello world !", "Hello world !");

    cr_assert_null(arr[0]);
    if (arr != NULL)
        free(arr);
}

Test(string, string_split_by_tok_multiple_seps)
{
    char **arr = string_split_by_tok("I want ; to be w you", " ;");

    cr_assert_str_eq(arr[0], "I");
    cr_assert_str_eq(arr[1], "want");
    cr_assert_str_eq(arr[2], "to");
    cr_assert_str_eq(arr[3], "be");
    cr_assert_str_eq(arr[4], "w");
    cr_assert_str_eq(arr[5], "you");
    cr_assert_null(arr[6]);
    if (arr != NULL) {
        free(arr[0]);
        free(arr[1]);
        free(arr[2]);
        free(arr[3]);
        free(arr[4]);
        free(arr[5]);
        free(arr);
    }
}

Test(string, string_split_by_tok_delim_in_a_row)
{
    char **arr = string_split_by_tok("    Hello         world        !     ", " ");

    cr_assert_str_eq(arr[0], "Hello");
    cr_assert_str_eq(arr[1], "world");
    cr_assert_str_eq(arr[2], "!");
    cr_assert_null(arr[3]);
    if (arr != NULL) {
        free(arr[0]);
        free(arr[1]);
        free(arr[2]);
        free(arr);
    }
}

Test(string, string_array_free)
{
    // Test wrote to check if string_array_free() produces a crash
    // This is why it doesn't contains an assert fct
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

Test(string, string_replace_none)
{
    char *str = string_replace("Hello world !", "abc", "def");

    cr_assert_str_eq(str, "Hello world !");
    if (str != NULL)
        free(str);
}

Test(string, string_replace_one)
{
    char *str = string_replace("Hello world !", "world", "you");

    cr_assert_str_eq(str, "Hello you !");
    if (str != NULL)
        free(str);
}

Test(string, string_replace_multiple)
{
    char *str = string_replace("Hello world ! Hello world !", "world", "you");

    cr_assert_str_eq(str, "Hello you ! Hello you !");
    if (str != NULL)
        free(str);
}

Test(string, string_replace_all)
{
    char *str = string_replace("Hello world !", "Hello world !", "Changing the string");

    cr_assert_str_eq(str, "Changing the string");
    if (str != NULL)
        free(str);
}
