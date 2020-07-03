/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell_unsetenv.c
*/

#include "../include/my.h"

int my_find_name(char *name, node_t *env_list)
{
    if (env_list && !my_strcmp(env_list->name, name))
        *env_list = *env_list->next;
    for (; env_list->next; env_list = env_list->next) {
        if (!my_strcmp(env_list->next->name, name)) {
            env_list->next = env_list->next->next;
            break;
        }
    }
    return (0);
}

int is_alp(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int is_num(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || \
    (c <= '0' && c >= '9') || c == '_');
}

int my_own_unsetenv(node_t *env_list, char *buffer)
{
    char **tab = my_str_to_word_array(buffer, " \t\n");
    int len_tab = 0;

    if (!env_list)
        return (0);
    for (; tab[len_tab]; len_tab += 1);
    if (len_tab == 1) {
        my_printf("unsetenv: Too few arguments.\n");
        return (0);
    }
    for (int current = 0; tab[current]; current += 1)
        my_find_name(tab[current], env_list);
    for (int cursor = 0; tab[cursor]; cursor += 1)
        free (tab[cursor]);
    free (tab);
    return (0);
}