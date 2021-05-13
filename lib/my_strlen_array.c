/*
** EPITECH PROJECT, 2021
** my_strlen_array
** File description:
** my_strlen_array
*/

#include "../include/minishell1.h"

int my_strlen_array(char **str)
{
    int i;

    for (i = 0; str[i] != NULL; i++);
    return (i);
}
