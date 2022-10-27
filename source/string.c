#include "string.h"
#include <stdlib.h>

int string_is_empty(const char *str)
{
    return (!str || !*str);
}

int string_is_alpha(const char *str)
{
    int i = 0;

    while (str[i] != 0) {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return (0);
        i++;
    }
    return (1);
}

int string_is_numeric(const char *str)
{
    int i = 0;

    while (str[i] != 0) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int string_is_alphanum(const char *str)
{
    int i = 0;

    while (str[i] != 0) {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return (0);
        i++;
    }
    return (1);
}

int string_is_printable(const char *str)
{
        int i = 0;

    while (str[i] != 0) {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9') && str[i] != ' ')
            return (0);
        i++;
    }
    return (1);
}

void string_to_upper(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
}

void string_to_lower(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
}

void string_capitalize(char *str)
{
    int i = 0;
    int tmp = 0;

    while (str[i] != 0) {
        tmp = string_is_alphanum((char[2]){str[i - 1], 0});
        if ((i == 0 || !tmp) && str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        if ((i > 0 && tmp) && str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
}

int string_length(const char *str)
{
    int i = 0;

    while (str[i] != 0)
        i++;
    return (i);
}

void string_reverse(char *str)
{
    int i = 0;
    int j = string_length(str) - 1;
    char tmp;

    while (i < j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
}

int string_includes(const char *str, const char *substr)
{
    int i = 0;
    int j = 0;

    while (str[i] != 0) {
        if (str[i] == substr[j]) {
            j++;
            if (substr[j] == 0)
                return (1);
        } else
            j = 0;
        i++;
    }
    return (0);
}

int string_starts_with(const char *str, const char *substr)
{
    int i = 0;

    while (substr[i] != 0) {
        if (str[i] == 0)
            return (0);
        if (str[i] != substr[i])
            return (0);
        i++;
    }
    return (1);
}

int string_ends_with(const char *str, const char *substr)
{
    int i = 0;
    int j = 0;

    while (str[i] != 0) {
        if (str[i] == substr[j]) {
            j++;
            if (substr[j] == 0 && str[i + 1] == 0)
                return (1);
        } else
            j = 0;
        i++;
    }
    return (0);
}

int string_count(const char *str, const char *substr)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while (str[i] != 0) {
        if (str[i] == substr[j]) {
            j++;
            if (substr[j] == 0)
                count++;
        } else
            j = 0;
        i++;
    }
    return (count);
}

char *string_repeat(const char *str, int n)
{
    int i = 0;
    int j = 0;
    char *new = NULL;

    if (n <= 0)
        return (NULL);
    new = malloc(sizeof(char) * ((string_length(str) * n) + 1));
    while (j < (string_length(str) * n)) {
        new[j] = str[i];
        j++;
        i++;
        if (i == string_length(str))
            i = 0;
    }
    new[j] = 0;
    return (new);
}

char *string_slice(const char *str, int start, int end)
{
    int i = 0;
    char *new = NULL;

    new = malloc(sizeof(char) * (end - start + 2));
    while (i < end - start) {
        new[i] = str[start + i];
        i++;
    }
    new[i] = 0;
    return (new);
}

int __string_split_count_words(const char *str, const char *sep) // util function to allocate our array while splitting
{
    int i = 0;
    int j = 0;
    int count = 0;
    int in_a_row = 0;

    while (str[i] != 0) {
        if (string_starts_with(str + i, sep)) {
            if (!in_a_row)
                count++;
            in_a_row = 1;
            i += string_length(sep);
        } else {
            in_a_row = 0;
            i++;
        }
    }
    if (!in_a_row)
        count++;
    return (count);
}

char **string_split(const char *str, const char *sep)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int in_a_row = string_starts_with(str, sep);
    char **array = malloc(sizeof(char *) * (__string_split_count_words(str, sep) + 1));

    while (str[i] != 0) {
        if (string_starts_with(str + i, sep)) {
            if (!in_a_row) {
                array[j] = malloc(sizeof(char) * (i - k + 1));
                array[j] = string_slice(str, k, i);
                j++;
            }
            in_a_row = 1;
            i += string_length(sep);
            k = i;
        } else {
            in_a_row = 0;
            i++;
        }
    }
    if (!in_a_row) {
        array[j] = malloc(sizeof(char) * (i - k + 1));
        array[j] = string_slice(str, k, i);
        j++;
    }
    array[j] = NULL;
    return (array);
}

void string_array_free(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        free(array[i]);
        i++;
    }
    free(array);

}
