/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** minishell_two_loop.c
*/

#include "../include/my.h"

tree_t *get_new(char *command)
{
    tree_t *my_tree = malloc(sizeof(tree_t));

    my_tree->command = my_strdup(command);
    my_tree->pipefds[0] = 0;
    my_tree->pipefds[1] = 1;
    my_tree->left = NULL;
    my_tree->right = NULL;
    return (my_tree);
}

tree_t *insert(tree_t *my_tree, char *command, int separator)
{
    if (!my_tree) {
        my_tree = get_new(command);
    }
    else if (!separator) {
        my_tree->left = insert(my_tree->left, command, separator);
    } else {
        my_tree->right = insert(my_tree->right, command, separator);
    }
    return (my_tree);
}

tree_t *my_binary_tree(buffer_t *buff, tree_t *my_tree)
{
    char **tab = NULL;
    int pos = my_change_buffer(buff);

    if (pos == 1)
        my_tree = insert(my_tree, ";", 0);
    if (pos == 2)
        my_tree = insert(my_tree, ">", 0);
    if (pos == 3)
        my_tree = insert(my_tree, ">>", 0);
    if (pos == 4)
        my_tree = insert(my_tree, "<", 0);
    if (pos == 5)
        my_tree = insert(my_tree, "|", 0);
    tab = my_str_to_word_array(buff->buffer, "\n\r");
    for (int cursor = 0; tab[cursor]; cursor += 1) {
        buff->buffer = tab[cursor];
        my_tree = obtain_good_tree(buff, cursor, my_tree);
        free (tab[cursor]);
    }
    free (tab);
    return (my_tree);
}