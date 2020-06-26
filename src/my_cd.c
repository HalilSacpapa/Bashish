/*
** EPITECH PROJECT, 2019
** my_cd.c
** File description:
** personal cd function using chdir
*/

#include "my.h"

int my_cd(s_minishell *p)
{
    if (my_strcmp(p->arg_tab[0], "cd") == 0 && p->arg_tab[1] == NULL)
        get_home(p);
    else if (p->arg_tab[0][0] == '/') {
        if ((chdir(p->arg_tab[0])) == -1) {;
            perror(p->arg_tab[0]);
            return (1);
        }
    } else {
        if ((chdir(p->arg_tab[1])) == -1) {
            perror(p->arg_tab[1]);
            return (1);
        }
    }
    return (0);
}
