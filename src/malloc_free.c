/*
** EPITECH PROJECT, 2019
** malloc_free.c
** File description:
** malloc and free functions
*/

#include "my.h"

void malloc_A(s_minishell *p)
{
    p->s = malloc(sizeof(char) * 151);
    p->path = malloc(sizeof(char) * 501);
    p->c_dir = malloc(sizeof(char) * 101);
    p->exc = malloc(sizeof(char) * 551);
    p->cd_home = malloc(sizeof(char) * 51);
    p->pat = malloc(sizeof(char) * 25);
    p->na = 0;
}

void free_A(s_minishell *p)
{
    free(p->s);
    free(p->arg_tab);
    free(p->path);
    free(p->c_dir);
    free(p->exc);
    free(p->cd_home);
    free(p->pat);
    free(p->cmds);
}

void free_B(s_minishell *p)
{
    free(p->s);
    free(p->path);
    free(p->c_dir);
    free(p->exc);
    free(p->cd_home);
    free(p->pat);
}

void final_free(s_minishell *p, int a)
{
    if (a == 1) {
        for (int i = 0; p->arg_tab[i] != NULL; i++)
            free(p->arg_tab[i]);
        for (int u = 0; p->path_tab[u] != NULL; u++)
            free(p->path_tab[u]);
        free(p->cmds);
    }
    free(p->s);
    free(p->path);
    free(p->c_dir);
    free(p->exc);
    free(p->cd_home);
    free(p->pat);
    free(p->usr_name);
}

void malloc_pathtab(s_minishell *p)
{
    int i = 0;

    p->path_tab = malloc(sizeof(char *) * 15);
    while (i < 15) {
        p->path_tab[i] = malloc(sizeof(char) * 25);
        i++;
    }
}
