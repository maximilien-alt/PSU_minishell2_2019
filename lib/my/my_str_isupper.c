/*
** EPITECH PROJECT, 2019
** is_upper
** File description:
** is_upper
*/

int is_char_upper(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int     my_str_isupper(char const *str)
{
    for (int current = 0; str[current]; current += 1) {
        if (!is_char_upper(str[current]))
            return (0);
    }
    return (1);
}
