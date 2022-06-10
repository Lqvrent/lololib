#include "internal.h"

const char *error_str(void)
{
    return (errors[current_errorno(-1)]);
}

int error_num(void)
{
    return (current_errorno(-1));
}