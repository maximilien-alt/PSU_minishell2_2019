/*
** EPITECH PROJECT, 2019
** showstr
** File description:
** showstr
*/

void my_putchar(char c);

void my_hex_number(char c)
{
    if (c < 16) {
        my_putchar('0');
        if (c < 10) {
            my_putchar(c + 48);
            return;
        }
        my_putchar(c + 87);
        return;
    }
    if (c < 32) {
        my_putchar('1');
        if (c < 26) {
            my_putchar(c + 32);
            return;
        }
        my_putchar(c + 71);
        return;
    }
    my_putchar('7');
    my_putchar('f');
}

int    my_showstr(char const *str)
{
    for (int letter = 0; str[letter]; letter += 1){
        if (str[letter] >= 32 && str[letter] != 127) {
            my_putchar(str[letter]);
        } else {
            my_hex_number(str[letter]);
        }
    }
    return (0);
}
