/*
** EPITECH PROJECT, 2021
** my_putstr_error.c
** File description:
** my_putstr_error.c
*/

#include "../include/minishell1.h"

int my_putstr_error(char const *str)
{
    write (2, str, my_strlen(str));
    return (84);
}