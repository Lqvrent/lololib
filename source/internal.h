/**
 * @file internal.h
 * @brief Internal data and functions so the end-user don't break the library and cause.. Segfaults maybe?
 */

#ifndef __INTERNAL_H__
    #define __INTERNAL_H__
    #define ERRORS_COUNT 1
    #ifndef NULL
        #define NULL (void *)0
    #endif /* !NULL */

static const char *errors[ERRORS_COUNT] = {
    "Success"
};

int current_errorno(int new_errorno);

#endif /* !__INTERNAL_H__ */
