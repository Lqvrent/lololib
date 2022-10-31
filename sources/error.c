#include "lolo/internal.h"
#include "lolo/error.h"

const char *error_str(void)
{
    return (__errors[__current_errorno(-1)]);
}

int error_num(void)
{
    return (__current_errorno(-1));
}
