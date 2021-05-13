/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** my_putstr
*/

#include "../include/minishell1.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
