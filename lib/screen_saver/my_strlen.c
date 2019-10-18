/*
** EPITECH PROJECT, 2018
** len
** File description:
** Mai Ly Lehoux
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    return (i);
}
