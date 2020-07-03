/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strncat
*/
char    *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int a = 0;

    if (nb <= 0) {
        return (0);
    }
    while (dest[i] != '\0') {
        i++;
    }
    while (nb > 0 && src[a] != '\0') {
            dest[i] = src[a];
            a++;
            i++;
            nb--;
    }
    dest[i] = '\0';
    return (dest);
}
