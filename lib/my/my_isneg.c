/*
** EPITECH PROJECT, 2019
** MY_ISNEG.c
** File description:
** Display, either N if the passed as parameter is negative, else P
*/

void my_putchar(char c);

int    my_isneg(int n)
{
    if (n < 0){
        my_putchar('N');
    } else my_putchar('P');
    return (0);
}
