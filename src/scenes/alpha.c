/*
** EPITECH PROJECT, 2018
** Scene 1
** File description:
** Mai Ly Lehoux
*/

#include "../include/my.h"
#include "../include/error_msg.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>

int scene1_is_display(framebuffer_t *buffer, sfColor color, int x0, int x1)
{
    coords_line_t* coords = give_coords_line(x0, x1);

    while (1) {
        my_put_pixel(buffer, x0, coords->y0, color);
        if (x0 == x1 && coords->y0 == coords->y1)
            return (EXIT_DRAW);
        coords->e2 = coords->err;
        if (coords->e2 > (coords->dx) * -1) {
            coords->err -= coords->dy;
            x0 += coords->sx;
        }
        if (coords->e2 < coords->dy) {
            coords->err += coords->dx;
            coords->y0 += coords->sy;
        }
    }
}
