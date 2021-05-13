/*
** EPITECH PROJECT, 2021
** minishell1.h
** File description:
** minishell1.h
*/

#ifndef MINISHELL1_H_
#define MINISHELL1_H_

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdarg.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

typedef struct shell
{
    char **env;
    char *str_path;
    int is_symbol;
} shell_t;

#define READ_SIZE   4096

/* MY_LIB */

void my_putstr(char *str);
int my_strlen(char *str);

/* MINISHELL */

char *get_next_line(int fd);
char *clean_str(char *str);
char **cut_str(char **str);
int my_exec(char *str, char **av, shell_t *shell);
int my_builtins(char *str, shell_t *shell);
int my_cd(char *str, char **env);
int my_setenv(char **env, char *str);
int my_unsetenv(char **env, char *str);
int command(char *str, shell_t *shell);
int error_directory(char *str);
int error_directory_without_error(char *str);
int segfault_error(int status);
int is_a_slash(char *str);
int my_access(char *str, shell_t *shell);

#endif /* !MINISHELL1_H_ */