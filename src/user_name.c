/*
** EPITECH PROJECT, 2019
** user_name.c
** File description:
** check user name in the env
*/

#include "my.h"

int check_name(char **env, int l)
{
    if (env[l][3] == 'N' && env[l][4] == 'A' && env[l][5] == 'M') {
        if (env[l][6] == 'E' && env[l][7] == '=')
            return (1);
    }
    return (0);
}

void cpy_name(s_minishell *p, char **env, int l, int i)
{
    int u = 0;

    while (i < my_strlen(env[l])) {
        p->usr_name[u] = env[l][i];
        u++;
        i++;
    }
    p->usr_name[u] = '\0';
    p->user_once = 1;
}

void usr_name(s_minishell *p, char **env)
{
    int i = 8;
    int l = 0;
    int check = 0;

    if (p->user_once > 0)
        return;
    p->usr_name = malloc(sizeof(char) * 42);
    while (check == 0 && env[l] != NULL) {
        if (env[l][0] == 'L' && env[l][1] == 'O' && env[l][2] == 'G')
            check = check_name(env, l);
        l++;
    }
    if (env[l] == NULL)
        return;
    l--;
    cpy_name(p, env, l, i);
}
