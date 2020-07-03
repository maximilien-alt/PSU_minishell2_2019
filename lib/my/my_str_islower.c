/*
** EPITECH PROJECT, 2019
** is_lower
** File description:
** is_lower
*/

int is_char_lower(char c)
{
    return (c >= 'a' && c <= 'z');
}

int    my_str_islower(char const *str)
{
    for (int current = 0; str[current]; current += 1) {
        if (!is_char_lower(str[current]))
            return (0);
    }
    return (1);
}
