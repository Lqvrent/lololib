#include <lolo/string.h>
#include <stdio.h>
#include "myenv.h"

int main(int argc, char *argv[], char *env[])
{
    char **envline = NULL;
    char **splitted_values = NULL;

    (void)argc; // to remove the "unused" warning
    (void)argv; // to remove the "unused" warning
    for (int i = 0; env[i]; i++) {
        envline = string_split_by_tok(env[i], "="); // split the line by the "=", to get the key and the value
        if (string_includes(envline[1], ":")) { // if the value contains a ":" (like PATH=/usr/bin:/bin), split it and pretty print it
            splitted_values = string_split_by_tok(envline[1], ":");
            printf("%s:\n", envline[0]); // key
            for (int j = 0; splitted_values[j]; j++) // values
                printf("\t%s\n", splitted_values[j]);
            string_array_free(splitted_values);
            splitted_values = NULL;
        } else { // else, just print the key and the value
            printf("%s:\n\t%s\n", envline[0], envline[1]);
        }
        string_array_free(envline);
        envline = NULL;
    }
    return (0);
}
