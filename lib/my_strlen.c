/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** my_strlen
*/

#include "../include/minishell1.h"

int my_strlen(char *str)
{
    int i;

    for (i = 0; str && str[i]; i++);
    return (i);
}
