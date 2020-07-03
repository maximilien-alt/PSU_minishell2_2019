/*
** EPITECH PROJECT, 2019
** is_alpha
** File description:
** is_alpha
*/

int is_char_alpha(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int    my_str_isalpha(char const *str)
{
    for (int current = 0; str[current]; current += 1) {
        if (!is_char_alpha(str[current]))
            return (0);
    }
    return (1);
}
