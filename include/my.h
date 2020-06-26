/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** h file for include all project
*/

#ifndef MY_H_
#define MY_H_

#define BUF_SIZE 1
#define PATH_SIZ 501

#define WHITE "\033[37m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define GREY "\033[30m"
#define BLINK "\033[32;5m"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

typedef struct s_minishell s_minishell;
struct s_minishell {
    char *usr_name;
    int user_once;
    char *s;
    char **arg_tab;
    int arch;
    char *path;
    char **path_tab;
    char *pat;
    int a_stat;
    int path_siz;
    char *c_dir;
    char *exc;
    char *cd_home;
    int *cmds;
    int na;
};

/*basic_fun.c*/
void my_putchar(char);
int my_strlen(char *);
void my_putstr(char *, int);
void my_putnbr(int);
int my_getnbr(char *);

/*basic_fun2.c*/
int my_strcmp(char *, char *);
int my_lencmp(char *, char *);

/*my_gnl.c*/
char *get_alloc(char *);
char *get_next_line(const int);

/*main.c*/
int check_s(s_minishell *, char **);
int check_str(s_minishell *, char **);
int minishell(s_minishell *, char **);
int main(int, char **, char **);

/*prompt_color.c*/
void disp_prompt(s_minishell *);

/*user_name.c*/
void usr_name(s_minishell *, char **);

/*malloc_free.c*/
void malloc_A(s_minishell *);
void free_A(s_minishell *);
void free_B(s_minishell *);
void final_free(s_minishell *, int);
void malloc_pathtab(s_minishell *);

/*mult_usage.c*/
void check_mult(s_minishell *);

/*clean_str.c*/
int count_tab(s_minishell *);
char *clean_mtab(s_minishell *);
int count_mspace(s_minishell *);
char *clean_mspace(s_minishell *);
char *clean_fspace(s_minishell *);

/*str_to_word_tab.c*/
int len_size(s_minishell *);
void malloc_tab(s_minishell *, int);
void str_tab(s_minishell *, int, int, int);

/*check_fun.c*/
void check_fun(s_minishell *, char **);
void check_fun2(s_minishell *, char **);
void check_fun3(s_minishell *, char **);
void check_fun4(s_minishell *, char **);

/*exec_prog.c*/
void exec_str(s_minishell *, int);
int exec_prog(s_minishell *, char **, int);

/*sys_cmd.c*/
int sys_cmd(s_minishell *, char **);

/*sys_id.c*/
int sys_id(s_minishell *, char **);

/*my_cd.c*/
int my_cd(s_minishell *);

/*path_cmd.c*/
int path_cmd(s_minishell *, int, int, int);
void cmd_notfd(s_minishell *);

/*env_fun.c*/
void my_getenv(char **);
void my_setenv(s_minishell *, char **);
void my_unsetenv(s_minishell *, char **);
int getenv_size(char **);

/*path_dir.c*/
void access_pathtab(s_minishell *, char **);
int path_check(char **, int);
int get_path(s_minishell *);
void get_home(s_minishell *);
void getc_dir(s_minishell *);

#endif /*MY_H_*/
