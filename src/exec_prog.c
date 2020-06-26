/*
** EPITECH PROJECT, 2019
** exec_prog.c
** File description:
** execute a program
*/

#include "my.h"

void exec_str(s_minishell *p, int stat)
{
    int u = 2;
    int i = 0;

    if (stat == 1) {
        while (p->s[u] != '\0') {
            p->exc[i] = p->s[u];
            i++;
            u++;
        }
    } else
        return;
}

int exec_prog(s_minishell *p, char **env, int i)
{
    pid_t pid;
    int stat;

    exec_str(p, i);
    if ((pid = fork()) == -1)
        return (1);
    else if (pid == 0) {
        if ((execve(p->exc, p->arg_tab, env)) == -1) {
            my_putstr("bashish: ./", 2);
            perror(p->exc);
            return (1);
        }
    } else
        waitpid(pid, &stat, 0);
    if (stat == 131 || stat == 139) {
        my_putstr("segmentation fault (core dumped)  ", 2);
        my_putstr(p->arg_tab[0], 2);
        my_putchar('\n');
    }
    return (0);
}
