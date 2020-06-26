/*
** EPITECH PROJECT, 2019
** my_gnl.c
** File description:
** personnal get_next_line
*/

#include "my.h"

char *get_alloc(char *s)
{
    int i = 0;
    char *s1 = malloc(sizeof(char) * 101);

    while (s[i]) {
        s1[i] = s[i];
        i++;
    }
    s1[i + 1] = '\0';
    return (s1);
}

char *get_next_line(const int fd)
{
    int i = 0;
    char *s = malloc(sizeof(char) * 101);
    int cnt = 0;
    static char buf[BUF_SIZE];

    s[0] = '\0';
    while ((cnt = read(fd, buf, BUF_SIZE)) > 0 && buf[0] != '\n') {
        s = get_alloc(s);
        s[i] = buf[0];
        i++;
    }
    if (i == 0 && cnt == 0)
        return (NULL);
    else
        return (s);
}
