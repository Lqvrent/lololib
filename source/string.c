#include "string.h"

int string_is_empty(const string_t str)
{
    return (!str || !*str);
}

int string_is_alpha(const string_t str)
{
    int i = 0;

    if (string_is_empty(str))
        return (0);
    while (str[i] != 0) {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return (0);
        i++;
    }
    return (1);
}

int string_is_numeric(const string_t str)
{
    int i = 0;

    if (string_is_empty(str))
        return (0);
    while (str[i] != 0) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int string_is_alphanum(const string_t str)
{
    int i = 0;

    if (string_is_empty(str))
        return (0);
    while (str[i] != 0) {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return (0);
        i++;
    }
    return (1);
}

int string_is_printable(const string_t str)
{
        int i = 0;

    if (string_is_empty(str))
        return (0);
    while (str[i] != 0) {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9') && str[i] != ' ')
            return (0);
        i++;
    }
    return (1);
}

void string_to_upper(string_t str)
{
    int i = 0;

    if (string_is_empty(str))
        return ;
    while (str[i] != 0) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
}

void string_to_lower(string_t str)
{
    int i = 0;

    if (string_is_empty(str))
        return ;
    while (str[i] != 0) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
}

void string_capitalize(string_t str)
{
    int i = 0;

    if (string_is_empty(str))
        return ;
    while (str[i] != 0) {
        if ((i == 0 || str[i - 1] == ' ') && str[i] >= 'a' && str[i] <= 'z')
            str[i] += 32;
        i++;
    }
    str[0] -= 32;
}

int string_length(const string_t str)
{
    int i = 0;

    if (string_is_empty(str))
        return (0);
    while (str[i] != 0)
        i++;
    return (i);
}

void string_reverse(string_t str)
{
    int i = 0;
    int j = string_length(str) - 1;
    char tmp;

    if (string_is_empty(str))
        return ;
    while (i < j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
}

int string_includes(const string_t str, const string_t substr)
{
    int i = 0;
    int j = 0;

    if (string_is_empty(str) || string_is_empty(substr))
        return (0);
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

int string_starts_with(const string_t str, const string_t substr)
{
    int i = 0;

    if (string_is_empty(str) || string_is_empty(substr))
        return (0);
    while (substr[i] != 0) {
        if (str[i] == 0)
            return (0);
        if (str[i] != substr[i])
            return (0);
        i++;
    }
    return (1);
}

int string_ends_with(const string_t str, const string_t substr)
{
    int i = 0;
    int j = 0;

    if (string_is_empty(str) || string_is_empty(substr))
        return (0);
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