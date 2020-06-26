/*
** EPITECH PROJECT, 2019
** check_fun.c
** File description:
** check functions entred
*/

#include "my.h"

void check_fun(s_minishell *p, char **env)
{
    if (my_strcmp(p->arg_tab[0], "exit") == 0) {
        final_free(p, 1);
	exit(0);
    } else if (my_strcmp(p->arg_tab[0], "pwd") == 0) {
        get_path(p);
        my_putstr(p->path, 1);
        my_putchar('\n');
        return;
    } else {
        check_fun2(p, env);
        return;
    }
}

void check_fun2(s_minishell *p, char **env)
{
    if (my_strcmp(p->arg_tab[0], "cd") == 0 || p->arg_tab[0][0] == '/') {
        my_cd(p);
        return;
    } else if (my_strcmp(p->arg_tab[0], "env") == 0) {
        my_getenv(env);
        return;
    } else {
        check_fun4(p, env);
        return;
    }
}

void check_fun3(s_minishell *p, char **env)
{
    if (my_strcmp(p->arg_tab[0], "setenv") == 0) {
        if (p->arg_tab[1] != NULL)
            my_setenv(p, env);
        else
            my_putstr("setenv: need at least one argument.\n", 1);
        return;
    } else if (my_strcmp(p->arg_tab[0], "unsetenv") == 0) {
        if (p->arg_tab[1] != NULL)
            my_unsetenv(p, env);
        else
            my_putstr("unsetenv: need at least one argument.\n", 1);
        return;
    } else {
        check_fun4(p, env);
        return;
    }
}

void check_fun4(s_minishell *p, char **env)
{
    if (p->arg_tab[0][0] == '.' && p->arg_tab[0][1] == '/') {
        if (my_strlen(p->arg_tab[0]) > 2)
            exec_prog(p, env, 1);
	return;
    } else if (sys_cmd(p, env) == 0)
        return;
    else {
        cmd_notfd(p);
        return;
    }
}
