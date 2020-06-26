/*
** EPITECH PROJECT, 2019
** sys_cmd.c
** File description:
** execve system command ls
*/

#include "my.h"

int sys_cmd(s_minishell *p, char **env)
{
    pid_t pid;
    int stat;
    int i = 0;

    while (path_cmd(p, i, 0, 0) != 1) {
        i++;
        if (p->path_tab[i] == NULL)
            return (1);
    }
    if ((pid = fork()) == -1)
        return (1);
    else if (pid == 0)
        execve(p->pat, p->arg_tab, env);
    waitpid(pid, &stat, 0);
    return (0);
}
