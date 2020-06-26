/*
** EPITECH PROJECT, 2019
** path_cmd.c
** File description:
** check the path by using access and cmd not found
*/

#include "my.h"

int path_cmd(s_minishell *p, int i, int u, int y)
{
    while (my_lencmp(p->pat, p->path_tab[i]) != 0) {
        p->pat[u] = p->path_tab[i][u];
        u++;
    }
    u = my_strlen(p->path_tab[i]);
    p->pat[u] = '/';
    u++;
    while (p->arg_tab[0][y] != ' ' && y <= my_strlen(p->arg_tab[0])) {
        p->pat[u] = p->arg_tab[0][y];
        u++;
        y++;
    }
    if (access(p->pat, F_OK) == 0)
        return (1);
    else {
        free(p->pat);
        p->pat = malloc(sizeof(char) * 25);
    }
    return (0);
}

void cmd_notfd(s_minishell *p)
{
    my_putstr(p->arg_tab[0], 1);
    my_putstr(": Command not found.\n", 1);
}
