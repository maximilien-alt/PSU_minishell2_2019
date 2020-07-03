/*
** EPITECH PROJECT, 2019
** task06
** File description:
** my_strcmp
*/

int my_strlen(char *str);

int my_strncmp(char *s1, char *s2, int n)
{
    if (my_strlen(s1) < n || my_strlen(s2) < n)
        return (1);
    for (int current = 0; current < n; current += 1) {
        if (s1[current] != s2[current])
            return (1);
    }
    return (0);
}
