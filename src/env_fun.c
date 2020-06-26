/*
** EPITECH PROJECT, 2019
** env_fun.c
** File description:
** environnement commands
*/

#include "my.h"

void my_getenv(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        my_putstr(env[i], 1);
        my_putchar('\n');
        i++;
    }
}

int new_env_size(s_minishell *p)
{
    int	size;

    if (p->arg_tab[2] != NULL)
        size = (my_strlen(p->arg_tab[1]) + my_strlen(p->arg_tab[2]));
    else
        size = my_strlen(p->arg_tab[1]);
    return (size);
}

void my_setenv(s_minishell *p, char **env)
{
    int len = getenv_size(env) + 1;
    int i = 0;
    int u = 0;
    int size = (new_env_size(p) + 2);

    env[len] = malloc(sizeof(char) * size + 2);
    for (; p->arg_tab[len][i] != '\0'; i++)
        env[len][i] = p->arg_tab[len][i];
    env[len][i] = '=';
    i++;
    if (p->arg_tab[2] != NULL) {
        for (; p->arg_tab[2][u] != '\0'; u++) {
            env[len][i] = p->arg_tab[2][u];
            i++;
        }
    }
    env[len][i] = '\0';
}

void my_unsetenv(s_minishell *p, char **env)
{
    if (env[1] != p->arg_tab[1])
        return;
    return;
}

int getenv_size(char **env)
{
    int i = 0;

    while (env[i] != NULL)
        i++;
    return (i);
}
