/*
** EPITECH PROJECT, 2019
** prompt_color.c
** File description:
** set the right color for the prompt display
*/

#include "my.h"

void disp_prompt(s_minishell *p)
{
    my_putstr("→  <B", 1);
    my_putstr(GREEN, 1);
    my_putstr("A$HI$H", 1);
    my_putstr(RED, 1);
    my_putchar('#');
    my_putstr(GREY, 1);
    my_putstr("#~ ", 1);
    my_putstr(WHITE, 1);
    my_putchar('{');
    my_putstr(p->usr_name, 1);
    my_putchar('}');
    my_putstr(GREEN, 1);
    my_putstr(". ", 1);
    my_putstr(WHITE, 1);
}
