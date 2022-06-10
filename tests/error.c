#include <criterion/criterion.h>
#include "error.h"

Test(error, error_str)
{
    cr_assert_str_eq(error_str(), "Success");
}

Test(error, error_num)
{
    cr_assert_eq(error_num(), 0);
}