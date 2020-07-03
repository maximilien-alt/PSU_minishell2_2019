/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_occ.c
*/

int my_occ1(char c, char *str)
{
    int cursor = 0;
    int res = 0;

    while (str[cursor]) {
        if (str[cursor] == c) {
            res += 1;
        }
        cursor += 1;
    }
    if (res >= 2) {
        return (0);
    }
    return (1);
}

int my_occ(char *str)
{
    int cursor = 0;

    while (str[cursor]) {
        if (my_occ1(str[cursor], str) == 1) {
            cursor += 1;
        }
        else {
            return (0);
        }
    }
    return (1);
}