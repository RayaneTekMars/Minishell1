/*
** EPITECH PROJECT, 2021
** cd.c
** File description:
** cd.c
*/

#include "../include/minishell1.h"

void access_to_user(char **env)
{
    char *str_home = NULL;
    int i;

    my_setenv(env, my_strcat("setenv OLDPWD ", getcwd(str_home, 4096)));
    for (i = 0; env != NULL && env[i] != NULL &&
        my_strncmp(env[i], "HOME", 4) != 1; i++);
    if (env == NULL || my_strlen_array(env) == i) {
        my_putstr_error("cd: No home directory.\n");
        return;
    }
    str_home = &env[i][5];
    if (chdir(str_home) == -1)
        my_putstr_error("cd: Can't change to home directory.\n");
}

void perror_handling(char *str)
{
    struct stat sb;

    if (stat(str, &sb) != -1 && S_ISDIR(sb.st_mode)) {
        my_putstr_error(str);
        my_putstr_error(": Permission denied.\n");
        return;
    }
    if (stat(str, &sb) == 0 && !S_ISDIR(sb.st_mode)) {
        my_putstr_error(str);
        my_putstr_error(": Not a directory.\n");
        return;
    }
    my_putstr_error(str);
    my_putstr_error(": No such file or directory.\n");
}

char *my_back_cd(char **env)
{
    int i = 0;

    while (env != NULL && env[i] != NULL) {
        if (my_strncmp(env[i], "OLDPWD", 6) == 1)
            return (&env[i][7]);
        i++;
    }
    return (NULL);
}

int chdir_handling(char **env, char *str, char *str_ret)
{
    char *str_cwd = NULL;

    my_setenv(env, my_strcat("setenv OLDPWD ", getcwd(str_cwd, 4096)));
    if (my_strcmp(&str[3], "-") == 1) {
        if (chdir(str_ret) == -1) {
            perror_handling(str_ret);
            return (1);
        }
    } else {
        if (chdir(&str[3]) == -1) {
            perror_handling(&str[3]);
            return (1);
        }
    }
    free(str_cwd);
    return (0);
}

int my_cd(char *str, char **env)
{
    char *str_getcwd = NULL;
    char *str_ret = NULL;

    str_ret = my_back_cd(env);
    if (my_strlen(str) == 2 || str[3] == '~')
        access_to_user(env);
    else if (my_strlen(str) == 3)
        return (2);
    else
        if (chdir_handling(env, str, str_ret) == 1) {
            my_setenv(env, my_strcat("setenv PWD ",getcwd(str_getcwd, 4096)));
            return (1);
        }
    my_setenv(env, my_strcat("setenv PWD ", getcwd(str_getcwd, 4096)));
    return (0);
}