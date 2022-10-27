/**
 * @file error.h
 * @brief Functions to handle errors occured while using the lololib.
 */

#ifndef __ERROR_H__
    #define __ERROR_H__

/**
 * @brief Gives you the error message corresponding to the last error occured.
 *
 * @return A string containing the error message ("Success" if no error occured).
 */
const char *error_str(void);

/**
 * @brief Gives you the error number corresponding to the last error occured.
 *
 * @return The error number (0 if no error occured)
 */
int error_num(void);

#endif /* !__ERROR_H__ */
