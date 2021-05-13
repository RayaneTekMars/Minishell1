/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** my_strcmp
*/

#include "../include/minishell1.h"

int my_strcmp(char const *str1, char const *str2)
{
    int i;

    for (i = 0; str1 && str1[i] != '\0' && str1[i] == str2[i]; i++);
    if (i == my_strlen(str1) && my_strlen(str1) == my_strlen(str2))
        return (1);
    return (0);
}
