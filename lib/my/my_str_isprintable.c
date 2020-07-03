/*
** EPITECH PROJECT, 2019
** is_printable
** File description:
** is_printable
*/

int is_char_printable(char c)
{
    return (c >= ' ' && c != 127);
}

int    my_str_isprintable(char const *str)
{
    for (int current = 0; str[current]; current += 1) {
        if (!is_char_printable(str[current]))
            return (0);
    }
    return (1);
}