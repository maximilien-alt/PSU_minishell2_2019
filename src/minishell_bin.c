/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell_bin.c
*/

#include "../include/my.h"

char *easy_ret(char *str)
{
    if (str)
        my_printf("%s: Command not found.\n", str);
    return (NULL);
}

int my_ret(int number, char **tab)
{
    if (number == 84) {
        if (tab[1])
            my_printf("%s: %s.\n", tab[1], strerror(errno));
    }
    my_free_tab(tab);
    return (number);
}

int my_tty(void)
{
    if (isatty(0))
        my_printf("exit\n");
    return (0);
}

char *my_special_str_dup(char *env, char *buffer)
{
    int malloc_size = 0;
    char *path = NULL;

    if (!env || env[0] == '\0')
        return (NULL);
    for (malloc_size = 0; env[malloc_size] && env[malloc_size] != ':'; \
    malloc_size += 1);
    path = malloc(sizeof(char) * malloc_size + 1);
    for (int current = 0; env[current] && env[current] != ':'; current += 1)
        path[current] = env[current];
    path[malloc_size] = '\0';
    path = my_strcat(path, "/", 0);
    path = my_strcat(path, buffer, 0);
    return (path);
}

char *my_get_good_bin(char *env, char *buffer)
{
    char *result = NULL;
    char **tab = my_str_to_word_array(buffer, " \t\n");

    if (!buffer || !env)
        return (easy_ret(buffer));
    if (access(tab[0], X_OK) == 0) {
        return (tab[0]);
    }
    result = my_special_str_dup(env, tab[0]);
    if (result && access(result, X_OK) == 0)
        return (result);
    for (int current = 0; env[current]; current += 1) {
        if (env[current] == ':')
            result = my_special_str_dup(&env[current + 1], tab[0]);
        if (access(result, X_OK) == 0)
            return (result);
    }
    return (easy_ret(tab[0]));
}