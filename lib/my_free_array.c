/*
** EPITECH PROJECT, 2021
** my_free_array.c
** File description:
** my_free_array.c
*/

#include "../include/minishell1.h"

void my_free_array(char **array)
{
    for (int i = 0; array && array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
