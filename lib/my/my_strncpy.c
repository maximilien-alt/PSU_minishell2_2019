/*
** EPITECH PROJECT, 2019
** task02
** File description:
** task02
*/

char    *my_strncpy(char *dest, char const *src, int nb)
{
    for (int letter = 0; letter != nb; letter += 1) {
        dest[letter] = src[letter];
    }
    return (dest);
}
