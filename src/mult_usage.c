/*
** EPITECH PROJECT, 2019
** mult_usage.c
** File description:
** checking for semicoluns, pipe and redirections
*/

#include "my.h"

int check_semcol(s_minishell *p, int i)
{
    if (my_strlen(p->arg_tab[i]) > 1 || p->arg_tab[i + 1] == NULL)
        return (1);
    if (p->arg_tab[i][0] == ';')
        return (0);
    return (1);
}

int check_pipes(s_minishell *p, int i)
{
    if (my_strlen(p->arg_tab[i]) > 1 || p->arg_tab[i + 1] == NULL)
        return (1);
    if (p->arg_tab[i][0] == '|')
        return (0);
    return (1);
}

void check_mult(s_minishell *p)
{
    int u = 0;

    for (int i = 0; p->arg_tab[i] != NULL; i++) {
        if (p->arg_tab[i][u] == '\0') {
            u = 0;
            i++;
        }
        if (check_semcol(p, i) == 0) {
            p->cmds[p->na] = i;
            p->na++;
        }
        if (check_pipes(p, i) == 0) {
            p->cmds[p->na] = i;
            p->na++;
        }
        u++;
    }
    p->cmds[p->na] = -1;
}
