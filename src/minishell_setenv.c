/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell_setenv.c
*/

#include "../include/my.h"

node_t *new_node(char **tab)
{
    node_t *new = NULL;

    new = malloc(sizeof(node_t));
    new->name = my_strdup(tab[1]);
    if (tab[2])
        new->value = my_strdup(tab[2]);
    else
        new->value = NULL;
    new->next = NULL;
    return (new);
}

int norm_print(void)
{
    my_printf("setenv: Variable name must contain alphanumeric characters.\n");
    return (0);
}

void special_insert(node_t *env_list, char **tab)
{
    node_t *new = NULL;
    node_t *temp = env_list;

    for (; env_list; env_list = env_list->next) {
        if (!my_strcmp(env_list->name, tab[1]))
            break;
    }
    if (env_list) {
        if (tab[2])
            env_list->value = my_strdup(tab[2]);
        else
            env_list->value[0] = '\0';
    } else
        new = new_node(tab);
    for (;temp && temp->next; temp = temp->next);
    if (!temp)
        temp = new;
    else
        temp->next = new;
}

int easy_setenv(node_t *env_list, char **tab)
{
    for (int current = 0; tab[1][current]; current += 1) {
        if (!is_num(tab[1][current]))
            return (norm_print());
    }
    special_insert(env_list, tab);
    return (0);
}

int my_own_setenv(node_t *env_list, char *buffer)
{
    char **tab = my_str_to_word_array(buffer, " \t\n");
    int len_tab = 0;

    for (len_tab = 0; tab[len_tab]; len_tab += 1);
    if (len_tab == 1)
        return (my_own_env(env_list, buffer));
    if (len_tab >= 4) {
        my_printf("setenv: Too many arguments\n");
        return (0);
    }
    if (is_alp(tab[1][0]) || tab[1][0] == '_')
        return (easy_setenv(env_list, tab));
    my_printf("setenv: Variable name must begin with a letter\n");
    for (int cursor = 0; tab[cursor]; cursor += 1)
        free (tab[cursor]);
    free (tab);
    return (0);
}