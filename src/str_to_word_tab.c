/*
** EPITECH PROJECT, 2019
** str_to_word_tab.c
** File description:
** turn a string into a word table
*/

#include "my.h"

int len_size(s_minishell *p)
{
    int i = 0;
    int u = 0;

    while (p->s[i]) {
        if ((p->s[i] == ' ' && p->s[i + 1] != ' ') || p->s[i + 1] == '\0') {
            u++;
            i++;
        }
        i++;
    }
    if (u != 0)
        u++;
    return (u);
}

void malloc_tab(s_minishell *p, int len)
{
    int i = 0;

    p->arg_tab = malloc(sizeof(char *) * (len + 2));
    while (i != (len + 2)) {
        p->arg_tab[i] = malloc(sizeof(char) * 21);
        i++;
    }
    p->cmds = malloc(sizeof(int) * (len + 2));
}

void str_tab(s_minishell *p, int i, int t, int u)
{
    int len = len_size(p);

    malloc_tab(p, len);
    while (p->s[i]) {
        while (p->s[i] != ' ' && p->s[i] != '\0') {
            p->arg_tab[t][u] = p->s[i];
            i++;
            u++;
        }
        p->cmds[t] = (t + 1);
        if (p->s[i] == ' ' && p->s[i + 1] != ' ') {
            p->arg_tab[t][u] = '\0';
            t++;
            u = 0;
            i++;
        }
    }
    t++;
    p->arg_tab[t] = NULL;
}
