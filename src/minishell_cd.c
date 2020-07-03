/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell_cd.c
*/

#include "../include/my.h"

int my_tab_len(char **comm)
{
    int size = 0;

    for (size = 0; comm[size]; size += 1);
    return (size);
}

int my_return_norm(char **comm, int size)
{
    if (size == 2) {
        if (chdir(comm[1]) == -1)
            return (my_ret(84, comm));
        return (my_ret(0, comm));
    }
    return (my_ret(84, comm));
}

int my_special_cd(char *save, char **comm, node_t *env_list)
{
    if (!save || save[0] == 0) {
        if (chdir("/home") == -1)
            return (my_ret(84, comm));
        my_own_setenv(env_list, "setenv PWD /home");
        return (my_ret(0, comm));
    }
    chdir(save);
    my_own_setenv(env_list, my_strcat("setenv PWD ", save, 1));
    return (my_ret(0, comm));
}

int my_own_cd(node_t *env_list, char *buffer)
{
    char **comm = my_str_to_word_array(buffer, " \t\n");
    int size = my_tab_len(comm);
    char *turn = NULL;
    static char *save = NULL;

    if (!turn)
        turn = malloc(sizeof(char) * 4096);
    getcwd(turn, 4096);
    if (size == 2 && comm[1][0] == '-' && comm[1][1] == '\0') {
        my_special_cd(save, comm, env_list);
        save = my_strdup(turn);
        return (0);
    }
    if (size == 1) {
        save = my_strdup(turn);
        chdir("/home");
        my_own_setenv(env_list, "setenv PWD /home");
        return (my_ret(0, comm));
    }
    (my_return_norm(comm, size) == 0) ? save = my_strdup(turn) : 0;
    return (0);
}