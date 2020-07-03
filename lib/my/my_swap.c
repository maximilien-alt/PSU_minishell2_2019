/*
** EPITECH PROJECT, 2019
** MY_SWAP
** File description:
** Swap the content of two integers
*/

void    my_swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}