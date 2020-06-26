/*
** EPITECH PROJECT, 2019
** path_dir.c
** File description:
** get current path and dir
*/

#include "my.h"

void access_pathtab(s_minishell *p, char **env)
{
    int i = 0;
    int u = 0;
    int y = 0;
    int x = 0;

    malloc_pathtab(p);
    while (path_check(env, i) != 1)
        i++;
    u = 5;
    while (env[i][u] != '\n' && env[i][u] != '\0') {
        if (env[i][u] == ':') {
            y++;
            x = 0;
            u++;
        }
        p->path_tab[y][x] = env[i][u];
        x++;
        u++;
    }
    p->path_tab[y + 1] = NULL;
}

int path_check(char **env, int i)
{
    if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T') {
        if (env[i][3] == 'H' && env[i][4] == '=')
            return (1);
    }
    return (0);
}

int get_path(s_minishell *p)
{
    int i = 0;
    int u = 0;
    char buf[PATH_SIZ];

    if (getcwd(buf, PATH_SIZ) == NULL)
        return (1);
    while (buf[u] != '\0') {
        p->path[i] = buf[u];
        i++;
	u++;
    }
    p->path[i] = '\0';
    p->path_siz = u - 1;
    return (0);
}

void get_home(s_minishell *p)
{
    int i = 1;

    get_path(p);
    p->cd_home[0] = '/';
    while (p->path[i] != '/') {
        p->cd_home[i] = p->path[i];
        i++;
    }
    p->cd_home[i] = '/';
    i++;
    while (p->path[i] != '/') {
        p->cd_home[i] = p->path[i];
        i++;
    }
    chdir(p->cd_home);
}

void getc_dir(s_minishell *p)
{
    int i = 0;
    int u = 0;

    get_path(p);
    while (p->path[i] != '\0') {
        i++;
        u++;
        if (p->path[i] == '/' && p->path[i + 1] != '\0') {
            i++;
            u = 0;
        } else {
            i = i - u;
            while (p->path[i] != '/')
                p->c_dir[u] = p->path[i];
        }
    }
}
