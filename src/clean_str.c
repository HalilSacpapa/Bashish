/*
** EPITECH PROJECT, 2019
** clean_str.c
** File description:
** clean string given as argument
*/

#include "my.h"

int count_tab(s_minishell *p)
{
    int i = 0;
    int u = 0;

    while (p->s[i]) {
        if (p->s[i] == '\t')
            u++;
        i++;
    }
    return (u);
}

char *clean_mtab(s_minishell *p)
{
    int len = count_tab(p);
    int size = my_strlen(p->s) - len;
    int i = 0;
    int u = 0;
    char *str = malloc(sizeof(char) * size + 2);

    while (p->s[i]) {
        if (p->s[i] != '\t') {
            str[u] = p->s[i];
            u++;
        }
        i++;
    }
    str[u] = '\0';
    return (str);
}

int count_mspace(s_minishell *p)
{
    int i = 0;
    int u = 0;

    while (p->s[i]) {
        if (p->s[i] == ' ' && p->s[i + 1] == ' ')
            u++;
        i++;
    }
    return (u);
}

char *clean_mspace(s_minishell *p)
{
    int len = count_mspace(p);
    int size = my_strlen(p->s) - len;
    int i = 0;
    int u = 0;
    char *str = malloc(sizeof(char) * size + 2);

    while (p->s[i]) {
        if (p->s[i] == ' ' && p->s[i + 1] == ' ')
            i++;
        else if (p->s[i] == ' ' && p->s[i + 1] == '\0')
            i++;
        else {
            str[u] = p->s[i];
            u++;
            i++;
        }
    }
    str[u] = '\0';
    free(p->s);
    p->s = malloc(sizeof(char) * 151);
    return (str);
}

char *clean_fspace(s_minishell *p)
{
    int u = 0;
    int i = 0;
    char *str = malloc(sizeof(char) * 151);

    while (p->s[i] == ' ')
        i++;
    while (p->s[i] != '\0') {
        str[u] = p->s[i];
        i++;
        u++;
    }
    return (str);
}
