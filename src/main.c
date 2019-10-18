/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Mai Ly Lehoux
*/

#include "../include/my.h"
#include "../include/error_msg.h"
#include <SFML/Graphics.h>

int main(int ac, char **av)
{
    if (error_gestion(ac, av) == EXIT_ERROR)
        return (EXIT_ERROR);
    if (error_gestion(ac, av) == EXIT_USAGE)
        return (EXIT_USAGE);
    if (animation_id(av[1]) == EXIT_SUCCESS)
        return (EXIT_SUCCESS);
    return (EXIT_ERROR);
}

int animation_id(char *animation_id)
{
    if (animation_id[0] == '1') {
        scene_is_display(1);
        return (EXIT_SUCCESS);
    }
    if (animation_id[0] == '2') {
        scene_is_display(2);
        return (EXIT_SUCCESS);
    }
    if (animation_id[0] == '3') {
        scene_is_display(3);
        return (EXIT_SUCCESS);
    }
    if (animation_id[0] == '4') {
        scene_is_display(4);
        return (EXIT_SUCCESS);
    }
    return (EXIT_ERROR);
}
