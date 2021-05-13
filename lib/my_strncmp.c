/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** my_strncmp
*/

#include "../include/minishell1.h"

int my_strncmp(char const *str1, char const *str2, unsigned int len)
{
    unsigned int i = 0;

    if (str1 == NULL || str2 == NULL)
        return (0);
    for (; str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0'; i++);
    if (i == len)
        return (1);
    return (0);
}
