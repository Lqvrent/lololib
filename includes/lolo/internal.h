/**
 * @file internal.h
 * @brief Internal data and functions so the end-user don't break the library and cause.. Segfaults maybe?
 */

#ifndef __INTERNAL_H__
    #define __INTERNAL_H__
    /**
     * @brief Number of error messages. (Used to check if the errorno is valid & allocate the error messages array)
     */
    #define __ERRORS_COUNT 1
    #ifndef NULL
        /**
         * @brief Represents a null pointer.
         */
        #define NULL (void *)0
    #endif /* !NULL */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
static const char *__errors[__ERRORS_COUNT] = {
    "Success"
};
#pragma GCC diagnostic pop

/**
 * @brief Get/set the error number in order to get the error message.
 * @param new_errorno The error code. (The code will NOT will modified if errno < 0 or errno > __ERRORS_COUNT)
 * @return int The error code.
 */
int __current_errorno(int new_errorno);

#endif /* !__INTERNAL_H__ */
