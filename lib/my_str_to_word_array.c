/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "../include/minishell1.h"

static int ct(char const *str, char symbol)
{
    static int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        i++;
        nb++;
        if (str[i] == symbol)
            return (nb);
    }
    i = 0;
    return (nb);
}

static char **malloc_it(char const *str, char symbol)
{
    int len_columns = 0;
    char **array_result;
    int i = 0;
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == symbol)
            len_columns++;
    len_columns++;
    array_result = malloc(sizeof(char *) * (len_columns + 1));
    array_result[len_columns] = NULL;
    for (; len_columns != 0; len_columns--, nb++) {
        i = ct(str, symbol);
        array_result[nb] = malloc(sizeof(char) * (i + 1));
        array_result[nb][i] = '\0';
    }
    return (array_result);
}

char **my_str_to_word_array(char const *str, char symbol)
{
    char **array_result = malloc_it(str, symbol);
    int nb = 0;
    int n = 0;
    int a = 0;

    if (array_result == NULL || (str && str[0] == '\0'))
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++, nb++) {
        if (str[i] == symbol) {
            array_result[n][nb] = '\0';
            n++;
            i++;
            nb = 0;
        }
        array_result[n][nb] = str[i];
        a = nb;
    }
    array_result[n][++a] = '\0';
    array_result[++n] = NULL;
    return (array_result);
}
