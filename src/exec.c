/*
** EPITECH PROJECT, 2021
** exec.c
** File description:
** exec.c
*/

#include "../include/minishell1.h"

int my_fork(char *str, char **av, char **env)
{
    int status = 0;
    pid_t cpid = fork();
    int return_value;

    if (cpid == -1) {
        perror("fork");
        return (84);
    }
    if (cpid == 0) {
        signal(SIGINT, SIG_DFL);
        if (execve(str, av, env) == -1)
            return (my_putstr_error("execve : error\n"));
    } else {
        if (waitpid(0, &status, WCONTINUED) == -1)
            return (status);
        if ((return_value = segfault_error(status)) != 0)
            return (return_value);
    }
    free(str);
    return (0);
}

int my_exec(char *str, char **av, shell_t *shell)
{
    int return_value = my_access(str, shell);

    if (access(str, X_OK) == 0 && is_a_slash(str) == 0) {
        if (error_directory(str) == 1 && my_access(str, shell) != -2)
            return (1);
        return (my_fork(str, av, shell->env));
    }
    if (shell->env == NULL || return_value == 84)
        return (84);
    if (return_value == -2 || str == NULL || str[0] == '\0')
        return (0);
    if (return_value == -1 || str[0] == '.' || str[0] == '/') {
        my_putstr_error(str);
        my_putstr_error(": Command not found.\n");
        return (1);
    }
    return (my_fork(shell->str_path, av, shell->env));
}