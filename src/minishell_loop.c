/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell_loop.c
*/

#include "../include/my.h"

static my_binaries_t tab[5] =
{
    {"cd", my_own_cd},
    {"setenv", my_own_setenv},
    {"unsetenv", my_own_unsetenv},
    {"env", my_own_env},
    {"exit", my_own_exit}
};

int lasts_checks(buffer_t *buff, int ret)
{
    int position = 0;
    int temp = 0;
    char save = 0;

    for (position = 0; buff->buffer[position]; position += 1) {
        if (check_for_redirect(buff->buffer[position]))
            temp = position;
        if (buff->buffer[position] == '>' && \
        (position > 0 && buff->buffer[position - 1] == '>')) {
            temp = position;
            ret = 3;
        }
    }
    if (temp) {
        save = buff->buffer[temp];
        buff->buffer[temp] = '\r';
        if (ret == 3)
            buff->buffer[temp - 1] = '\r';
    }
    return ((save == '|') ? 5 : (save == '<') ? 4 : \
    (ret == 3) ? 3 : (save == '>') ? 2 : 0);
}

void my_draw_prompt(void)
{
    static char *str = NULL;
    size_t size = 4096;

    if (!str)
        str = malloc(sizeof(char) * 4096);
    if (getcwd(str, size))
        my_printf("[%s]", str);
    my_printf("$ ");
}

int check_own(char *buffer, node_t *env_list, int fds[2])
{
    for (int i = 0; i < 5; i += 1) {
        if (my_strcmp(tab[i].command, buffer) == 0) {
            dup2(fds[0], 0);
            dup2(fds[1], 1);
            tab[i].ptr(env_list, buffer);
            return (1);
        }
    }
    return (0);
}

int minishell_loop(node_t *env_list)
{
    char *buffer = NULL;
    size_t size = 0;
    tree_t *my_tree = NULL;
    buffer_t buff;

    do {
        free_tree(my_tree);
        my_tree = NULL;
        if (isatty(0))
            my_draw_prompt();
        if (getline(&buffer, &size, stdin) == -1)
            return (my_tty());
        buff.buffer = buffer;
        my_tree = my_binary_tree(&buff, my_tree);
    } while (parse_tree(my_tree, env_list));
    return (free_list(env_list));
}