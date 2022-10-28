/**
 * @file string.h
 * @brief String manipulation functions.
 */

#ifndef __STRING_H__
    #define __STRING_H__

/**
 * @brief Check if a string is empty or NULL.
 *
 * @param str The string to check.
 * @return 1 if the string is empty or NULL, 0 otherwise.
 */
int string_is_empty(const char *str);

/**
 * @brief Check if a string is filled with only alpha characters.
 *
 * @param str The string to check.
 * @return 1 if the string is filled with only alpha characters, 0 otherwise.
 * @warning If the string is empty, the function will return 1.
 */
int string_is_alpha(const char *str);

/**
 * @brief Check if a string is filled with only numeric characters.
 *
 * @param str The string to check.
 * @return 1 if the string is filled with only numeric characters, 0 otherwise.
 * @warning If the string is empty, the function will return 1.
 */
int string_is_numeric(const char *str);

/**
 * @brief Check if a string is filled with only alphanumeric characters. (Spaces not included)
 *
 * @param str The string to check.
 * @return 1 if the string is filled with only alphanumeric characters, 0 otherwise.
 * @warning If the string is empty, the function will return 1.
 */
int string_is_alphanum(const char *str);

/**
 * @brief Check if a string is filled with only alphanumeric characters (spaces included)
 *
 * @param str The string to check.
 * @return 1 if the string is filled with only alphanumeric characters, 0 otherwise.
 * @warning If the string is empty, the function will return 1.
 */
int string_is_printable(const char *str);

/**
 * @brief Uppercase all characters in a string.
 *
 * @param str The string to uppercase.
 */
void string_to_upper(char *str);

/**
 * @brief Lowercase all characters in a string.
 *
 * @param str The string to lowercase.
 */
void string_to_lower(char *str);

/**
 * @brief Capitalize the string passed as parameter.
 *
 * @param str The string to capitalize.
 */
void string_capitalize(char *str);

/**
 * @brief Count characters in a string.
 *
 * @param str The string to count.
 * @return The number of characters in the string.
 */
int string_length(const char *str);

/**
 * @brief Reverse the string passed as parameter.
 *
 * @param str The string to reverse.
 */
void string_reverse(char *str);

/**
 * @brief Check if a string contains a substring.
 *
 * @param str The string to check.
 * @param substr The substring.
 * @return 1 if the string contains the substring, 0 otherwise.
 * @warning If the string or substring is NULL, you'll get a segfault.
 */
int string_includes(const char *str, const char *substr);

/**
 * @brief Check if a string starts with a substring.
 *
 * @param str The string to check.
 * @param substr The substring.
 * @return int 1 if the string starts with the substring, 0 otherwise.
 * @warning If the string or substring is NULL, you'll get a segfault.
 */
int string_starts_with(const char *str, const char *substr);

/**
 * @brief Check if a string ends with a substring.
 *
 * @param str The string to check.
 * @param substr The substring.
 * @return int 1 if the string ends with the substring, 0 otherwise.
 * @warning If the string or substring is NULL, you'll get a segfault.
 */
int string_ends_with(const char *str, const char *substr);

/**
 * @brief Count the number of occurrences of a substring in a string.
 *
 * @param str The string to check.
 * @param substr The substring.
 * @return int The number of occurrences of the substring in the string.
 * @warning If the string or substring is NULL, you'll get a segfault.
 */
int string_count(const char *str, const char *substr);

/**
 * @brief Create a string which is a repetition (n times of a given string.
 *
 * @param str The string to repeat.
 * @param n The number of times to repeat the string.
 * @return char* The newly allocated string.
 * @warning If the number of times is 0 or less, the function will return NULL.
 */
char *string_repeat(const char *str, int n);

/**
 * @brief Extracts a section of a string and returns a newly allocated string.
 *
 * @param str The string to extract from.
 * @param start The index of the first character to extract.
 * @param end The index of the last character to extract.
 * @return char* The newly allocated string.
 * @warning If the string is NULL, or one of the indexes is invalid, you'll get a segfault.
 */
char *string_slice(const char *str, int start, int end);

/**
 * @brief Returns an array of strings populated by splitting the calling string at occurrences of the substring sep
 *
 * @param str The string to split.
 * @param sep The substring to split the string at.
 * @return char** The newly allocated array of strings.
 */
char **string_split(const char *str, const char *sep);

/**
 * @brief Returns an array of string populated by splitting the calling string at occurrences of all the characters in the string delims
 *
 * @param str The string to split.
 * @param delims The characters to split the string at.
 * @return char** The newly allocated array of strings.
 */
char **string_split_by_tok(const char *str, const char *delims);

/**
 * @brief Frees an array of strings.
 *
 * @param array The array of strings to free.
 */
void string_array_free(char **array);

/**
 * @brief Returns a string with all occurrences of the substring old replaced by the substring new.
 *
 * @param str The string to replace in.
 * @param old The substring to replace.
 * @param new The substring to replace with.
 * @return char* The newly allocated string.
 */
char *string_replace(const char *str, const char *old, const char *new);

/**
 * @brief Removes all leading and trailing whitespace characters from the string.
 *
 * @param str The string to trim. (Will remove ' ' and '\t')
 * @return char* The newly allocated string.
 */
char *string_trim(const char *str);

/**
 * @brief Removes all leading whitespace characters from the string. (in the left)
 *
 * @param str The string to trim. (Will remove ' ' and '\t')
 * @return char* The newly allocated string.
 */
char *string_ltrim(const char *str);

/**
 * @brief Removes all trailing whitespace characters from the string. (in the right)
 *
 * @param str The string to trim. (Will remove ' ' and '\t')
 * @return char* The newly allocated string.
 */
char *string_rtrim(const char *str);

#endif /* !__STRING_H__ */
