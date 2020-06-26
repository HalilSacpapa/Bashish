/*
** EPITECH PROJECT, 2019
** basic_fun.c
** File description:
** basics functions needed
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

void my_putstr(char *str, int i)
{
    write(i, str, my_strlen(str));
}

void my_putnbr(int nb)
{
    if (nb > 9)
        my_putnbr(nb / 10);
    my_putchar(nb % 10 + '0');
}

int my_getnbr(char *str)
{
    int i = 0;
    int u = 0;
    int y = 0;

    while (str[y] == '-')
        y++;
    i = i + y;
    while (str[i] > 47 && str[i] < 58) {
        u = u * 10 + (str[i] % 48);
        i++;
    }
    if (y % 2 == 1)
        u = u * -1;
    return (u);
}
