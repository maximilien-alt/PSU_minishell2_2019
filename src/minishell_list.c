/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell_list.c
*/

#include "../include/my.h"

int easy_len(char *str)
{
    int len = 0;

    for (; str[len] && str[len] != 61; len += 1);
    return (len);
}

char *my_special_dup(char *str)
{
    char *cpy = malloc(sizeof(char) * easy_len(str) + 1);
    int current = 0;

    for (; str[current] && str[current] != 61; current += 1)
        cpy[current] = str[current];
    cpy[current] = 0;
    return (cpy);
}

node_t *get_new_node(char *env)
{
    node_t *node = malloc(sizeof(node_t));
    int len = easy_len(env);

    node->name = my_special_dup(env);
    node->value = my_special_dup(&env[len + 1]);
    node->next = NULL;
    return (node);
}

node_t *insert_node(node_t *nodes, char *env)
{
    if (!nodes) {
        nodes = get_new_node(env);
        return (nodes);
    }
    nodes->next = insert_node(nodes->next, env);
    return (nodes);
}

node_t *my_env_to_list(node_t *nodes, char **env)
{
    for (int cursor = 0; env[cursor]; cursor += 1)
        nodes = insert_node(nodes, env[cursor]);
    return (nodes);
}