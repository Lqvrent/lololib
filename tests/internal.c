#include <criterion/criterion.h>
#include "internal.h"

Test(internal, current_errorno_get)
{
    cr_assert_eq(current_errorno(-1), 0);
}

Test(internal, current_errorno_set)
{
    cr_assert_eq(current_errorno(0), 0);
}
