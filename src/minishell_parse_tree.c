/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** minishell_parse_tree.c
*/

#include "../include/my.h"

void change_fd(int fd, tree_t *tree, int index, node_t *env_list)
{
    if (!index) {
        tree->left->pipefds[0] = fd;
        tree->left->pipefds[1] = tree->pipefds[1];
    } else {
        tree->left->pipefds[0] = tree->pipefds[0];
        tree->left->pipefds[1] = fd;
    }
    parse_tree(tree->left, env_list);
    close(fd);
}

void exec_redirect_left(tree_t *tree, node_t *env_list)
{
    char **tab = NULL;
    int fd = 0;

    if (tree && (!tree->left || !tree->right)) {
        my_printf("Missing name for redirect.\n");
        return;
    }
    tab = my_str_to_word_array(tree->right->command, " ");
    fd = open(tab[0], O_RDONLY);
    if (fd >= 0) {
        change_fd(fd, tree, 0, env_list);
    } else
        my_printf("%s: No such file or directory.\n", tab[0]);
}

void exec_double(tree_t *tree, node_t *env_list)
{
    parse_tree(tree->left, env_list);
    parse_tree(tree->right, env_list);
}

void exec_double_redirect_right(tree_t *tree, node_t *env_list)
{
    char **tab = NULL;
    int fd = 0;

    if (tree && (!tree->left || !tree->right)) {
        my_printf("Missing name for redirect.\n");
        return;
    }
    tab = my_str_to_word_array(tree->right->command, " ");
    fd = open(tab[0], O_WRONLY | O_CREAT | O_APPEND, 0664);
    change_fd(fd, tree, 1, env_list);
}

void exec_redirect_right(tree_t *tree, node_t *env_list)
{
    char **tab = NULL;
    int fd = 0;

    if (tree && (!tree->left || !tree->right)) {
        my_printf("Missing name for redirect.\n");
        return;
    }
    tab = my_str_to_word_array(tree->right->command, " ");
    fd = open(tab[0], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    change_fd(fd, tree, 1, env_list);
}