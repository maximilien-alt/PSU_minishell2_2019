/*
** EPITECH PROJECT, 2019
** task06
** File description:
** my_strcmp
*/

char **my_str_to_word_array(char *str, char *operator);

int my_strlen(char *str);

int    my_strcmp(char *s1, char *s2)
{
    int cursor = 0;
    char **tab = my_str_to_word_array(s2, " \t\n");

    if (!s1 || !s2)
        return (1);
    if (my_strlen(s1) != my_strlen(tab[0]))
        return (1);
    for (cursor = 0; s1[cursor] && tab[0][cursor]; cursor += 1) {
        if (s1[cursor] != tab[0][cursor])
            return (1);
    }
    return (0);
}