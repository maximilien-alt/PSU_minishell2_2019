/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell_owns_functions.c
*/

#include "../include/my.h"

char **my_list_to_tab(node_t *env_list)
{
    char **tab = NULL;
    char *str = NULL;

    if (!env_list)
        return (NULL);
    for (; env_list; env_list = env_list->next) {
        str = my_strcat(str, env_list->name, 0);
        str = my_strcat(str, "=", 0);
        str = my_strcat(str, env_list->value, 0);
        str = my_strcat(str, "\n", 0);
    }
    tab = my_str_to_word_array(str, "\n");
    free (str);
    return (tab);
}

char **quick_mod(char **tab, int check, char *name, char *value)
{
    tab[check] = NULL;
    tab[check] = my_strcat(tab[check], name, 0);
    tab[check] = my_char_strcat(tab[check], 61, 0);
    if (value)
        tab[check] = my_strcat(tab[check], value, 0);
    return (tab);
}

int my_own_env(node_t *env_list, char *buffer)
{
    for (; env_list; env_list = env_list->next)
        my_printf("%s=%s\n", env_list->name, env_list->value);
    if (!buffer)
        return (0);
    return (0);
}

int my_own_exit(node_t *env_list, char *buffer)
{
    char **tab = my_str_to_word_array(buffer, " \t\n");
    int ret = 0;

    (void)env_list;
    if (!tab[1]) {
        free (tab[0]);
        exit (0);
    }
    ret = my_getnbr(tab[1]);
    for (int i = 0; tab[i]; i += 1)
        free (tab[i]);
    free (tab);
    exit (ret);
}