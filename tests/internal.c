#include <criterion/criterion.h>
#include "../includes/lolo/internal.h"

Test(internal, __current_errorno_get)
{
    cr_assert_eq(__current_errorno(-1), 0);
}

Test(internal, __current_errorno_set)
{
    cr_assert_eq(__current_errorno(0), 0);
}

Test(internal, __current_errorno_set_max)
{
    cr_assert_eq(__current_errorno(__ERRORS_COUNT - 1), __ERRORS_COUNT - 1);
}

Test(internal, __current_errorno_set_over)
{
    __current_errorno(0);
    cr_assert_eq(__current_errorno(__ERRORS_COUNT), 0);
}
