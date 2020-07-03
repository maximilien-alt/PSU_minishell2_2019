/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** my_str_isnum
*/

int is_char_num(char c)
{
    return (c >= '0' && c <= '9');
}

int    my_str_isnum(char const *str)
{
    for (int current = 0; str[current]; current += 1) {
        if (!is_char_num(str[current]))
            return (0);
    }
    return (1);
}
