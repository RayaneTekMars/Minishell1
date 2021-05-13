/*
** EPITECH PROJECT, 2021
** error_exec.c
** File description:
** error_exec.c
*/

#include "../include/minishell1.h"

int is_a_slash(char *str)
{
    int i;

    for (i = 0; str[i] != '\0' && str[i] != '/'; i++);
    if (i != my_strlen(str))
        return (0);
    return (1);
}

int error_directory_without_error(char *str)
{
    struct stat sb;

    if (stat(str, &sb) == -1 || S_ISDIR(sb.st_mode))
        return (1);
    return (0);
}

int error_directory(char *str)
{
    struct stat sb;

    if (stat(str, &sb) == -1 || S_ISDIR(sb.st_mode)) {
        my_putstr_error(str);
        my_putstr_error(": Permission denied.\n");
        return (1);
    }
    return (0);
}

int segfault_error(int status)
{
    if (WIFSIGNALED(status) == 1) {
        if (status == SIGFPE || status - 128 == SIGFPE)
            my_putstr_error("Floating exception");
        if (WTERMSIG(status) == 11)
            my_putstr_error("Segmentation fault");
        if (WCOREDUMP(status))
            my_putstr_error(" (core dumped)\n");
        else
            my_putchar('\n');
    }
    return (status);
}
