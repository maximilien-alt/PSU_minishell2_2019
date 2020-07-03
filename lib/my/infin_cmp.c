/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** infin_cmp.c
*/

int my_strlen(char const *str);

int    my_str_compare_neg(char *str, char *str2)
{
    int a = 1;

    while (str[a]) {
        if ((str[a] - str2[a] + '0') < '0')
            return (1);
        if ((str[a] - str2[a] + '0') > '0')
            return (0);
        a += 1;
    }
    return (1);
}

int    same_length_cmp(char *str, char *str2)
{
    int a = 0;
    int b = 1;

    if (str[a] == '-') {
        return (my_str_compare_neg(str, str2));
    }
    while (str[a]) {
        if ((str[a] - str2[a]) < 0)
            return (0);
        if ((str[a] - str2[a]) > 0)
            return (1);
        a += 1;
    }
    return (1);
}

int    my_infin_cmp(char *str, char *str2)
{
    int str_len = my_strlen(str);
    int str2_len = my_strlen(str2);

    if (str_len == str2_len)
        return (same_length_cmp(str, str2));
    if (str[0] == '-' && str2[0] == '-') {
        if (str_len < str2_len)
            return (1);
        return (0);
    }
    if (str[0] != '-' && str2[0] != '-') {
        if (str_len > str2_len)
            return (1);
        return (0);
    }
    if (str[0] == '-' && str2[0] != '-')
        return (0);
    if (str2[0] == '-' && str[0] != '-')
        return (1);
}