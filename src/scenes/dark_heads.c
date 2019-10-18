/*
** EPITECH PROJECT, 2018
** dark heads scene
** File description:
** Mai Ly Lehoux
*/

#include "../include/my.h"
#include "../include/error_msg.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

int my_put_dark_plasma(framebuffer_t *buffer, unsigned int x, unsigned int y)
{
    int courbs = 160.0 + (160.0 * (sin(x / 16.0)) / 2) \
    + 160.0 + (160.0 * (sin(y / 13.0)) /2) / 2;

    if (x > 799 || y > 599 || x < 1 || y < 1)
        return (EXIT_ERROR);
    buffer->pixels[4*(y*buffer->width+x)] = courbs;
    buffer->pixels[4*(y*buffer->width+x)+1] = courbs;
    buffer->pixels[4*(y*buffer->width+x)+2] = courbs;
    buffer->pixels[4*(y*buffer->width+x)+3] = courbs;
    return (EXIT_DRAW);
}

int scene3_is_display(framebuffer_t *buffer, int x0, int x1)
{
    coords_line_t* coords = give_coords_line(x0, x1);

    while (1) {
        my_put_dark_plasma(buffer, coords->y0, x1);
        my_put_dark_plasma(buffer, x0, coords->y1);
        my_put_dark_plasma(buffer, coords->dx, coords->dy);
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
