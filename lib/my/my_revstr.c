/*
** EPITECH PROJECT, 2019
** MY_EVIL_STR
** File description:
** reverse string
*/

int    my_strlen4(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

void    my_swap3(char *a, char *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

char    *my_revstr(char *str)
{
    int r = my_strlen4(str)-1;
    int u = my_strlen4(str);
    int d = 0;

    while (d < (u/2)) {
        my_swap3(&str[r], &str[d]);
        r--;
        d++;
    }
    return (str);
}