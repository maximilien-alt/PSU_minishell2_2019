/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** minishell_free_list.c
*/

#include "../include/my.h"

int simple_ending(char *str, char **exec_tab, char **tab, pid_t pid)
{
    free (str);
    my_free_tab(tab);
    my_disp_error(pid);
    my_free_tab(exec_tab);
    return (0);
}

int minishell_return(char **tab, char **exec_tab, char *str, pid_t pid)
{
    free (str);
    my_free_tab(tab);
    my_free_tab(exec_tab);
    return (my_disp_error(pid));
}

int free_list(node_t *env_list)
{
    for (node_t *temp = NULL; env_list; free (temp)) {
        temp = env_list;
        env_list = env_list->next;
        free (temp->name);
        free (temp->value);
    }
    return (0);
}

void free_tree(tree_t *my_tree)
{
    if (my_tree) {
        free_tree(my_tree->right);
        free_tree(my_tree->left);
        free (my_tree->command);
        free (my_tree);
    }
    return;
}