/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_bistro_error.c
*/

int my_strlen(char *str);

int my_getnbr(char *str);

int my_occ(char *str);

int my_miss_matching_par(char *buff)
{
    int open = 0;
    int close = 0;
    int cursor = 0;

    while (buff[cursor]) {
        if (buff[cursor] == '(')
            open += 1;
        if (buff[cursor] == ')')
            close += 1;
        cursor += 1;
    }
    if (open != close)
        return (0);
    return (1);
}

int my_bistro_error(int ac, char **av, char *buff)
{
    ac += 1;

    if (my_getnbr(av[3]) == 0)
        return (0);
    if (my_strlen(av[2]) != 7)
        return (0);
    if (buff[0] == '\0')
        return (0);
    if (my_miss_matching_par(buff) == 0)
        return (0);
    if (my_occ(av[1]) == 0)
        return (0);
    if (my_occ(av[2]) == 0)
        return (0);
    return (1);
}
