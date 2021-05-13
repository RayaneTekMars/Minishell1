/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** my_strcat
*/

#include "../include/minishell1.h"

char *my_strcat(char *str1, char *str2)
{
    char *str_return = malloc(sizeof(char) *
                (my_strlen(str1) + my_strlen(str2) + 1));
    int i;

    if (str_return == NULL)
        return (NULL);
    for (i = 0; str1[i]; i++)
        str_return[i] = str1[i];
    for (int nb = 0; str2[nb]; nb++, i++)
        str_return[i] = str2[nb];
    str_return[my_strlen(str1) + my_strlen(str2)] = '\0';
    return (str_return);
}
