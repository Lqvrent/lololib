#include <criterion/criterion.h>
#include "../includes/lolo/internal.h"

Test(internal, current_errorno_get)
{
    cr_assert_eq(current_errorno(-1), 0);
}

Test(internal, current_errorno_set)
{
    cr_assert_eq(current_errorno(0), 0);
}

Test(internal, current_errorno_set_max)
{
    cr_assert_eq(current_errorno(ERRORS_COUNT - 1), ERRORS_COUNT - 1);
}

Test(internal, current_errorno_set_over)
{
    current_errorno(0);
    cr_assert_eq(current_errorno(ERRORS_COUNT), 0);
}
