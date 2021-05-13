/*
** EPITECH PROJECT, 2021
** my_putnbr
** File description:
** my_putnbr
*/

#include "../include/minishell1.h"

void my_putnbr(int nb)
{
    int start;
    int end;

    if (nb < 0) {
        my_putchar('-');
        my_putnbr(-nb);
    } else {
        end = nb % 10;
        start = nb / 10;
        if (start != 0)
            my_putnbr(start);
        my_putchar(end + '0');
    }
}
