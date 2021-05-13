/*
** EPITECH PROJECT, 2021
** builtins.c
** File description:
** builtins.c
*/

#include "../include/minishell1.h"

static int my_builtins_cd_env(char *str, shell_t *shell)
{
    int i = 0;

    if (my_strncmp(str, "cd", 2) == 1)
        return (my_cd(str, shell->env));
    if (my_strncmp(str, "env", 3) == 1 || my_strcmp(str, "setenv") == 1) {
        if (my_strlen(str) > 3) {
            my_putstr_error("Too many arguments\n");
            return (1);
        }
        while (shell->env && shell->env[i] != NULL) {
            my_putstr(shell->env[i]);
            i += 1;
        }
        return (0);
    }
    return (2);
}

int my_builtins(char *str, shell_t *shell)
{
    int return_value = my_builtins_cd_env(str, shell);

    if (return_value != 2)
        return (return_value);
    if (my_strncmp(str, "setenv", 6) == 1)
        return (my_setenv(shell->env, str));
    if (my_strncmp(str, "unsetenv", 8) == 1)
        return (my_unsetenv(shell->env, str));
    if (my_strncmp(str, "exit", 4) == 1) {
        if (str[5] == '-')
            my_atoi(&str[6]) != - 1 ? exit(256 - my_atoi(&str[6])) :
                my_putstr_error("exit: Expression Syntax.\n");
        else
            my_atoi(&str[5]) != - 1 ? exit(my_atoi(&str[5])) :
                my_putstr_error("exit: Expression Syntax.\n");
        return (1);
    }
    return (2);
}