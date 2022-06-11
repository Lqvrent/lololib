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

Test(string, string_is_alpha_w_null)
{
    cr_assert_eq(string_is_alpha(NULL), 0);
}

Test(string, string_is_alpha_w_empty)
{
    cr_assert_eq(string_is_alpha(""), 0);
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

Test(string, string_is_numeric_w_null)
{
    cr_assert_eq(string_is_numeric(NULL), 0);
}

Test(string, string_is_numeric_w_empty)
{
    cr_assert_eq(string_is_numeric(""), 0);
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

Test(string, string_is_alphanum_w_null)
{
    cr_assert_eq(string_is_alphanum(NULL), 0);
}

Test(string, string_is_alphanum_w_empty)
{
    cr_assert_eq(string_is_alphanum(""), 0);
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

Test(string, string_is_printable_w_null)
{
    cr_assert_eq(string_is_printable(NULL), 0);
}

Test(string, string_is_printable_w_empty)
{
    cr_assert_eq(string_is_printable(""), 0);
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