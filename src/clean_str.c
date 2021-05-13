/*
** EPITECH PROJECT, 2021
** clean_str.c
** File description:
** clean_str.c
*/

#include "../include/minishell1.h"

char **cut_str(char **str)
{
    char **av = my_str_to_word_array(*str, ' ');

    if ((*str == NULL) || av == NULL)
        return (NULL);
    free(*str);
    *str = my_strcpy(av[0]);
    return (av);
}

static char *parse(char *str)
{
    int i = 0;

    if (str[0] == '\0')
        return (str);
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;
    if (i == my_strlen(str))
            return (NULL);
    for (int nb = my_strlen(str) - 1; str[nb] == ' '
        || str[nb] == '\t'; nb--)
        str[nb] = '\0';
    return (str);
}

char *clean_str(char *str)
{
    int i = 0;
    int n = 0;
    char *str2 = malloc(sizeof(char) * my_strlen(str) + 1);
    str = parse(str);

    if (str2 == NULL || str == NULL || str == NULL)
        return (NULL);
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    for (i = i; str[i] != '\0'; i++, n++) {
        if (str[i] == ' ' || str[i] == '\t') {
            str2[n] = ' ';
            n++;
            for (; str[i] == ' ' || str[i] == '\t'; i++);
        }
        str2[n] = str[i];
    }
    free(str);
    str2[n] = '\0';
    return (str2);
}
