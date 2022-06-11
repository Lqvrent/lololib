/**
 * @file string.h
 * @brief String manipulation functions.
 */

#ifndef __STRING_H__
    #define __STRING_H__

/**
 * @brief Just for fun.
 */
typedef char *string_t;

/**
 * @brief Check if a string is empty or NULL.
 *
 * @param str The string to check.
 * @return 1 if the string is empty or NULL, 0 otherwise.
 */
int string_is_empty(const string_t str);

/**
 * @brief Check if a string is filled with only alpha characters.
 *
 * @param str The string to check.
 * @return 1 if the string is filled with only alpha characters, 0 otherwise.
 * @warning If the string is NULL, you'll get a segfault.
 * @warning If the string is empty, the function will return 1.
 */
int string_is_alpha(const string_t str);

/**
 * @brief Check if a string is filled with only numeric characters.
 *
 * @param str The string to check.
 * @return 1 if the string is filled with only numeric characters, 0 otherwise.
 * @warning If the string is NULL, you'll get a segfault.
 * @warning If the string is empty, the function will return 1.
 */
int string_is_numeric(const string_t str);

/**
 * @brief Check if a string is filled with only alphanumeric characters. (Spaces not included)
 *
 * @param str The string to check.
 * @return 1 if the string is filled with only alphanumeric characters, 0 otherwise.
 * @warning If the string is NULL, you'll get a segfault.
 * @warning If the string is empty, the function will return 1.
 */
int string_is_alphanum(const string_t str);

/**
 * @brief Check if a string is filled with only alphanumeric characters (spaces included)
 *
 * @param str The string to check.
 * @return 1 if the string is filled with only alphanumeric characters, 0 otherwise.
 * @warning If the string is NULL, you'll get a segfault.
 * @warning If the string is empty, the function will return 1.
 */
int string_is_printable(const string_t str);

/**
 * @brief Uppercase all characters in a string.
 *
 * @param str The string to uppercase.
 * @warning If the string is NULL, you'll get a segfault.
 */
void string_to_upper(string_t str);

/**
 * @brief Lowercase all characters in a string.
 *
 * @param str The string to lowercase.
 * @warning If the string is NULL, you'll get a segfault.
 */
void string_to_lower(string_t str);

/**
 * @brief Capitalize the string passed as parameter.
 *
 * @param str The string to capitalize.
 * @warning If the string is NULL, you'll get a segfault.
 */
void string_capitalize(string_t str);

/**
 * @brief Count characters in a string.
 *
 * @param str The string to count.
 * @return The number of characters in the string.
 * @warning If the string is NULL, you'll get a segfault.
 */
int string_length(const string_t str);

/**
 * @brief Reverse the string passed as parameter.
 *
 * @param str The string to reverse.
 * @warning If the string is NULL, you'll get a segfault.
 */
void string_reverse(string_t str);

/**
 * @brief Check if a string contains a substring.
 *
 * @param str The string to check.
 * @param sub The substring.
 * @return 1 if the string contains the substring, 0 otherwise.
 * @warning If the string or substring is NULL, you'll get a segfault.
 */
int string_includes(const string_t str, const string_t substr);

/**
 * @brief Check if a string starts with a substring.
 *
 * @param str The string to check.
 * @param substr The substring.
 * @return int 1 if the string starts with the substring, 0 otherwise.
 * @warning If the string or substring is NULL, you'll get a segfault.
 */
int string_starts_with(const string_t str, const string_t substr);

/**
 * @brief Check if a string ends with a substring.
 *
 * @param str The string to check.
 * @param substr The substring.
 * @return int 1 if the string ends with the substring, 0 otherwise.
 * @warning If the string or substring is NULL, you'll get a segfault.
 */
int string_ends_with(const string_t str, const string_t substr);

#endif /* !__STRING_H__ */
