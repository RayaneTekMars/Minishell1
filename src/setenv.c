/*
** EPITECH PROJECT, 2021
** setenv.c
** File description:
** setenv.c
*/

#include "../include/minishell1.h"

static char *fill_str_insert(char **array)
{
    int i;
    int len = my_strlen(array[1]) + 1;
    char *str = NULL;

    if (my_strlen_array(array) == 3)
        len += my_strlen(array[2]);
    if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
        return (NULL);
    for (i = 0; array[1][i] != '\0'; i++)
        str[i] = array[1][i];
    str[i] = '=';
    if (my_strlen_array(array) == 2) {
        str[len] = '\0';
        return (str);
    }
    i++;
    for (int nb = 0; array[2][nb] != '\0'; nb++, i++)
        str[i] = array[2][nb];
    str[i] = '\0';
    return (str);
}

static int env_exist(char **array, char **env)
{
    char *str_to_insert = NULL;

    for (int i = 0; env[i] != NULL; i++)
        if (my_strncmp(array[1], env[i], my_strlen(array[1])) == 1) {
            str_to_insert = fill_str_insert(array);
            env[i] = my_strcpy(str_to_insert);
            free(str_to_insert);
            return (1);
        }
    return (0);
}

static int parse_str(char *str)
{
    int i;

    for (i = 0; str && str[i] != ' ' && str[i] != '\0'; i++);
    i++;
    if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) {
        my_putstr_error("setenv: Variable name must "
                "begin with a letter.\n");
        return (1);
    }
    for (; str && str[i] != '\0' && str[i] != ' '; i++)
        if ((str[i] < '0' || str[i] > '9') && (str[i] < 'a'
            || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) {
            my_putstr_error("setenv: Variable name must contain "
                    "alphanumeric characters.\n");
            return (1);
        }
    return (0);
}

int my_setenv(char **env, char *str)
{
    char **array_insert = my_str_to_word_array(str, ' ');
    char *str_to_insert = NULL;
    int len_env = my_strlen_array(env);

    if (parse_str(str) == 1)
        return (1);
    if (my_strlen_array(array_insert) > 3) {
        my_putstr_error("setenv: Too many arguments.\n");
        my_free_array(array_insert);
        return (1);
    }
    if (env_exist(array_insert, env) == 0) {
        str_to_insert = fill_str_insert(array_insert);
        env[len_env] = my_strcpy(str_to_insert);
        env[len_env + 1] = NULL;
        free(str_to_insert);
    }
    my_free_array(array_insert);
    return (1);
}
