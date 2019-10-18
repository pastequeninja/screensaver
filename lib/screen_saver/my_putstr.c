/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** Display one-by-one the charaters of a string
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
