/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell_nodes.c
*/

#include "../include/my.h"

int check_same_name(char **tab, char *name)
{
    name = my_char_strcat(name, 61, 1);
    for (int current = 0; tab[current]; current += 1) {
        if (my_strncmp(tab[current], name, my_strlen(name)) == 0)
            return (current);
    }
    return (-1);
}

char     *my_char_strcat(char *src, char c, int check)
{
    char *str_cat = NULL;
    int cat = 0;

    if (!src || src[0] == '\0') {
        str_cat = malloc(sizeof(char) * 2);
        if (!str_cat)
            return (NULL);
    } else {
        str_cat = malloc(sizeof(char) * my_strlen(src) + 2);
        if (!str_cat)
            return (NULL);
    }
    for (cat = 0; src && src[cat]; cat += 1)
        str_cat[cat] = src[cat];
    str_cat[cat] = c;
    str_cat[cat + 1] = '\0';
    if (check == 0 && src)
        free (src);
    return (str_cat);
}

int is_alpha(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || \
    (c >= '0' && c <= '9'));
}

int return_and_free(char **tab, int number)
{
    my_free_tab(tab);
    return (number);
}

char *get_good_env(node_t *env_list)
{
    char *str = NULL;

    for (; env_list; env_list = env_list->next) {
        if (!my_strcmp(env_list->name, "PATH")) {
            str = my_strdup(env_list->value);
            break;
        }
    }
    return (str);
}