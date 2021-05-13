/*
** EPITECH PROJECT, 2021
** unsetenv.c
** File description:
** unsetenv.c
*/

#include "../include/minishell1.h"

static void remove_line(char **env, int line)
{
    for (; env[line + 1] != NULL; line++)
        env[line] = my_strcpy(env[line + 1]);
    env[line] = NULL;
}

int my_unsetenv(char **env, char *str)
{
    char **array_remove = my_str_to_word_array(str, ' ');
    char *str_equal = NULL;
    int n;

    if (my_strlen_array(array_remove) == 1) {
        my_putstr_error("unsetenv: Too few arguments.\n");
        my_free_array(array_remove);
        return (1);
    }
    for (int nb = 1; array_remove[nb] != NULL; nb++)
        for (int i = 0; env[i] != NULL; i++) {
            str_equal = malloc(sizeof(char) * my_strlen(env[i]));
            for (n = 0; env[i][n] != '='; n++)
                str_equal[n] = env[i][n];
            str_equal[n] = '\0';
            if (my_strcmp(array_remove[nb], str_equal) == 1)
                remove_line(env, i);
            free(str_equal);
        }
    my_free_array(array_remove);
    return (1);
}