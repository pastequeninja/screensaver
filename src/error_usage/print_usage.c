/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** Mai Ly lehoux
*/

#include "../include/my.h"
#include "../include/error_msg.h"
#include <SFML/Graphics.h>

void h_flag(void)
{
    my_putstr("animation rendering in a CSFML window.\n\n");
    my_putstr("USAGE\n");
    my_putstr("  ./my_screensaver[OPTIONS] animation_id\n");
    my_putstr("  animation_id    ID of the animation to process");
    my_putstr(" (between 1 and 4).\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("-d      print the description of all the animations");
    my_putstr("and quit.\n-h     print the usage and quit.");
    my_putstr("USER INTERACTIONS\n  LEFT_ARROW   switch to the");
    my_putstr(" previous animation.\n  RIGTH_ARROW   switch to the next");
    my_putstr(" animation.");
}

void one_argument(void)
{
    my_putstr("./my_screensaver: bad arguments: 0 given but 1");
    my_putstr(" is required\n");
    my_putstr("retry with -h");
}

void d_flag(void)
{
    my_putstr("1: Disco lines\n");
    my_putstr("2: Lines intception\n");
    my_putstr("3: Pink lines intceptions\n");
    my_putstr("4: Strange lines");
}
