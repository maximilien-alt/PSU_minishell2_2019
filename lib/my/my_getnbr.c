/*
** EPITECH PROJECT, 2019
** getnbr
** File description:
** getnbr
*/

int my_getnbr(char const *str)
{
    int nb_moins = 0;
    int cursor = 0;
    int result = 0;

    for (cursor = 0; str[cursor] == '-'; cursor += 1)
        nb_moins += 1;
    for (; str[cursor] && (str[cursor] >= '0' && str[cursor] <= '9'); \
    cursor += 1) {
        result *= 10;
        result += (str[cursor] - '0');
    }
    if (nb_moins % 2 == 1)
        result *= -1;
    return (result);
}