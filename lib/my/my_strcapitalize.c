/*
** EPITECH PROJECT, 2019
** capitalize
** File description:
** capitalize
*/

char    *my_strcapitalize(char *str)
{
    int i = 0;

    if (str[i] >= 97 && str[i] <= 122) {
        str[i] = str[i] - 32;
    }
    i++;
    while (str[i] != '\0') {
        if (str[i] <= 90 && str[i] >= 65) {
            str[i] = str[i] + 32;
        }
        if (str[i] > 122 || str[i] < 97) {
            if (str[i+1] >= 97 && str[i+1] <= 122) {
                i++;
                str[i] = str[i] - 32;
            }
        }
        i++;
    }
    return (str);
}
