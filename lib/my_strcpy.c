/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** my_strcpy.c
*/

#include "../include/minishell1.h"

char *my_strcpy(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}