#include "lolo/internal.h"

int __current_errorno(int new_errorno)
{
    static int current = 0;

    if (new_errorno >= 0 && new_errorno < __ERRORS_COUNT)
        current = new_errorno;
    return (current);
}
