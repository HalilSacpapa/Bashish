/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main loops
*/

#include "my.h"

int check_s(s_minishell *p, char **env)
{
    if (p->a_stat == 0) {
        access_pathtab(p, env);
        p->a_stat = 1;
    }
    if (p->s[0] == ' ') {
        if (my_strlen(p->s) == 1)
            return (1);
        else
            p->s = clean_fspace(p);
    }
    return (0);
}

int check_str(s_minishell *p, char **env)
{
    if (my_strlen(p->s) > 0) {
        p->s = clean_mtab(p);
        p->s = clean_mspace(p);
        if (check_s(p, env) == 1) {
            free_B(p);
            p->arch = 1;
            return (1);
        }
        str_tab(p, 0, 0, 0);
        check_mult(p);
        return (0);
    } else {
        free_B(p);
        p->arch = 1;
        return (1);
    }
}

int minishell(s_minishell *p, char **env)
{
    malloc_A(p);
    usr_name(p, env);
    disp_prompt(p);
    for (; (p->s = get_next_line(0)) != NULL ;) {
        check_str(p, env);
        if (p->arch == 1)
            return (1);
        check_fun(p, env);
        free_A(p);
        malloc_A(p);
        disp_prompt(p);
    }
    if (p->s == NULL) {
        my_putchar('\n');
        final_free(p, 0);
        exit (1);
    }
    free_A(p);
    return (0);
}

int main(int ac, char **av, char **env)
{
    s_minishell p;

    p.arch = 0;
    p.a_stat = 0;
    p.user_once = 0;
    my_putstr(WHITE, 1);
    while (ac == 1 && av[0][0] == '.') {
        if (p.arch == 1) {
            p.arch = 0;
            minishell(&p, env);
        } else
            minishell(&p, env);
    }
    return (0);
}
