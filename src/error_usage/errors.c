/*
** EPITECH PROJECT, 2018
** errors
** File description:
** Mai Ly Lehoux
*/

#include "../include/my.h"
#include "../include/error_msg.h"
#include <SFML/Graphics.h>

int error_gestion(int ac, char **av)
{
    int flag = 0;

    if (ac == 1) {
        one_argument();
        return (EXIT_ERROR);
    }
    if (ac > 2)
        return (EXIT_ERROR);
    if (av[1][0] == '-') {
        flag = print_usage(av[1]);
        if (flag == EXIT_USAGE)
            return (EXIT_USAGE);
        return (EXIT_ERROR);
    }
    return (EXIT_DRAW);
 }

int print_usage(char *options)
{
    if (options[1] == 'h') {
        h_flag();
        return (EXIT_USAGE);
    }
    if (options[1] == 'd') {
        d_flag();
        return (EXIT_USAGE);
    }
    return (EXIT_ERROR);
}
