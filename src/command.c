/*
** EPITECH PROJECT, 2021
** command.c
** File description:
** command.c
*/

#include "../include/minishell1.h"

static char *a_pipe(char *str, int *len)
{
    char *return_str = NULL;
    int n_malloc;
    int len_space = (*len);

    for (n_malloc = (*len); str[n_malloc] != ';'; n_malloc++);
    if (n_malloc != 0 && str[n_malloc - 1] == ' ')
        n_malloc--;
    return_str = malloc(sizeof(char) * (n_malloc - (*len) + 1));
    for (int nb = 0; str[(*len)] != ';'; (*len)++, nb++)
        return_str[nb] = str[(*len)];
    return_str[n_malloc - len_space] = '\0';
    if (str[(*len)] == ' ')
        (*len)++;
    (*len)++;
    if (str[(*len)] != '\0' && str[(*len)] == ' ')
        (*len)++;
    return (return_str);
}

static char *not_a_pipe(char *str, int *i, int *len, int *is_symbol)
{
    char *return_str = NULL;
    int n_malloc;

    if ((*len) == 0) {
        *is_symbol = 1;
        (*i) = 0;
        return (str);
    }
    for (n_malloc = (*len); str[n_malloc] != '\0'; n_malloc++);
    return_str = malloc(sizeof(char) * (n_malloc - (*len) + 1));
    return_str[n_malloc - (*len)] = '\0';
    for (int nb = 0; str[(*len)] != '\0'; (*len)++, nb++)
        return_str[nb] = str[(*len)];
    *is_symbol = 1;
    (*len) = 0;
    (*i) = 0;
    return (return_str);
}

static char *is_a_pipe(char *str, int *is_symbol)
{
    static int len = 0;
    static int i = 0;
    int len_str = 0;

    for (;str[i] != '\0' && str[i] != ';'; i++);
    for (len_str = i; str[len_str] != '\0'; len_str++);
    if (i != len_str) {
        i++;
        return (a_pipe(str, &len));
    }
    i++;
    return (not_a_pipe(str, &i, &len, is_symbol));
}

int command(char *str_start, shell_t *shell)
{
    char **av = NULL;
    int return_value = 0;
    char *s_cut = NULL;
    char *str = NULL;

    if (str_start == NULL || str_start[0] == '\n' || str_start[0] == '\0')
        return (0);
    if ((str = clean_str(str_start)) != NULL)
        while (shell->is_symbol != 1) {
            s_cut = is_a_pipe(str, &shell->is_symbol);
            if (s_cut && s_cut[0] != '\0' &&
                (return_value = my_builtins(s_cut, shell)) != 2)
                break;
            av = cut_str(&s_cut);
            return_value = my_exec(s_cut, av, shell);
            my_free_array(av);
        }
    shell->is_symbol = 0;
    return (return_value);
}