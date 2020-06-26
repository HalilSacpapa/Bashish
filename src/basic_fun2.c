/*
** EPITECH PROJECT, 2019
** basic_fun2.c
** File description:
** basic functions needed
*/

#include "my.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    int u = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            u++;
        i++;
    }
    if (my_lencmp(s1, s2) == 1 && u == 0)
        u++;
    return (u);
}

int my_lencmp(char *s1, char *s2)
{
    int a = my_strlen(s1);
    int b = my_strlen(s2);

    if (a == b)
        return (0);
    return (1);
}
